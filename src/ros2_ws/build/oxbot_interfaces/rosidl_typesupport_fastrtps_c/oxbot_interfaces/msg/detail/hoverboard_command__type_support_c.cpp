// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
// generated code does not contain a copyright notice
#include "oxbot_interfaces/msg/detail/hoverboard_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "oxbot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "oxbot_interfaces/msg/detail/hoverboard_command__struct.h"
#include "oxbot_interfaces/msg/detail/hoverboard_command__functions.h"
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


// forward declare type support functions


using _HoverboardCommand__ros_msg_type = oxbot_interfaces__msg__HoverboardCommand;

static bool _HoverboardCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HoverboardCommand__ros_msg_type * ros_message = static_cast<const _HoverboardCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: start_frame
  {
    cdr << ros_message->start_frame;
  }

  // Field name: steer_or_brake
  {
    cdr << ros_message->steer_or_brake;
  }

  // Field name: speed_or_throttle
  {
    cdr << ros_message->speed_or_throttle;
  }

  // Field name: xor_checksum
  {
    cdr << ros_message->xor_checksum;
  }

  return true;
}

static bool _HoverboardCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HoverboardCommand__ros_msg_type * ros_message = static_cast<_HoverboardCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: start_frame
  {
    cdr >> ros_message->start_frame;
  }

  // Field name: steer_or_brake
  {
    cdr >> ros_message->steer_or_brake;
  }

  // Field name: speed_or_throttle
  {
    cdr >> ros_message->speed_or_throttle;
  }

  // Field name: xor_checksum
  {
    cdr >> ros_message->xor_checksum;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_oxbot_interfaces
size_t get_serialized_size_oxbot_interfaces__msg__HoverboardCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HoverboardCommand__ros_msg_type * ros_message = static_cast<const _HoverboardCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name start_frame
  {
    size_t item_size = sizeof(ros_message->start_frame);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name steer_or_brake
  {
    size_t item_size = sizeof(ros_message->steer_or_brake);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed_or_throttle
  {
    size_t item_size = sizeof(ros_message->speed_or_throttle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name xor_checksum
  {
    size_t item_size = sizeof(ros_message->xor_checksum);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HoverboardCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_oxbot_interfaces__msg__HoverboardCommand(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_oxbot_interfaces
size_t max_serialized_size_oxbot_interfaces__msg__HoverboardCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: start_frame
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: steer_or_brake
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: speed_or_throttle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: xor_checksum
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _HoverboardCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_oxbot_interfaces__msg__HoverboardCommand(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_HoverboardCommand = {
  "oxbot_interfaces::msg",
  "HoverboardCommand",
  _HoverboardCommand__cdr_serialize,
  _HoverboardCommand__cdr_deserialize,
  _HoverboardCommand__get_serialized_size,
  _HoverboardCommand__max_serialized_size
};

static rosidl_message_type_support_t _HoverboardCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HoverboardCommand,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, oxbot_interfaces, msg, HoverboardCommand)() {
  return &_HoverboardCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
