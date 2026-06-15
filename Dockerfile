FROM ros:foxy-ros-base-focal
#Install build tools
RUN apt-get update && apt-get install -y \
    build-essential \
    ros-foxy-ament-cmake-gtest \
    ros-foxy-vision-msgs \
    ros-foxy-cv-bridge \
    ros-foxy-image-transport \
    python3-zmq \
    python3-pip
RUN pip3 install ultralytics
# Set up workspace
WORKDIR /sherry
COPY ./src ./src
# Build the ROS2 bridge
RUN . /opt/ros/foxy/setup.sh && colcon build
# Run the node on startup
CMD ["bash", "-c", "source install/setup.bash && ros2 run telemetry_bridge udp_bridge"]