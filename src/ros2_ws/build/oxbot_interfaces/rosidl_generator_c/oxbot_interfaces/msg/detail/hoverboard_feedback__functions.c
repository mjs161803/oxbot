// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from oxbot_interfaces:msg/HoverboardFeedback.idl
// generated code does not contain a copyright notice
#include "oxbot_interfaces/msg/detail/hoverboard_feedback__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
oxbot_interfaces__msg__HoverboardFeedback__init(oxbot_interfaces__msg__HoverboardFeedback * msg)
{
  if (!msg) {
    return false;
  }
  // steer_or_brake
  // speed_or_throttle
  // right_wheel_rpm
  // left_wheel_rpm
  // batt_voltage_x100
  // temperature
  // led
  return true;
}

void
oxbot_interfaces__msg__HoverboardFeedback__fini(oxbot_interfaces__msg__HoverboardFeedback * msg)
{
  if (!msg) {
    return;
  }
  // steer_or_brake
  // speed_or_throttle
  // right_wheel_rpm
  // left_wheel_rpm
  // batt_voltage_x100
  // temperature
  // led
}

bool
oxbot_interfaces__msg__HoverboardFeedback__are_equal(const oxbot_interfaces__msg__HoverboardFeedback * lhs, const oxbot_interfaces__msg__HoverboardFeedback * rhs)
{
  if (!lhs || !rhs) {
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
  // right_wheel_rpm
  if (lhs->right_wheel_rpm != rhs->right_wheel_rpm) {
    return false;
  }
  // left_wheel_rpm
  if (lhs->left_wheel_rpm != rhs->left_wheel_rpm) {
    return false;
  }
  // batt_voltage_x100
  if (lhs->batt_voltage_x100 != rhs->batt_voltage_x100) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // led
  if (lhs->led != rhs->led) {
    return false;
  }
  return true;
}

bool
oxbot_interfaces__msg__HoverboardFeedback__copy(
  const oxbot_interfaces__msg__HoverboardFeedback * input,
  oxbot_interfaces__msg__HoverboardFeedback * output)
{
  if (!input || !output) {
    return false;
  }
  // steer_or_brake
  output->steer_or_brake = input->steer_or_brake;
  // speed_or_throttle
  output->speed_or_throttle = input->speed_or_throttle;
  // right_wheel_rpm
  output->right_wheel_rpm = input->right_wheel_rpm;
  // left_wheel_rpm
  output->left_wheel_rpm = input->left_wheel_rpm;
  // batt_voltage_x100
  output->batt_voltage_x100 = input->batt_voltage_x100;
  // temperature
  output->temperature = input->temperature;
  // led
  output->led = input->led;
  return true;
}

oxbot_interfaces__msg__HoverboardFeedback *
oxbot_interfaces__msg__HoverboardFeedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  oxbot_interfaces__msg__HoverboardFeedback * msg = (oxbot_interfaces__msg__HoverboardFeedback *)allocator.allocate(sizeof(oxbot_interfaces__msg__HoverboardFeedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(oxbot_interfaces__msg__HoverboardFeedback));
  bool success = oxbot_interfaces__msg__HoverboardFeedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
oxbot_interfaces__msg__HoverboardFeedback__destroy(oxbot_interfaces__msg__HoverboardFeedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    oxbot_interfaces__msg__HoverboardFeedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
oxbot_interfaces__msg__HoverboardFeedback__Sequence__init(oxbot_interfaces__msg__HoverboardFeedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  oxbot_interfaces__msg__HoverboardFeedback * data = NULL;

  if (size) {
    data = (oxbot_interfaces__msg__HoverboardFeedback *)allocator.zero_allocate(size, sizeof(oxbot_interfaces__msg__HoverboardFeedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = oxbot_interfaces__msg__HoverboardFeedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        oxbot_interfaces__msg__HoverboardFeedback__fini(&data[i - 1]);
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
oxbot_interfaces__msg__HoverboardFeedback__Sequence__fini(oxbot_interfaces__msg__HoverboardFeedback__Sequence * array)
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
      oxbot_interfaces__msg__HoverboardFeedback__fini(&array->data[i]);
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

oxbot_interfaces__msg__HoverboardFeedback__Sequence *
oxbot_interfaces__msg__HoverboardFeedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  oxbot_interfaces__msg__HoverboardFeedback__Sequence * array = (oxbot_interfaces__msg__HoverboardFeedback__Sequence *)allocator.allocate(sizeof(oxbot_interfaces__msg__HoverboardFeedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = oxbot_interfaces__msg__HoverboardFeedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
oxbot_interfaces__msg__HoverboardFeedback__Sequence__destroy(oxbot_interfaces__msg__HoverboardFeedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    oxbot_interfaces__msg__HoverboardFeedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
oxbot_interfaces__msg__HoverboardFeedback__Sequence__are_equal(const oxbot_interfaces__msg__HoverboardFeedback__Sequence * lhs, const oxbot_interfaces__msg__HoverboardFeedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!oxbot_interfaces__msg__HoverboardFeedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
oxbot_interfaces__msg__HoverboardFeedback__Sequence__copy(
  const oxbot_interfaces__msg__HoverboardFeedback__Sequence * input,
  oxbot_interfaces__msg__HoverboardFeedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(oxbot_interfaces__msg__HoverboardFeedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    oxbot_interfaces__msg__HoverboardFeedback * data =
      (oxbot_interfaces__msg__HoverboardFeedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!oxbot_interfaces__msg__HoverboardFeedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          oxbot_interfaces__msg__HoverboardFeedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!oxbot_interfaces__msg__HoverboardFeedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
