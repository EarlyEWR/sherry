// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from telemetry_bridge:msg/LatencyStats.idl
// generated code does not contain a copyright notice

#ifndef TELEMETRY_BRIDGE__MSG__DETAIL__LATENCY_STATS__STRUCT_H_
#define TELEMETRY_BRIDGE__MSG__DETAIL__LATENCY_STATS__STRUCT_H_

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

// Struct defined in msg/LatencyStats in the package telemetry_bridge.
typedef struct telemetry_bridge__msg__LatencyStats
{
  std_msgs__msg__Header header;
  double mean_ms;
  double p95_ms;
  double p99_ms;
  double max_ms;
  uint64_t sequence_gap_count;
  uint64_t stale_packet_count;
} telemetry_bridge__msg__LatencyStats;

// Struct for a sequence of telemetry_bridge__msg__LatencyStats.
typedef struct telemetry_bridge__msg__LatencyStats__Sequence
{
  telemetry_bridge__msg__LatencyStats * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} telemetry_bridge__msg__LatencyStats__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TELEMETRY_BRIDGE__MSG__DETAIL__LATENCY_STATS__STRUCT_H_
