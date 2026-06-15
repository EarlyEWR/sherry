// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from telemetry_bridge:msg/LatencyStats.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "telemetry_bridge/msg/detail/latency_stats__rosidl_typesupport_introspection_c.h"
#include "telemetry_bridge/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "telemetry_bridge/msg/detail/latency_stats__functions.h"
#include "telemetry_bridge/msg/detail/latency_stats__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  telemetry_bridge__msg__LatencyStats__init(message_memory);
}

void LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_fini_function(void * message_memory)
{
  telemetry_bridge__msg__LatencyStats__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_message_member_array[7] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(telemetry_bridge__msg__LatencyStats, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mean_ms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(telemetry_bridge__msg__LatencyStats, mean_ms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "p95_ms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(telemetry_bridge__msg__LatencyStats, p95_ms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "p99_ms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(telemetry_bridge__msg__LatencyStats, p99_ms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_ms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(telemetry_bridge__msg__LatencyStats, max_ms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sequence_gap_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(telemetry_bridge__msg__LatencyStats, sequence_gap_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stale_packet_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(telemetry_bridge__msg__LatencyStats, stale_packet_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_message_members = {
  "telemetry_bridge__msg",  // message namespace
  "LatencyStats",  // message name
  7,  // number of fields
  sizeof(telemetry_bridge__msg__LatencyStats),
  LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_message_member_array,  // message members
  LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_init_function,  // function to initialize message memory (memory has to be allocated)
  LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_message_type_support_handle = {
  0,
  &LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_telemetry_bridge
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, telemetry_bridge, msg, LatencyStats)() {
  LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_message_type_support_handle.typesupport_identifier) {
    LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &LatencyStats__rosidl_typesupport_introspection_c__LatencyStats_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
