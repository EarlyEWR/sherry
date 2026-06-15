// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from telemetry_bridge:msg/TelemetryState.idl
// generated code does not contain a copyright notice

#ifndef TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__TRAITS_HPP_
#define TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__TRAITS_HPP_

#include "telemetry_bridge/msg/detail/telemetry_state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<telemetry_bridge::msg::TelemetryState>()
{
  return "telemetry_bridge::msg::TelemetryState";
}

template<>
inline const char * name<telemetry_bridge::msg::TelemetryState>()
{
  return "telemetry_bridge/msg/TelemetryState";
}

template<>
struct has_fixed_size<telemetry_bridge::msg::TelemetryState>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<telemetry_bridge::msg::TelemetryState>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<telemetry_bridge::msg::TelemetryState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__TRAITS_HPP_
