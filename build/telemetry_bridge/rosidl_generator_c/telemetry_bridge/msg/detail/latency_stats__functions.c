// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from telemetry_bridge:msg/LatencyStats.idl
// generated code does not contain a copyright notice
#include "telemetry_bridge/msg/detail/latency_stats__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
telemetry_bridge__msg__LatencyStats__init(telemetry_bridge__msg__LatencyStats * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    telemetry_bridge__msg__LatencyStats__fini(msg);
    return false;
  }
  // mean_ms
  // p95_ms
  // p99_ms
  // max_ms
  // sequence_gap_count
  // stale_packet_count
  return true;
}

void
telemetry_bridge__msg__LatencyStats__fini(telemetry_bridge__msg__LatencyStats * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // mean_ms
  // p95_ms
  // p99_ms
  // max_ms
  // sequence_gap_count
  // stale_packet_count
}

bool
telemetry_bridge__msg__LatencyStats__are_equal(const telemetry_bridge__msg__LatencyStats * lhs, const telemetry_bridge__msg__LatencyStats * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // mean_ms
  if (lhs->mean_ms != rhs->mean_ms) {
    return false;
  }
  // p95_ms
  if (lhs->p95_ms != rhs->p95_ms) {
    return false;
  }
  // p99_ms
  if (lhs->p99_ms != rhs->p99_ms) {
    return false;
  }
  // max_ms
  if (lhs->max_ms != rhs->max_ms) {
    return false;
  }
  // sequence_gap_count
  if (lhs->sequence_gap_count != rhs->sequence_gap_count) {
    return false;
  }
  // stale_packet_count
  if (lhs->stale_packet_count != rhs->stale_packet_count) {
    return false;
  }
  return true;
}

bool
telemetry_bridge__msg__LatencyStats__copy(
  const telemetry_bridge__msg__LatencyStats * input,
  telemetry_bridge__msg__LatencyStats * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // mean_ms
  output->mean_ms = input->mean_ms;
  // p95_ms
  output->p95_ms = input->p95_ms;
  // p99_ms
  output->p99_ms = input->p99_ms;
  // max_ms
  output->max_ms = input->max_ms;
  // sequence_gap_count
  output->sequence_gap_count = input->sequence_gap_count;
  // stale_packet_count
  output->stale_packet_count = input->stale_packet_count;
  return true;
}

telemetry_bridge__msg__LatencyStats *
telemetry_bridge__msg__LatencyStats__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  telemetry_bridge__msg__LatencyStats * msg = (telemetry_bridge__msg__LatencyStats *)allocator.allocate(sizeof(telemetry_bridge__msg__LatencyStats), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(telemetry_bridge__msg__LatencyStats));
  bool success = telemetry_bridge__msg__LatencyStats__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
telemetry_bridge__msg__LatencyStats__destroy(telemetry_bridge__msg__LatencyStats * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    telemetry_bridge__msg__LatencyStats__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
telemetry_bridge__msg__LatencyStats__Sequence__init(telemetry_bridge__msg__LatencyStats__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  telemetry_bridge__msg__LatencyStats * data = NULL;

  if (size) {
    data = (telemetry_bridge__msg__LatencyStats *)allocator.zero_allocate(size, sizeof(telemetry_bridge__msg__LatencyStats), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = telemetry_bridge__msg__LatencyStats__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        telemetry_bridge__msg__LatencyStats__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
telemetry_bridge__msg__LatencyStats__Sequence__fini(telemetry_bridge__msg__LatencyStats__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      telemetry_bridge__msg__LatencyStats__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

telemetry_bridge__msg__LatencyStats__Sequence *
telemetry_bridge__msg__LatencyStats__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  telemetry_bridge__msg__LatencyStats__Sequence * array = (telemetry_bridge__msg__LatencyStats__Sequence *)allocator.allocate(sizeof(telemetry_bridge__msg__LatencyStats__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = telemetry_bridge__msg__LatencyStats__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
telemetry_bridge__msg__LatencyStats__Sequence__destroy(telemetry_bridge__msg__LatencyStats__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    telemetry_bridge__msg__LatencyStats__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
telemetry_bridge__msg__LatencyStats__Sequence__are_equal(const telemetry_bridge__msg__LatencyStats__Sequence * lhs, const telemetry_bridge__msg__LatencyStats__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!telemetry_bridge__msg__LatencyStats__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
telemetry_bridge__msg__LatencyStats__Sequence__copy(
  const telemetry_bridge__msg__LatencyStats__Sequence * input,
  telemetry_bridge__msg__LatencyStats__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(telemetry_bridge__msg__LatencyStats);
    telemetry_bridge__msg__LatencyStats * data =
      (telemetry_bridge__msg__LatencyStats *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!telemetry_bridge__msg__LatencyStats__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          telemetry_bridge__msg__LatencyStats__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!telemetry_bridge__msg__LatencyStats__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
