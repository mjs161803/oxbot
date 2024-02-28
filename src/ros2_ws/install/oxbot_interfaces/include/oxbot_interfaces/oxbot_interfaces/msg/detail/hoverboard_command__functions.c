// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
// generated code does not contain a copyright notice
#include "oxbot_interfaces/msg/detail/hoverboard_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
oxbot_interfaces__msg__HoverboardCommand__init(oxbot_interfaces__msg__HoverboardCommand * msg)
{
  if (!msg) {
    return false;
  }
  // start_frame
  // steer_or_brake
  // speed_or_throttle
  // xor_checksum
  return true;
}

void
oxbot_interfaces__msg__HoverboardCommand__fini(oxbot_interfaces__msg__HoverboardCommand * msg)
{
  if (!msg) {
    return;
  }
  // start_frame
  // steer_or_brake
  // speed_or_throttle
  // xor_checksum
}

bool
oxbot_interfaces__msg__HoverboardCommand__are_equal(const oxbot_interfaces__msg__HoverboardCommand * lhs, const oxbot_interfaces__msg__HoverboardCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start_frame
  if (lhs->start_frame != rhs->start_frame) {
    return false;
  }
  // steer_or_brake
  if (lhs->steer_or_brake != rhs->steer_or_brake) {
    return false;
  }
  // speed_or_throttle
  if (lhs->speed_or_throttle != rhs->speed_or_throttle) {
    return false;
  }
  // xor_checksum
  if (lhs->xor_checksum != rhs->xor_checksum) {
    return false;
  }
  return true;
}

bool
oxbot_interfaces__msg__HoverboardCommand__copy(
  const oxbot_interfaces__msg__HoverboardCommand * input,
  oxbot_interfaces__msg__HoverboardCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // start_frame
  output->start_frame = input->start_frame;
  // steer_or_brake
  output->steer_or_brake = input->steer_or_brake;
  // speed_or_throttle
  output->speed_or_throttle = input->speed_or_throttle;
  // xor_checksum
  output->xor_checksum = input->xor_checksum;
  return true;
}

oxbot_interfaces__msg__HoverboardCommand *
oxbot_interfaces__msg__HoverboardCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  oxbot_interfaces__msg__HoverboardCommand * msg = (oxbot_interfaces__msg__HoverboardCommand *)allocator.allocate(sizeof(oxbot_interfaces__msg__HoverboardCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(oxbot_interfaces__msg__HoverboardCommand));
  bool success = oxbot_interfaces__msg__HoverboardCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
oxbot_interfaces__msg__HoverboardCommand__destroy(oxbot_interfaces__msg__HoverboardCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    oxbot_interfaces__msg__HoverboardCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
oxbot_interfaces__msg__HoverboardCommand__Sequence__init(oxbot_interfaces__msg__HoverboardCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  oxbot_interfaces__msg__HoverboardCommand * data = NULL;

  if (size) {
    data = (oxbot_interfaces__msg__HoverboardCommand *)allocator.zero_allocate(size, sizeof(oxbot_interfaces__msg__HoverboardCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = oxbot_interfaces__msg__HoverboardCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        oxbot_interfaces__msg__HoverboardCommand__fini(&data[i - 1]);
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
oxbot_interfaces__msg__HoverboardCommand__Sequence__fini(oxbot_interfaces__msg__HoverboardCommand__Sequence * array)
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
      oxbot_interfaces__msg__HoverboardCommand__fini(&array->data[i]);
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

oxbot_interfaces__msg__HoverboardCommand__Sequence *
oxbot_interfaces__msg__HoverboardCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  oxbot_interfaces__msg__HoverboardCommand__Sequence * array = (oxbot_interfaces__msg__HoverboardCommand__Sequence *)allocator.allocate(sizeof(oxbot_interfaces__msg__HoverboardCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = oxbot_interfaces__msg__HoverboardCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
oxbot_interfaces__msg__HoverboardCommand__Sequence__destroy(oxbot_interfaces__msg__HoverboardCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    oxbot_interfaces__msg__HoverboardCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
oxbot_interfaces__msg__HoverboardCommand__Sequence__are_equal(const oxbot_interfaces__msg__HoverboardCommand__Sequence * lhs, const oxbot_interfaces__msg__HoverboardCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!oxbot_interfaces__msg__HoverboardCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
oxbot_interfaces__msg__HoverboardCommand__Sequence__copy(
  const oxbot_interfaces__msg__HoverboardCommand__Sequence * input,
  oxbot_interfaces__msg__HoverboardCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(oxbot_interfaces__msg__HoverboardCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    oxbot_interfaces__msg__HoverboardCommand * data =
      (oxbot_interfaces__msg__HoverboardCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!oxbot_interfaces__msg__HoverboardCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          oxbot_interfaces__msg__HoverboardCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!oxbot_interfaces__msg__HoverboardCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
