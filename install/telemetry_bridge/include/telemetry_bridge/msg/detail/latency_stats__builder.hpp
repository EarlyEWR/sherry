// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from telemetry_bridge:msg/LatencyStats.idl
// generated code does not contain a copyright notice

#ifndef TELEMETRY_BRIDGE__MSG__DETAIL__LATENCY_STATS__BUILDER_HPP_
#define TELEMETRY_BRIDGE__MSG__DETAIL__LATENCY_STATS__BUILDER_HPP_

#include "telemetry_bridge/msg/detail/latency_stats__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace telemetry_bridge
{

namespace msg
{

namespace builder
{

class Init_LatencyStats_stale_packet_count
{
public:
  explicit Init_LatencyStats_stale_packet_count(::telemetry_bridge::msg::LatencyStats & msg)
  : msg_(msg)
  {}
  ::telemetry_bridge::msg::LatencyStats stale_packet_count(::telemetry_bridge::msg::LatencyStats::_stale_packet_count_type arg)
  {
    msg_.stale_packet_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::telemetry_bridge::msg::LatencyStats msg_;
};

class Init_LatencyStats_sequence_gap_count
{
public:
  explicit Init_LatencyStats_sequence_gap_count(::telemetry_bridge::msg::LatencyStats & msg)
  : msg_(msg)
  {}
  Init_LatencyStats_stale_packet_count sequence_gap_count(::telemetry_bridge::msg::LatencyStats::_sequence_gap_count_type arg)
  {
    msg_.sequence_gap_count = std::move(arg);
    return Init_LatencyStats_stale_packet_count(msg_);
  }

private:
  ::telemetry_bridge::msg::LatencyStats msg_;
};

class Init_LatencyStats_max_ms
{
public:
  explicit Init_LatencyStats_max_ms(::telemetry_bridge::msg::LatencyStats & msg)
  : msg_(msg)
  {}
  Init_LatencyStats_sequence_gap_count max_ms(::telemetry_bridge::msg::LatencyStats::_max_ms_type arg)
  {
    msg_.max_ms = std::move(arg);
    return Init_LatencyStats_sequence_gap_count(msg_);
  }

private:
  ::telemetry_bridge::msg::LatencyStats msg_;
};

class Init_LatencyStats_p99_ms
{
public:
  explicit Init_LatencyStats_p99_ms(::telemetry_bridge::msg::LatencyStats & msg)
  : msg_(msg)
  {}
  Init_LatencyStats_max_ms p99_ms(::telemetry_bridge::msg::LatencyStats::_p99_ms_type arg)
  {
    msg_.p99_ms = std::move(arg);
    return Init_LatencyStats_max_ms(msg_);
  }

private:
  ::telemetry_bridge::msg::LatencyStats msg_;
};

class Init_LatencyStats_p95_ms
{
public:
  explicit Init_LatencyStats_p95_ms(::telemetry_bridge::msg::LatencyStats & msg)
  : msg_(msg)
  {}
  Init_LatencyStats_p99_ms p95_ms(::telemetry_bridge::msg::LatencyStats::_p95_ms_type arg)
  {
    msg_.p95_ms = std::move(arg);
    return Init_LatencyStats_p99_ms(msg_);
  }

private:
  ::telemetry_bridge::msg::LatencyStats msg_;
};

class Init_LatencyStats_mean_ms
{
public:
  explicit Init_LatencyStats_mean_ms(::telemetry_bridge::msg::LatencyStats & msg)
  : msg_(msg)
  {}
  Init_LatencyStats_p95_ms mean_ms(::telemetry_bridge::msg::LatencyStats::_mean_ms_type arg)
  {
    msg_.mean_ms = std::move(arg);
    return Init_LatencyStats_p95_ms(msg_);
  }

private:
  ::telemetry_bridge::msg::LatencyStats msg_;
};

class Init_LatencyStats_header
{
public:
  Init_LatencyStats_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LatencyStats_mean_ms header(::telemetry_bridge::msg::LatencyStats::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LatencyStats_mean_ms(msg_);
  }

private:
  ::telemetry_bridge::msg::LatencyStats msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::telemetry_bridge::msg::LatencyStats>()
{
  return telemetry_bridge::msg::builder::Init_LatencyStats_header();
}

}  // namespace telemetry_bridge

#endif  // TELEMETRY_BRIDGE__MSG__DETAIL__LATENCY_STATS__BUILDER_HPP_
