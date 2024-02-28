// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__STRUCT_H_
#define OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/HoverboardCommand in the package oxbot_interfaces.
typedef struct oxbot_interfaces__msg__HoverboardCommand
{
  uint16_t start_frame;
  int16_t steer_or_brake;
  int16_t speed_or_throttle;
  uint16_t xor_checksum;
} oxbot_interfaces__msg__HoverboardCommand;

// Struct for a sequence of oxbot_interfaces__msg__HoverboardCommand.
typedef struct oxbot_interfaces__msg__HoverboardCommand__Sequence
{
  oxbot_interfaces__msg__HoverboardCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} oxbot_interfaces__msg__HoverboardCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__STRUCT_H_
