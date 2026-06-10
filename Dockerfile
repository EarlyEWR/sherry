FROM ros:foxy
#Install build tools
RUN apt-get update && apt-get install -y build-essential
# Set up workspace
WORKDIR /pillar-project-1
COPY ./src ./src
# Build the ROS2 bridge
RUN . /opt/ros/foxy/setup.sh && colcon build
# Run the node on startup
CMD ["bash", "-c", "source install/setup.bash && ros2 run telemetry_bridge udp_bridge"]