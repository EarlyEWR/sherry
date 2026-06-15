#include "../../include/sim_clock/SimClockNode.hpp"

namespace sim_clock {

SimClockNode::SimClockNode()
: Node("sim_clock_node")
{
    this->declare_parameter("sim_frequency_hz", 100.0);
    this->declare_parameter("realtime_factor", 1.0);

    sim_frequency_hz_ = this->get_parameter("sim_frequency_hz").as_double();
    realtime_factor_ = this->get_parameter("realtime_factor").as_double();

    clock_pub_ = this->create_publisher<rosgraph_msgs::msg::Clock>("/clock", 10);
    
    // Fire tick() every (1 / frequency) real-world seconds
    auto period = std::chrono::duration<double>(1.0 / sim_frequency_hz_);
    time_ = this->create_wall_timer(
        std::chrono::duration_cast<std::chrono::nanoseconds>(period),
        std::bind(&SimClockNode::tick, this));
}

void SimClockNode::tick()
{
    // Advance sim time by one dt, scaled by the realtime factor
    double dt = (1.0 / sim_frequency_hz_) * realtime_factor_;
    sim_time_sec_ += dt;

    auto msg = rosgraph_msgs::msg::Clock();
    msg.clock.sec = static_cast<int32_t>(sim_time_sec_);
    msg.clock.nanosec = static_cast<uint32_t>(
        (sim_time_sec_ - static_cast<int32_t>(sim_time_sec_)) * 1e9);
    
    clock_pub_->publish(msg);
}

} // namespace sim_clock