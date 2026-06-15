#include "telemetry_bridge/StateMonitorNode.hpp"

#include <chrono>
#include <functional>

namespace telemetry_bridge {

StateMonitorNode::StateMonitorNode(const rclcpp::NodeOptions & options)
: Node("state_monitor_node", options)
{
  state_sub_ = this->create_subscription<telemetry_bridge::msg::TelemetryState>(
    "telemetry/incoming",
    10,
    std::bind(&StateMonitorNode::handle_state, this, std::placeholders::_1));

  stats_pub_ = this->create_publisher<telemetry_bridge::msg::LatencyStats>(
    "telemetry/latency_stats",
    10);

  stats_timer_ = this->create_wall_timer(
    std::chrono::seconds(1),
    std::bind(&StateMonitorNode::publish_latency_stats, this));
}

bool StateMonitorNode::has_state() const
{
  std::lock_guard<std::mutex> lock(mutex_);
  return has_state_;
}

uint64_t StateMonitorNode::last_sequence_id() const
{
  std::lock_guard<std::mutex> lock(mutex_);
  return last_sequence_id_;
}

uint64_t StateMonitorNode::sequence_gap_count() const
{
  std::lock_guard<std::mutex> lock(mutex_);
  return sequence_gap_count_;
}

uint64_t StateMonitorNode::stale_packet_count() const
{
  std::lock_guard<std::mutex> lock(mutex_);
  return stale_packet_count_;
}

telemetry_bridge::msg::TelemetryState StateMonitorNode::last_state() const
{
  std::lock_guard<std::mutex> lock(mutex_);
  return last_state_;
}

void StateMonitorNode::handle_state(
  const telemetry_bridge::msg::TelemetryState::SharedPtr msg)
{
  process_state(*msg);
}

void StateMonitorNode::process_state(
  const telemetry_bridge::msg::TelemetryState & msg)
{
  const auto now = this->now();
  const auto stamp = rclcpp::Time(msg.header.stamp);
  const double latency_ms = (now - stamp).seconds() * 1000.0;

  if (latency_ms >= 0.0) {
    latency_monitor_.add_sample(latency_ms);
  }

  std::lock_guard<std::mutex> lock(mutex_);

  if (!has_state_) {
    last_state_ = msg;
    last_sequence_id_ = msg.sequence_id;
    has_state_ = true;
    return;
  }

  if (msg.sequence_id <= last_sequence_id_) {
    ++stale_packet_count_;
    return;
  }

  if (msg.sequence_id > last_sequence_id_ + 1) {
    sequence_gap_count_ += (msg.sequence_id - last_sequence_id_ - 1);
  }

  last_state_ = msg;
  last_sequence_id_ = msg.sequence_id;
}

void StateMonitorNode::publish_latency_stats()
{
  telemetry_bridge::msg::LatencyStats stats_msg;
  stats_msg.header.stamp = this->now();
  stats_msg.mean_ms = 0.0;
  stats_msg.p95_ms = latency_monitor_.get_p95();
  stats_msg.p99_ms = latency_monitor_.get_p99();
  stats_msg.max_ms = 0.0;

  {
    std::lock_guard<std::mutex> lock(mutex_);
    stats_msg.sequence_gap_count = sequence_gap_count_;
    stats_msg.stale_packet_count = stale_packet_count_;
  }

  stats_pub_->publish(stats_msg);
}

}  // namespace telemetry_bridge