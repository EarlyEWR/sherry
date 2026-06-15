#ifndef TELEMETRY_BRIDGE__UDP_BRIDGE_NODE_HPP_
#define TELEMETRY_BRIDGE__UDP_BRIDGE_NODE_HPP_

#include <atomic>
#include <cstdint>
#include <thread>
#include <vector>

#include <netinet/in.h>

#include "rclcpp/rclcpp.hpp"
#include "telemetry_bridge/msg/telemetry_state.hpp"

namespace telemetry_bridge {

class UdpBridgeNode : public rclcpp::Node {
public:
    UdpBridgeNode();
    ~UdpBridgeNode();

private:
    void handle_outgoing_state(const telemetry_bridge::msg::TelemetryState::SharedPtr msg);
    void receive_loop();
    std::vector<uint8_t> serialize_state(const telemetry_bridge::msg::TelemetryState & msg) const;
    bool deserialize_state(
        const uint8_t * data,
        std::size_t size,
        telemetry_bridge::msg::TelemetryState & out_msg) const;

    rclcpp::Subscription<telemetry_bridge::msg::TelemetryState>::SharedPtr outgoing_sub_;
    rclcpp::Publisher<telemetry_bridge::msg::TelemetryState>::SharedPtr incoming_pub_;

    int socket_fd_{-1};
    sockaddr_in local_addr_{};
    sockaddr_in remote_addr_{};
    std::atomic<bool> running_{false};
    std::thread receiver_thread_;

    static constexpr std::size_t PACKET_SIZE = 112;

    int udp_port_{8091};
    std::string target_ip_{"127.0.0.1"};
    int qos_depth_{10};
};

} // namespace telemetry_bridge

#endif