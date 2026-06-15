"""
Subscribes to the Basilisk ZMQ camera publisher and republishes frames as sensor_msgs/Image and sensor_msgs/CameraInfo on ROS2 topics

Wire format (matches camera_publisher.py):
    [0:4]   width       uint32  (little-endian)
    [4:8]   height      uint32
    [8:16]  timestamp   uint64  (nanoseconds, Bsilisk sim time)
    [16:]   pixels      uint8   (height, x width x 3, RGB8)
"""

import struct
import numpy as np
import zmq

import rclpy
from rclpy.node import Node
from builtin_interfaces.msg import Time
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge

_HEADER_SIZE = 16 # bytes 4 + 4 + 8

class BasiliskCameraNode(Node):
    def __init__(self):
        super().__init__('basilisk_camera_node')

        self.declare_parameter('zmq_host', '127.0.0.1')
        self.declare_parameter('zmq_port', 5570)
        self.declare_parameter('image_topic', '/camera/image_raw')
        self.declare_parameter('camera_info_topic', '/camera/camera_info')
        self.declare_parameter('image_encoding', 'rgb8')

        host = self.get_parameter('zmq_host').get_parameter_value().string_value
        port = self.get_parameter('zmq_port').get_parameter_value().integer_value
        image_topic = self.get_parameter('image_topic').get_parameter_value().string_value
        info_topic = self.get_parameter('camera_info_topic').get_parameter_value().string_value
        self._encoding = self.get_parameter('image_encoding').get_parameter_value().string_value

        self._bridge = CvBridge()

        self._zmq_context = zmq.Context()
        self._zmq_socket = self._zmq_context.socket(zmq.SUB)
        self._zmq_socket.connect(f"tcp://{host}:{port}")
        self._zmq_socket.setsockopt(zmq.SUBSCRIBE, b'')
        self._zmq_socket.setsockopt(zmq.RCVTIMEO, 0) # non-blocking

        self._image_pub = self.create_publisher(Image, image_topic, 10)
        self._info_pub = self.create_publisher(CameraInfo, info_topic, 10)

        #Poll at 30 Hz, adjust if Basilisk sim rate differs
        self._timer = self.create_timer(1.0 / 30.0, self._poll)

        self.get_logger().info(f"Listening for Basilisk frames on tcp://{host}:{port}")

    def _poll(self) -> None:
        try:
            raw = self._zmq_socket.recv()
        except zmq.Again:
            return  # no frame available this tick

        if len(raw) < _HEADER_SIZE:
            self.get_logger().warn('Received malformed frame (too short), dropping')
            return

        width, height, timestamp_ns = struct.unpack_from('<IIQ', raw, 0)
        expected_pixels = height * width * 3

        if len(raw) - _HEADER_SIZE != expected_pixels:
            self.get_logger().warn(
                f'Pixel data length mismatch: expected {expected_pixels}, '
                f'got {len(raw) - _HEADER_SIZE}, dropping'
            )
            return

        pixels = np.frombuffer(raw, dtype=np.uint8, offset=_HEADER_SIZE)
        image = pixels.reshape((height, width, 3))

        stamp = _ns_to_ros_time(timestamp_ns)
        frame_id = 'camera_optical'

        img_msg = self._bridge.cv2_to_imgmsg(image, encoding=self._encoding)
        img_msg.header.stamp = stamp
        img_msg.header.frame_id = frame_id

        info_msg = _make_camera_info(width, height, stamp, frame_id)

        self._image_pub.publish(img_msg)
        self._info_pub.publish(info_msg)

    def destroy_node(self) -> None:
        self._zmq_socket.close()
        self._zmq_context.term()
        super().destroy_node()

def _ns_to_ros_time(ns: int) -> Time:
    t = Time()
    t.sec = ns // 1_000_000_000
    t.nanosec = ns % 1_000_000_000
    return t

def _make_camera_info(width: int, height: int, stamp: Time, frame_id: str) -> CameraInfo:
    """
    Returns a CameraInfo with identity intrinsics; placeholder until
    Baslisk camera parameters are known and calibration is performed
    """
    info = CameraInfo()
    info.header.stamp = stamp
    info.header.frame_id = frame_id
    info.width = width
    info.height = height
    info.distortion_model = 'plumb_bob'
    info.d = [0.0, 0.0, 0.0, 0.0, 0.0]
    
    # Intrinsic matrix K (3x3, row-major), identity focal length placeholder
    info.k = [1.0, 0.0, float(width / 2),
              0.0, 1.0, float(height / 2),
              0.0, 0.0, 1.0]
    info.r = [1.0, 0.0, 0.0,
              0.0, 1.0, 0.0,
              0.0, 0.0, 1.0]
    info.p = [1.0, 0.0, float(width / 2), 0.0,
              0.0, 1.0, float(height / 2), 0.0,
              0.0, 0.0, 1.0,                0.0]
    return info

def main(args=None):
    rclpy.init(args=args)
    node = BasiliskCameraNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

