// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from telemetry_bridge:msg/TelemetryState.idl
// generated code does not contain a copyright notice

#ifndef TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__STRUCT_HPP_
#define TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__STRUCT_HPP_

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
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__telemetry_bridge__msg__TelemetryState __attribute__((deprecated))
#else
# define DEPRECATED__telemetry_bridge__msg__TelemetryState __declspec(deprecated)
#endif

namespace telemetry_bridge
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TelemetryState_
{
  using Type = TelemetryState_<ContainerAllocator>;

  explicit TelemetryState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->vx = 0.0;
      this->vy = 0.0;
      this->vz = 0.0;
      this->sequence_id = 0ull;
    }
  }

  explicit TelemetryState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->vx = 0.0;
      this->vy = 0.0;
      this->vz = 0.0;
      this->sequence_id = 0ull;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _vx_type =
    double;
  _vx_type vx;
  using _vy_type =
    double;
  _vy_type vy;
  using _vz_type =
    double;
  _vz_type vz;
  using _sequence_id_type =
    uint64_t;
  _sequence_id_type sequence_id;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__vx(
    const double & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const double & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__vz(
    const double & _arg)
  {
    this->vz = _arg;
    return *this;
  }
  Type & set__sequence_id(
    const uint64_t & _arg)
  {
    this->sequence_id = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    telemetry_bridge::msg::TelemetryState_<ContainerAllocator> *;
  using ConstRawPtr =
    const telemetry_bridge::msg::TelemetryState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<telemetry_bridge::msg::TelemetryState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<telemetry_bridge::msg::TelemetryState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      telemetry_bridge::msg::TelemetryState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<telemetry_bridge::msg::TelemetryState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      telemetry_bridge::msg::TelemetryState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<telemetry_bridge::msg::TelemetryState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<telemetry_bridge::msg::TelemetryState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<telemetry_bridge::msg::TelemetryState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__telemetry_bridge__msg__TelemetryState
    std::shared_ptr<telemetry_bridge::msg::TelemetryState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__telemetry_bridge__msg__TelemetryState
    std::shared_ptr<telemetry_bridge::msg::TelemetryState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TelemetryState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->vz != other.vz) {
      return false;
    }
    if (this->sequence_id != other.sequence_id) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const TelemetryState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TelemetryState_

// alias to use template instance with default allocator
using TelemetryState =
  telemetry_bridge::msg::TelemetryState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace telemetry_bridge

#endif  // TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__STRUCT_HPP_
