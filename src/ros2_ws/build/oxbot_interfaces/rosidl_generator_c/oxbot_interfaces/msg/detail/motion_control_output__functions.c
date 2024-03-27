// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from oxbot_interfaces:msg/MotionControlOutput.idl
// generated code does not contain a copyright notice
#include "oxbot_interfaces/msg/detail/motion_control_output__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `mc_output`
#include "oxbot_interfaces/msg/detail/hoverboard_feedback__functions.h"

bool
oxbot_interfaces__msg__MotionControlOutput__init(oxbot_interfaces__msg__MotionControlOutput * msg)
{
  if (!msg) {
    return false;
  }
  // mc_output
  if (!oxbot_interfaces__msg__HoverboardFeedback__Sequence__init(&msg->mc_output, 0)) {
    oxbot_interfaces__msg__MotionControlOutput__fini(msg);
    return false;
  }
  return true;
}

void
oxbot_interfaces__msg__MotionControlOutput__fini(oxbot_interfaces__msg__MotionControlOutput * msg)
{
  if (!msg) {
    return;
  }
  // mc_output
  oxbot_interfaces__msg__HoverboardFeedback__Sequence__fini(&msg->mc_output);
}

bool
oxbot_interfaces__msg__MotionControlOutput__are_equal(const oxbot_interfaces__msg__MotionControlOutput * lhs, const oxbot_interfaces__msg__MotionControlOutput * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mc_output
  if (!oxbot_interfaces__msg__HoverboardFeedback__Sequence__are_equal(
      &(lhs->mc_output), &(rhs->mc_output)))
  {
    return false;
  }
  return true;
}

bool
oxbot_interfaces__msg__MotionControlOutput__copy(
  const oxbot_interfaces__msg__MotionControlOutput * input,
  oxbot_interfaces__msg__MotionControlOutput * output)
{
  if (!input || !output) {
    return false;
  }
  // mc_output
  if (!oxbot_interfaces__msg__HoverboardFeedback__Sequence__copy(
      &(input->mc_output), &(output->mc_output)))
  {
    return false;
  }
  return true;
}

oxbot_interfaces__msg__MotionControlOutput *
oxbot_interfaces__msg__MotionControlOutput__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  oxbot_interfaces__msg__MotionControlOutput * msg = (oxbot_interfaces__msg__MotionControlOutput *)allocator.allocate(sizeof(oxbot_interfaces__msg__MotionControlOutput), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(oxbot_interfaces__msg__MotionControlOutput));
  bool success = oxbot_interfaces__msg__MotionControlOutput__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
oxbot_interfaces__msg__MotionControlOutput__destroy(oxbot_interfaces__msg__MotionControlOutput * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    oxbot_interfaces__msg__MotionControlOutput__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
oxbot_interfaces__msg__MotionControlOutput__Sequence__init(oxbot_interfaces__msg__MotionControlOutput__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  oxbot_interfaces__msg__MotionControlOutput * data = NULL;

  if (size) {
    data = (oxbot_interfaces__msg__MotionControlOutput *)allocator.zero_allocate(size, sizeof(oxbot_interfaces__msg__MotionControlOutput), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = oxbot_interfaces__msg__MotionControlOutput__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        oxbot_interfaces__msg__MotionControlOutput__fini(&data[i - 1]);
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
oxbot_interfaces__msg__MotionControlOutput__Sequence__fini(oxbot_interfaces__msg__MotionControlOutput__Sequence * array)
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
      oxbot_interfaces__msg__MotionControlOutput__fini(&array->data[i]);
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

oxbot_interfaces__msg__MotionControlOutput__Sequence *
oxbot_interfaces__msg__MotionControlOutput__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  oxbot_interfaces__msg__MotionControlOutput__Sequence * array = (oxbot_interfaces__msg__MotionControlOutput__Sequence *)allocator.allocate(sizeof(oxbot_interfaces__msg__MotionControlOutput__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = oxbot_interfaces__msg__MotionControlOutput__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
oxbot_interfaces__msg__MotionControlOutput__Sequence__destroy(oxbot_interfaces__msg__MotionControlOutput__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    oxbot_interfaces__msg__MotionControlOutput__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
oxbot_interfaces__msg__MotionControlOutput__Sequence__are_equal(const oxbot_interfaces__msg__MotionControlOutput__Sequence * lhs, const oxbot_interfaces__msg__MotionControlOutput__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!oxbot_interfaces__msg__MotionControlOutput__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
oxbot_interfaces__msg__MotionControlOutput__Sequence__copy(
  const oxbot_interfaces__msg__MotionControlOutput__Sequence * input,
  oxbot_interfaces__msg__MotionControlOutput__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(oxbot_interfaces__msg__MotionControlOutput);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    oxbot_interfaces__msg__MotionControlOutput * data =
      (oxbot_interfaces__msg__MotionControlOutput *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!oxbot_interfaces__msg__MotionControlOutput__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          oxbot_interfaces__msg__MotionControlOutput__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!oxbot_interfaces__msg__MotionControlOutput__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
