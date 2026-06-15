// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from telemetry_bridge:msg/LatencyStats.idl
// generated code does not contain a copyright notice

#ifndef TELEMETRY_BRIDGE__MSG__DETAIL__LATENCY_STATS__STRUCT_HPP_
#define TELEMETRY_BRIDGE__MSG__DETAIL__LATENCY_STATS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__telemetry_bridge__msg__LatencyStats __attribute__((deprecated))
#else
# define DEPRECATED__telemetry_bridge__msg__LatencyStats __declspec(deprecated)
#endif

namespace telemetry_bridge
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LatencyStats_
{
  using Type = LatencyStats_<ContainerAllocator>;

  explicit LatencyStats_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mean_ms = 0.0;
      this->p95_ms = 0.0;
      this->p99_ms = 0.0;
      this->max_ms = 0.0;
      this->sequence_gap_count = 0ull;
      this->stale_packet_count = 0ull;
    }
  }

  explicit LatencyStats_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mean_ms = 0.0;
      this->p95_ms = 0.0;
      this->p99_ms = 0.0;
      this->max_ms = 0.0;
      this->sequence_gap_count = 0ull;
      this->stale_packet_count = 0ull;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _mean_ms_type =
    double;
  _mean_ms_type mean_ms;
  using _p95_ms_type =
    double;
  _p95_ms_type p95_ms;
  using _p99_ms_type =
    double;
  _p99_ms_type p99_ms;
  using _max_ms_type =
    double;
  _max_ms_type max_ms;
  using _sequence_gap_count_type =
    uint64_t;
  _sequence_gap_count_type sequence_gap_count;
  using _stale_packet_count_type =
    uint64_t;
  _stale_packet_count_type stale_packet_count;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__mean_ms(
    const double & _arg)
  {
    this->mean_ms = _arg;
    return *this;
  }
  Type & set__p95_ms(
    const double & _arg)
  {
    this->p95_ms = _arg;
    return *this;
  }
  Type & set__p99_ms(
    const double & _arg)
  {
    this->p99_ms = _arg;
    return *this;
  }
  Type & set__max_ms(
    const double & _arg)
  {
    this->max_ms = _arg;
    return *this;
  }
  Type & set__sequence_gap_count(
    const uint64_t & _arg)
  {
    this->sequence_gap_count = _arg;
    return *this;
  }
  Type & set__stale_packet_count(
    const uint64_t & _arg)
  {
    this->stale_packet_count = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    telemetry_bridge::msg::LatencyStats_<ContainerAllocator> *;
  using ConstRawPtr =
    const telemetry_bridge::msg::LatencyStats_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<telemetry_bridge::msg::LatencyStats_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<telemetry_bridge::msg::LatencyStats_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      telemetry_bridge::msg::LatencyStats_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<telemetry_bridge::msg::LatencyStats_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      telemetry_bridge::msg::LatencyStats_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<telemetry_bridge::msg::LatencyStats_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<telemetry_bridge::msg::LatencyStats_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<telemetry_bridge::msg::LatencyStats_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__telemetry_bridge__msg__LatencyStats
    std::shared_ptr<telemetry_bridge::msg::LatencyStats_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__telemetry_bridge__msg__LatencyStats
    std::shared_ptr<telemetry_bridge::msg::LatencyStats_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LatencyStats_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->mean_ms != other.mean_ms) {
      return false;
    }
    if (this->p95_ms != other.p95_ms) {
      return false;
    }
    if (this->p99_ms != other.p99_ms) {
      return false;
    }
    if (this->max_ms != other.max_ms) {
      return false;
    }
    if (this->sequence_gap_count != other.sequence_gap_count) {
      return false;
    }
    if (this->stale_packet_count != other.stale_packet_count) {
      return false;
    }
    return true;
  }
  bool operator!=(const LatencyStats_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LatencyStats_

// alias to use template instance with default allocator
using LatencyStats =
  telemetry_bridge::msg::LatencyStats_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace telemetry_bridge

#endif  // TELEMETRY_BRIDGE__MSG__DETAIL__LATENCY_STATS__STRUCT_HPP_
