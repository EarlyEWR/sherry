// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from telemetry_bridge:msg/LatencyStats.idl
// generated code does not contain a copyright notice
#include "telemetry_bridge/msg/detail/latency_stats__rosidl_typesupport_fastrtps_cpp.hpp"
#include "telemetry_bridge/msg/detail/latency_stats__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace telemetry_bridge
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemetry_bridge
cdr_serialize(
  const telemetry_bridge::msg::LatencyStats & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: mean_ms
  cdr << ros_message.mean_ms;
  // Member: p95_ms
  cdr << ros_message.p95_ms;
  // Member: p99_ms
  cdr << ros_message.p99_ms;
  // Member: max_ms
  cdr << ros_message.max_ms;
  // Member: sequence_gap_count
  cdr << ros_message.sequence_gap_count;
  // Member: stale_packet_count
  cdr << ros_message.stale_packet_count;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemetry_bridge
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  telemetry_bridge::msg::LatencyStats & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: mean_ms
  cdr >> ros_message.mean_ms;

  // Member: p95_ms
  cdr >> ros_message.p95_ms;

  // Member: p99_ms
  cdr >> ros_message.p99_ms;

  // Member: max_ms
  cdr >> ros_message.max_ms;

  // Member: sequence_gap_count
  cdr >> ros_message.sequence_gap_count;

  // Member: stale_packet_count
  cdr >> ros_message.stale_packet_count;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemetry_bridge
get_serialized_size(
  const telemetry_bridge::msg::LatencyStats & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: mean_ms
  {
    size_t item_size = sizeof(ros_message.mean_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p95_ms
  {
    size_t item_size = sizeof(ros_message.p95_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p99_ms
  {
    size_t item_size = sizeof(ros_message.p99_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_ms
  {
    size_t item_size = sizeof(ros_message.max_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sequence_gap_count
  {
    size_t item_size = sizeof(ros_message.sequence_gap_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: stale_packet_count
  {
    size_t item_size = sizeof(ros_message.stale_packet_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemetry_bridge
max_serialized_size_LatencyStats(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: mean_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p95_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p99_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: max_ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: sequence_gap_count
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: stale_packet_count
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _LatencyStats__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const telemetry_bridge::msg::LatencyStats *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LatencyStats__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<telemetry_bridge::msg::LatencyStats *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LatencyStats__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const telemetry_bridge::msg::LatencyStats *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LatencyStats__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_LatencyStats(full_bounded, 0);
}

static message_type_support_callbacks_t _LatencyStats__callbacks = {
  "telemetry_bridge::msg",
  "LatencyStats",
  _LatencyStats__cdr_serialize,
  _LatencyStats__cdr_deserialize,
  _LatencyStats__get_serialized_size,
  _LatencyStats__max_serialized_size
};

static rosidl_message_type_support_t _LatencyStats__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LatencyStats__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace telemetry_bridge

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_telemetry_bridge
const rosidl_message_type_support_t *
get_message_type_support_handle<telemetry_bridge::msg::LatencyStats>()
{
  return &telemetry_bridge::msg::typesupport_fastrtps_cpp::_LatencyStats__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, telemetry_bridge, msg, LatencyStats)() {
  return &telemetry_bridge::msg::typesupport_fastrtps_cpp::_LatencyStats__handle;
}

#ifdef __cplusplus
}
#endif
