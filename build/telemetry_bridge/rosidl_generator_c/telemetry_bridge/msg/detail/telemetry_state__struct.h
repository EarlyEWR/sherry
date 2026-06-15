// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from telemetry_bridge:msg/TelemetryState.idl
// generated code does not contain a copyright notice

#ifndef TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__STRUCT_H_
#define TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in msg/TelemetryState in the package telemetry_bridge.
typedef struct telemetry_bridge__msg__TelemetryState
{
  std_msgs__msg__Header header;
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  uint64_t sequence_id;
  geometry_msgs__msg__Pose pose;
} telemetry_bridge__msg__TelemetryState;

// Struct for a sequence of telemetry_bridge__msg__TelemetryState.
typedef struct telemetry_bridge__msg__TelemetryState__Sequence
{
  telemetry_bridge__msg__TelemetryState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} telemetry_bridge__msg__TelemetryState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__STRUCT_H_
