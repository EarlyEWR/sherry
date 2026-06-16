"""
Minimal CV pipeline node:
- subscribes to camera images
- runs optional YOLO inference (if ultralytics is available)
- publishes vision_msgs/Detection2DArray
"""

from typing import List, Tuple

import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from vision_msgs.msg import Detection2D, Detection2DArray
from cv_bridge import CvBridge

BBox = Tuple[float, float, float, float]  # cx, cy, w, h


class CvPipelineNode(Node):
    def __init__(self) -> None:
        super().__init__("cv_pipeline_node")

        self.declare_parameter("image_topic", "/camera/image_raw")
        self.declare_parameter("detection_topic", "/cv_pipeline/detections")
        self.declare_parameter("model_path", "models/weights/yolo_docking.pt")
        self.declare_parameter("confidence_threshold", 0.5)
        self.declare_parameter("image_encoding", "rgb8")
        self.declare_parameter("use_sim_time", True)

        self._image_topic = self.get_parameter("image_topic").value
        self._detection_topic = self.get_parameter("detection_topic").value
        self._model_path = self.get_parameter("model_path").value
        self._confidence = float(self.get_parameter("confidence_threshold").value)
        self._encoding = self.get_parameter("image_encoding").value

        self._bridge = CvBridge()
        self._detector = self._init_optional_yolo(self._model_path)

        self._sub = self.create_subscription(Image, self._image_topic, self._on_image, 10)
        self._pub = self.create_publisher(Detection2DArray, self._detection_topic, 10)

        self.get_logger().info(
            f"cv_pipeline_node ready | image_topic={self._image_topic} | detection_topic={self._detection_topic}"
        )

    def _init_optional_yolo(self, model_path: str):
        try:
            from ultralytics import YOLO
            model = YOLO(model_path)
            self.get_logger().info(f"Loaded YOLO model: {model_path}")
            return model
        except Exception as exc:
            self.get_logger().warn(
                f"YOLO unavailable or failed to load ({exc}). Using fallback heuristic detector."
            )
            return None

    def _on_image(self, msg: Image) -> None:
        try:
            img = self._bridge.imgmsg_to_cv2(msg, desired_encoding=self._encoding)
        except Exception as exc:
            self.get_logger().warn(f"Failed to decode image: {exc}")
            return

        boxes = self._run_detector(img)

        out = Detection2DArray()
        out.header = msg.header

        for cx, cy, w, h in boxes:
            det = Detection2D()
            det.header = msg.header
            self._set_bbox(det, cx, cy, w, h)
            out.detections.append(det)

        self._pub.publish(out)

    def _run_detector(self, img: np.ndarray) -> List[BBox]:
        if self._detector is not None:
            try:
                results = self._detector.predict(source=img, conf=self._confidence, verbose=False)
                return self._boxes_from_yolo(results)
            except Exception as exc:
                self.get_logger().warn(f"YOLO inference failed, fallback used: {exc}")

        return self._fallback_detector(img)

    def _boxes_from_yolo(self, results) -> List[BBox]:
        if not results:
            return []

        boxes_obj = getattr(results[0], "boxes", None)
        if boxes_obj is None or len(boxes_obj) == 0:
            return []

        xyxy = boxes_obj.xyxy.detach().cpu().numpy()
        out: List[BBox] = []
        for x1, y1, x2, y2 in xyxy:
            w = float(max(0.0, x2 - x1))
            h = float(max(0.0, y2 - y1))
            cx = float(x1 + w / 2.0)
            cy = float(y1 + h / 2.0)
            out.append((cx, cy, w, h))
        return out

    def _fallback_detector(self, img: np.ndarray) -> List[BBox]:
        gray = img.mean(axis=2) if img.ndim == 3 else img
        if float(gray.mean()) < 40.0:
            return []

        h, w = gray.shape[:2]
        return [(w * 0.5, h * 0.5, w * 0.25, h * 0.25)]

    def _set_bbox(self, det: Detection2D, cx: float, cy: float, w: float, h: float) -> None:
        bbox = det.bbox

        if hasattr(bbox, "center"):
            center = bbox.center
            if hasattr(center, "x"):
                center.x = float(cx)
            if hasattr(center, "y"):
                center.y = float(cy)
            if hasattr(center, "theta"):
                center.theta = 0.0
            if hasattr(center, "position"):
                if hasattr(center.position, "x"):
                    center.position.x = float(cx)
                if hasattr(center.position, "y"):
                    center.position.y = float(cy)

        if hasattr(bbox, "size_x"):
            bbox.size_x = float(w)
        if hasattr(bbox, "size_y"):
            bbox.size_y = float(h)


def main(args=None) -> None:
    rclpy.init(args=args)
    node = CvPipelineNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
