# Standard ROS2 header for timestamping statistics
std_msgs/Header header

# Mean (average) processing latency in milliseconds
float64 mean_ms

# 95th percentile latency
float64 p95_ms

# 99th percentile latency
float64 p99_ms

# Maximum observed latency in this sample window
float64 max_ms

uint64 sequence_gap_count
uint64 stale_packet_count