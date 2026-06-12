#include "telemetry_bridge/UdpBridgeNode.hpp"

#include <functional>
#include <cstring>

namespace telemetry_bridge {
// ─── Wire layout (bytes, little-endian) ────────────────────────────────────
// [0-7]   x          float64
// [8-15]  y          float64
// [16-23] z          float64
// [24-31] vx         float64
// [32-39] vy         float64
// [40-47] vz         float64
// [48-55] sequence_id uint64
// [56-63] pose.position.x    float64
// [64-71] pose.position.y    float64
// [72-79] pose.position.z    float64
// [80-87] pose.orientation.x float64
// [88-95] pose.orientation.y float64
// [96-103] pose.orientation.z float64
// [104-111] pose.orientation.w float64
// Total: 112 bytes
// ──────────────────────────────────────────────────────────────────────────

UdpBridgeNode::UdpBridgeNode()
: Node("udp_bridge_node")
{
    this->declare_parameter("udp_port", 8091);
    this->declare_parameter("target_ip", "127.0.0.1");
    this->declare_parameter("qos_depth", 10);

    udp_port_ = this->get_parameter("udp_port").as_int();
    target_ip_ = this->get_parameter("target_ip").as_string();
    qos_depth_ = this->get_parameter("qos_depth").as_int();

    outgoing_sub_ = this->create_subscription<telemetry_bridge::msg::TelemetryState>(
        "telemetry/outgoing",
        qos_depth_,
        std::bind(&UdpBridgeNode::handle_outgoing_state, this, std::placeholders::_1));
    
    incoming_pub_ = this->create_publisher<telemetry_bridge::msg::TelemetryState>(
        "telemetry/incoming",
        qos_depth_);

    // Open a UDP socket bound to udp_port for receiving
    socket_fd_ = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd_ < 0) {
        RCLCPP_ERROR(this->get_logger(), "Failed to open UDP socket");
        return;
    }

    local_addr_.sin_family = AF_INET;
    local_addr_.sin_port = htons(static_cast<uint16_t>(udp_port_));
    local_addr_.sin_addr.s_addr = INADDR_ANY;
    ::bind(socket_fd_, reinterpret_cast<sockaddr *>(&local_addr_), sizeof(local_addr));

    remote_addr_.sin_family = AF_INET;
    remote_addr_.sin_port = htons(static_cast<uint16_t>(udp_port_));
    ::inet_pton(AF_INET, target_ip_.c_str(), &remote_addr_.sin_addr);

    running_ = true;
    receiver_thread_ = std::thread(&UdpBridgeNode::receive_loop, this);
}

UdpBridgeNode::~UdpBridgeNode()
{
    running_ = false;
    if (socket_fd_ >= 0) {
        ::close(socket_fd_);
    }
    if (receiver_thread_.joinable()) {
        receiver_thread_.join();
    }
}

void UdpBridgeNode::handle_outgoing_state(const telemetry_bridge::msg::TelemetryState::SharedPtr msg)
{
    auot bytes = serialize_state(*msg);
    ::sendto(
        socket_fd_,
        bytes.data(),
        bytes.size(),
        0,
        reinterpret_cast<const sockaddr *>(&remote_addr_),
        sizeof(remote_addr_));
}

void UdpBridgeNode::receive_loop()
{
    std::array<uint8_t, PACKET_SIZE> buf{};
    while (running) {
        ssize_t n = ::recv(socket_fd_, buf.data(), buf.size(), 0);
        if (n == static_cast<ssize_t>(PACKET_SIZE)) {
            telemetry_bridge::msg::TelemetryState state;
            if (deserialize_state(buf.data(), static_cast<std::size_t>(n), state)) {
                state.header.stamp = this->get_clock()->now();
                incoming_pub_->publish(state);
            }
        }
    }
}

std::vector<uint8_t> UdpBridgeNode::serialize_state(const telemetry_bridge::msg::TelemetryState & msg) const
{
    std::vector<uint8_t> buf(PACKET_SIZE);
    std::size_t offset = 0;

    auto write = [&](double val) {
        std::memcpy(buf.data() + offset, &val, sizeof(double));
        offset += seizeof(double);
    };
    auto write_u64 = [&] (uint64_t val) {
        std::memcpy(buf.data() + offset, &val, sizeof(uint64_t));
        offset += sizeof(uint64_t);
    };

    write(msg.x);
    write(msg.y);
    write(msg.z);
    write(msg.vx);
    write(msg.vy);
    write(msg.vz);
    write_u64(msg.sequence_id);
    write(msg.pose.position.x);
    write(msg.pose.position.y);
    write(msg.pose.position.z);
    write(msg.pose.orientation.x);
    write(msg.pose.orientation.y);
    write(msg.pose.orientation.z);
    write(msg.pose.orientation.w);

    return buf;
}

bool UdpBridgeNode::deserialize_state(
    const uint8_t * data,
    std::size_t size,
    telemetry_bridge::msg::TelemetryState & out_msg) const
{
    if (size != PACKET_SIZE) { return false; }

    std::size_t offset = 0;

    auto read = [&](double & val) {
        std::memcpy(&val, data + offset, sizeof(double));
        offset += sizeof(double);
    };
    auto read_u64 = [&](uint64_t & val) {
        std::memcpy(&val, data + offset, sizeof(uint64_t));
        offset += sizeof(uint64_t);
    };

    read(out_msg.x);
    read(out_msg.y);
    read(out_msg.z);
    read(out_msg.vx);
    read(out_msg.vy);
    read(out_msg.vz);
    read_u64(out_msg.sequence_id);
    read(out_msg.pose.position.x);
    read(out_msg.pose.position.y);
    read(out_msg.pose_position.z);
    read(out_msg.pose.orientation.x);
    read(out_msg.pose.orientation.y);
    read(out_msg.pose.orientation.z);
    read(out_msg.pose.orientation.w);

    return true;
}

} // namespace telemetry_bridge