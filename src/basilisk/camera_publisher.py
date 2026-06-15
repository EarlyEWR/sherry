"""
Basilisk camera ZMQ publisher

Wire format (little-endian)
[0:4]   width       uint32
[4:8]   height      uint32
[8:16]  timestamp   uint64  (nanoseconds)
[16:]   pixels      uint8   (height x width x 3, RGB8)

Usage in Basilisk sim script:
    from basilisk.camera_publisher import CameraPublisher
    pub = CameraPublisher(port=5570)

    # Inside simulation step loop or camera task callback:
    pub.publish(camera_module.imageRawMsg, sim_time_ns)

    pub.close()
"""

import struct
import numpy as np
import zmq


class CameraPublisher:
    def __init__(self, host: str = "127.0.0.1", port: int = 5570):
        self._context = zmq.Context()
        self._socket = self._context.socket(zmq.PUB)
        self._socket.bind(f"tcp://{host}:{port}")

    def publish(self, image_msg, timestamp_ns: int) -> None:
        """
        Publish a Basilisk camera frame over ZMQ

        Args:
            image_msg:      Basilisk CameraImageMsg payload
                            Expected to have .imageData (numpy array, shape HxWx3, dtype uint8)
                            and .cameraIsOn (int, 1 = active)
            timestamp_ns:   Simulation time in nanoseconds
        """
        if not image_msg.cameraIsOn:
            return

        image: np.ndarray = np.array(image_msg.imageData, dtype=np.uint8)
        if image.ndim != 3 or image.shape[2] != 3:
            return

        height, width = image.shape[:2]
        header = struct.pack('<IIQ', width, height, timestamp_ns)
        self._socket.send(header + image.tobytes(), zmq.NOBLOCK)

    def close(self) -> None:
        self._socket.close()
        self._context.term()