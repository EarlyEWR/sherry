// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from telemetry_bridge:msg/LatencyStats.idl
// generated code does not contain a copyright notice
#include "telemetry_bridge/msg/detail/latency_stats__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "telemetry_bridge/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "telemetry_bridge/msg/detail/latency_stats__struct.h"
#include "telemetry_bridge/msg/detail/latency_stats__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_telemetry_bridge
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_telemetry_bridge
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_telemetry_bridge
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _LatencyStats__ros_msg_type = telemetry_bridge__msg__LatencyStats;

static bool _LatencyStats__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LatencyStats__ros_msg_type * ros_message = static_cast<const _LatencyStats__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: mean_ms
  {
    cdr << ros_message->mean_ms;
  }

  // Field name: p95_ms
  {
    cdr << ros_message->p95_ms;
  }

  // Field name: p99_ms
  {
    cdr << ros_message->p99_ms;
  }

  // Field name: max_ms
  {
    cdr << ros_message->max_ms;
  }

  // Field name: sequence_gap_count
  {
    cdr << ros_message->sequence_gap_count;
  }

  // Field name: stale_packet_count
  {
    cdr << ros_message->stale_packet_count;
  }

  return true;
}

static bool _LatencyStats__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LatencyStats__ros_msg_type * ros_message = static_cast<_LatencyStats__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: mean_ms
  {
    cdr >> ros_message->mean_ms;
  }

  // Field name: p95_ms
  {
    cdr >> ros_message->p95_ms;
  }

  // Field name: p99_ms
  {
    cdr >> ros_message->p99_ms;
  }

  // Field name: max_ms
  {
    cdr >> ros_message->max_ms;
  }

  // Field name: sequence_gap_count
  {
    cdr >> ros_message->sequence_gap_count;
  }

  // Field name: stale_packet_count
  {
    cdr >> ros_message->stale_packet_count;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_telemetry_bridge
size_t get_serialized_size_telemetry_bridge__msg__LatencyStats(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LatencyStats__ros_msg_type * ros_message = static_cast<const _LatencyStats__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name mean_ms
  {
    size_t item_size = sizeof(ros_message->mean_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p95_ms
  {
    size_t item_size = sizeof(ros_message->p95_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p99_ms
  {
    size_t item_size = sizeof(ros_message->p99_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_ms
  {
    size_t item_size = sizeof(ros_message->max_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sequence_gap_count
  {
    size_t item_size = sizeof(ros_message->sequence_gap_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name stale_packet_count
  {
    size_t item_size = sizeof(ros_message->stale_packet_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LatencyStats__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_telemetry_bridge__msg__LatencyStats(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_telemetry_bridge
size_t max_serialized_size_telemetry_bridge__msg__LatencyStats(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: mean_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p95_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p99_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: max_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: sequence_gap_count
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: stale_packet_count
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _LatencyStats__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_telemetry_bridge__msg__LatencyStats(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_LatencyStats = {
  "telemetry_bridge::msg",
  "LatencyStats",
  _LatencyStats__cdr_serialize,
  _LatencyStats__cdr_deserialize,
  _LatencyStats__get_serialized_size,
  _LatencyStats__max_serialized_size
};

static rosidl_message_type_support_t _LatencyStats__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LatencyStats,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, telemetry_bridge, msg, LatencyStats)() {
  return &_LatencyStats__type_support;
}

#if defined(__cplusplus)
}
#endif
