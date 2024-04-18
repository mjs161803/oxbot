// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from oxbot_interfaces:msg/HoverboardFeedback.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__STRUCT_H_
#define OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'front_or_back'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/HoverboardFeedback in the package oxbot_interfaces.
typedef struct oxbot_interfaces__msg__HoverboardFeedback
{
  int16_t steer_or_brake;
  int16_t speed_or_throttle;
  int16_t right_wheel_rpm;
  int16_t left_wheel_rpm;
  int16_t batt_voltage_x100;
  int16_t temperature;
  uint16_t led;
  uint64_t timestamp_ns;
  rosidl_runtime_c__String front_or_back;
} oxbot_interfaces__msg__HoverboardFeedback;

// Struct for a sequence of oxbot_interfaces__msg__HoverboardFeedback.
typedef struct oxbot_interfaces__msg__HoverboardFeedback__Sequence
{
  oxbot_interfaces__msg__HoverboardFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} oxbot_interfaces__msg__HoverboardFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__STRUCT_H_
