// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from telemetry_bridge:msg/TelemetryState.idl
// generated code does not contain a copyright notice

#ifndef TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__BUILDER_HPP_
#define TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__BUILDER_HPP_

#include "telemetry_bridge/msg/detail/telemetry_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace telemetry_bridge
{

namespace msg
{

namespace builder
{

class Init_TelemetryState_pose
{
public:
  explicit Init_TelemetryState_pose(::telemetry_bridge::msg::TelemetryState & msg)
  : msg_(msg)
  {}
  ::telemetry_bridge::msg::TelemetryState pose(::telemetry_bridge::msg::TelemetryState::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::telemetry_bridge::msg::TelemetryState msg_;
};

class Init_TelemetryState_sequence_id
{
public:
  explicit Init_TelemetryState_sequence_id(::telemetry_bridge::msg::TelemetryState & msg)
  : msg_(msg)
  {}
  Init_TelemetryState_pose sequence_id(::telemetry_bridge::msg::TelemetryState::_sequence_id_type arg)
  {
    msg_.sequence_id = std::move(arg);
    return Init_TelemetryState_pose(msg_);
  }

private:
  ::telemetry_bridge::msg::TelemetryState msg_;
};

class Init_TelemetryState_vz
{
public:
  explicit Init_TelemetryState_vz(::telemetry_bridge::msg::TelemetryState & msg)
  : msg_(msg)
  {}
  Init_TelemetryState_sequence_id vz(::telemetry_bridge::msg::TelemetryState::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_TelemetryState_sequence_id(msg_);
  }

private:
  ::telemetry_bridge::msg::TelemetryState msg_;
};

class Init_TelemetryState_vy
{
public:
  explicit Init_TelemetryState_vy(::telemetry_bridge::msg::TelemetryState & msg)
  : msg_(msg)
  {}
  Init_TelemetryState_vz vy(::telemetry_bridge::msg::TelemetryState::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_TelemetryState_vz(msg_);
  }

private:
  ::telemetry_bridge::msg::TelemetryState msg_;
};

class Init_TelemetryState_vx
{
public:
  explicit Init_TelemetryState_vx(::telemetry_bridge::msg::TelemetryState & msg)
  : msg_(msg)
  {}
  Init_TelemetryState_vy vx(::telemetry_bridge::msg::TelemetryState::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_TelemetryState_vy(msg_);
  }

private:
  ::telemetry_bridge::msg::TelemetryState msg_;
};

class Init_TelemetryState_z
{
public:
  explicit Init_TelemetryState_z(::telemetry_bridge::msg::TelemetryState & msg)
  : msg_(msg)
  {}
  Init_TelemetryState_vx z(::telemetry_bridge::msg::TelemetryState::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_TelemetryState_vx(msg_);
  }

private:
  ::telemetry_bridge::msg::TelemetryState msg_;
};

class Init_TelemetryState_y
{
public:
  explicit Init_TelemetryState_y(::telemetry_bridge::msg::TelemetryState & msg)
  : msg_(msg)
  {}
  Init_TelemetryState_z y(::telemetry_bridge::msg::TelemetryState::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TelemetryState_z(msg_);
  }

private:
  ::telemetry_bridge::msg::TelemetryState msg_;
};

class Init_TelemetryState_x
{
public:
  explicit Init_TelemetryState_x(::telemetry_bridge::msg::TelemetryState & msg)
  : msg_(msg)
  {}
  Init_TelemetryState_y x(::telemetry_bridge::msg::TelemetryState::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TelemetryState_y(msg_);
  }

private:
  ::telemetry_bridge::msg::TelemetryState msg_;
};

class Init_TelemetryState_header
{
public:
  Init_TelemetryState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TelemetryState_x header(::telemetry_bridge::msg::TelemetryState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TelemetryState_x(msg_);
  }

private:
  ::telemetry_bridge::msg::TelemetryState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::telemetry_bridge::msg::TelemetryState>()
{
  return telemetry_bridge::msg::builder::Init_TelemetryState_header();
}

}  // namespace telemetry_bridge

#endif  // TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__BUILDER_HPP_
