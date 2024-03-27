// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from oxbot_interfaces:msg/MotionControlOutput.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__STRUCT_H_
#define OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mc_output'
#include "oxbot_interfaces/msg/detail/hoverboard_feedback__struct.h"

/// Struct defined in msg/MotionControlOutput in the package oxbot_interfaces.
typedef struct oxbot_interfaces__msg__MotionControlOutput
{
  oxbot_interfaces__msg__HoverboardFeedback__Sequence mc_output;
} oxbot_interfaces__msg__MotionControlOutput;

// Struct for a sequence of oxbot_interfaces__msg__MotionControlOutput.
typedef struct oxbot_interfaces__msg__MotionControlOutput__Sequence
{
  oxbot_interfaces__msg__MotionControlOutput * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} oxbot_interfaces__msg__MotionControlOutput__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__STRUCT_H_
