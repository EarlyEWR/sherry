#include "thruster_control/ThrusterControlNode.hpp"

#include <algorithm>
#include <cmath>

namespace thruster_control {

ThrusterControlNode::ThrusterControlNode()
: Node("thruster_control_node")
{
    this->declare_parameter("max_thrust_n", 500.0);
    this->declare_parameter("duration_ms", 20.0);
    this->declare_parameter("max_p95_latency_ms", 100.0);
    this->declare_parameter("health_timeout_sec", 2.0);

    max_thrust_n_ = this->get_parameter("max_thrust_n").as_double();
    duration_ms_ = this->get_parameter("duration_ms").as_double();
    max_p95_latency_ms_ = this->get_parameter("max_p95_latency_ms").as_double();
    health_timeout_sec_ = this->get_parameter("health_timeout_sec").as_double();

    // Hard-code the mix from the 6 thrusters defined in thruster_mix.yaml
    // In a follow-up these can be loaded dynamically from parameters
    thrusters_ = {
        {0, {1.0, 0.0, 0.0, 0.0, 0.0, 0.0}}, // aft_main
        {1, {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0}}, // fore_retro
        {2, {0.0, 1.0, 0.0, 0.0, 0.0, 0.0}}, //port_lateral
        {3, {0.0, -1.0, 0.0, 0.0, 0.0, 0.0}}, // starboard_lateral
        {4, {0.0, 0.0, 0.0, 0.0, 0.0, -1.0}}, // yaw_cw
        {5, {0.0, 0.0, 0.0, 0.0, 0.0, 1.0}}, // yaw_ccw
    };

    cmd_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
        "/cmd_vel", 10,
        std::bind(&ThrusterControlNode::on_cmd_vel, this, std::placeholders::_1));
    
    cmd_pub_ = this->create_publisher<thruster_control::msg::ThrusterCommand>("/thruster_command", 10);
    
    latency_stats_sub_ = this->create_subscription<telemetry_bridge::msg::LatencyStats>(
        "telemetry/latency_stats",
        rclcpp::QoS(10).reliable(),
        std::bind(&ThrusterControlNode::on_latency_stats, this, std::placeholders::_1));
}

void ThrusterControlNode::on_latency_stats(
    const telemetry_bridge::msg::LatencyStats::SharedPtr msg)
{
    last_stats_time_ = rclcpp::Time(msg->header.stamp);
    is_healthy_ = (msg->p95_ms < max_p95_latency_ms_);
}

void ThrusterControlNode::on_cmd_vel(const geometry_msgs::msg::Twist::SharedPtr msg)
{
    if (!last_stats_time_.has_value()) {
        RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
        "No telemetry health stats received yet, supressing command");
        
        return;
    }

    if ((this->now() - *last_stats_time_).seconds() > health_timeout_sec_) {
        is_healthy_ = false;
        RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
        "Telemetry health stats timed out, supressing command");
        
        return;
    }

    if (!is_healthy_) {
        RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000, 
        "Telemetry latency out of bounds, supressing command");

        return;
    }

    // Pack the 6-DOF demand vector from the Twist message
    std::array<double, 6> demand = {
        msg->linear.x, // forward
        msg->linear.y, // lateral
        msg->linear.z, // vertical
        msg->angular.x, // roll
        msg->angular.y, // pitch
        msg->angular.z, // yaw
    };

    thruster_control::msg::ThrusterCommand cmd;
    cmd.header.stamp = this->get_clock()->now();
    cmd.duration_ms = duration_ms_;

    for (const auto & t : thrusters_) {
        // Dot product: how much does this thruster contribute to the demand?
        double level = 0.0;
        for (std::size_t i = 0; i < 6; ++i) {
            level += t.influence[i] * demand[i];
        }

        // Only fire if the dot product is positive (thruster pushes the right way)
        if (level > 0.0) {
            level = std::min(level, 1.0); // clamp to max
            cmd.thruster_ids.push_back(t.id);
            cmd.thrust_levels.push_back(level);
        }
    }

    cmd_pub_->publish(cmd);
}

} // namespace thruster_control