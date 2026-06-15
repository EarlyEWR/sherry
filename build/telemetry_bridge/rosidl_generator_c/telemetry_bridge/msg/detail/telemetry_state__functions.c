// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from telemetry_bridge:msg/TelemetryState.idl
// generated code does not contain a copyright notice
#include "telemetry_bridge/msg/detail/telemetry_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
telemetry_bridge__msg__TelemetryState__init(telemetry_bridge__msg__TelemetryState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    telemetry_bridge__msg__TelemetryState__fini(msg);
    return false;
  }
  // x
  // y
  // z
  // vx
  // vy
  // vz
  // sequence_id
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    telemetry_bridge__msg__TelemetryState__fini(msg);
    return false;
  }
  return true;
}

void
telemetry_bridge__msg__TelemetryState__fini(telemetry_bridge__msg__TelemetryState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // x
  // y
  // z
  // vx
  // vy
  // vz
  // sequence_id
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
}

bool
telemetry_bridge__msg__TelemetryState__are_equal(const telemetry_bridge__msg__TelemetryState * lhs, const telemetry_bridge__msg__TelemetryState * rhs)
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
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // vz
  if (lhs->vz != rhs->vz) {
    return false;
  }
  // sequence_id
  if (lhs->sequence_id != rhs->sequence_id) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
telemetry_bridge__msg__TelemetryState__copy(
  const telemetry_bridge__msg__TelemetryState * input,
  telemetry_bridge__msg__TelemetryState * output)
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
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // vx
  output->vx = input->vx;
  // vy
  output->vy = input->vy;
  // vz
  output->vz = input->vz;
  // sequence_id
  output->sequence_id = input->sequence_id;
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

telemetry_bridge__msg__TelemetryState *
telemetry_bridge__msg__TelemetryState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  telemetry_bridge__msg__TelemetryState * msg = (telemetry_bridge__msg__TelemetryState *)allocator.allocate(sizeof(telemetry_bridge__msg__TelemetryState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(telemetry_bridge__msg__TelemetryState));
  bool success = telemetry_bridge__msg__TelemetryState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
telemetry_bridge__msg__TelemetryState__destroy(telemetry_bridge__msg__TelemetryState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    telemetry_bridge__msg__TelemetryState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
telemetry_bridge__msg__TelemetryState__Sequence__init(telemetry_bridge__msg__TelemetryState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  telemetry_bridge__msg__TelemetryState * data = NULL;

  if (size) {
    data = (telemetry_bridge__msg__TelemetryState *)allocator.zero_allocate(size, sizeof(telemetry_bridge__msg__TelemetryState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = telemetry_bridge__msg__TelemetryState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        telemetry_bridge__msg__TelemetryState__fini(&data[i - 1]);
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
telemetry_bridge__msg__TelemetryState__Sequence__fini(telemetry_bridge__msg__TelemetryState__Sequence * array)
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
      telemetry_bridge__msg__TelemetryState__fini(&array->data[i]);
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

telemetry_bridge__msg__TelemetryState__Sequence *
telemetry_bridge__msg__TelemetryState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  telemetry_bridge__msg__TelemetryState__Sequence * array = (telemetry_bridge__msg__TelemetryState__Sequence *)allocator.allocate(sizeof(telemetry_bridge__msg__TelemetryState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = telemetry_bridge__msg__TelemetryState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
telemetry_bridge__msg__TelemetryState__Sequence__destroy(telemetry_bridge__msg__TelemetryState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    telemetry_bridge__msg__TelemetryState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
telemetry_bridge__msg__TelemetryState__Sequence__are_equal(const telemetry_bridge__msg__TelemetryState__Sequence * lhs, const telemetry_bridge__msg__TelemetryState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!telemetry_bridge__msg__TelemetryState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
telemetry_bridge__msg__TelemetryState__Sequence__copy(
  const telemetry_bridge__msg__TelemetryState__Sequence * input,
  telemetry_bridge__msg__TelemetryState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(telemetry_bridge__msg__TelemetryState);
    telemetry_bridge__msg__TelemetryState * data =
      (telemetry_bridge__msg__TelemetryState *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!telemetry_bridge__msg__TelemetryState__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          telemetry_bridge__msg__TelemetryState__fini(&data[i]);
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
    if (!telemetry_bridge__msg__TelemetryState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
