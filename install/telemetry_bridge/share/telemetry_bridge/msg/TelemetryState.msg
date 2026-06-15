# Standard ROS2 header for synchronization and latency tracking
std_msgs/Header header

# 3D Position components in meters
float64 x
float64 y
float64 z

# 3D Velocity components in meters per second
float64 vx
float64 vy
float64 vz

# Sequence number to detect out-of-order UDP packets or gaps
uint64 sequence_id

# Full 6-DOF pose: position (mirrors x/y/z above) + orientation quaternion
geometry_msgs/Pose pose
