// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from oxbot_interfaces:msg/MotionControlOutput.idl
// generated code does not contain a copyright notice
#include "oxbot_interfaces/msg/detail/motion_control_output__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "oxbot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "oxbot_interfaces/msg/detail/motion_control_output__struct.h"
#include "oxbot_interfaces/msg/detail/motion_control_output__functions.h"
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

#include "oxbot_interfaces/msg/detail/hoverboard_feedback__functions.h"  // mc_output

// forward declare type support functions
size_t get_serialized_size_oxbot_interfaces__msg__HoverboardFeedback(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_oxbot_interfaces__msg__HoverboardFeedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, oxbot_interfaces, msg, HoverboardFeedback)();


using _MotionControlOutput__ros_msg_type = oxbot_interfaces__msg__MotionControlOutput;

static bool _MotionControlOutput__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MotionControlOutput__ros_msg_type * ros_message = static_cast<const _MotionControlOutput__ros_msg_type *>(untyped_ros_message);
  // Field name: mc_output
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, oxbot_interfaces, msg, HoverboardFeedback
      )()->data);
    size_t size = ros_message->mc_output.size;
    auto array_ptr = ros_message->mc_output.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _MotionControlOutput__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MotionControlOutput__ros_msg_type * ros_message = static_cast<_MotionControlOutput__ros_msg_type *>(untyped_ros_message);
  // Field name: mc_output
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, oxbot_interfaces, msg, HoverboardFeedback
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->mc_output.data) {
      oxbot_interfaces__msg__HoverboardFeedback__Sequence__fini(&ros_message->mc_output);
    }
    if (!oxbot_interfaces__msg__HoverboardFeedback__Sequence__init(&ros_message->mc_output, size)) {
      fprintf(stderr, "failed to create array for field 'mc_output'");
      return false;
    }
    auto array_ptr = ros_message->mc_output.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_oxbot_interfaces
size_t get_serialized_size_oxbot_interfaces__msg__MotionControlOutput(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MotionControlOutput__ros_msg_type * ros_message = static_cast<const _MotionControlOutput__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name mc_output
  {
    size_t array_size = ros_message->mc_output.size;
    auto array_ptr = ros_message->mc_output.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_oxbot_interfaces__msg__HoverboardFeedback(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MotionControlOutput__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_oxbot_interfaces__msg__MotionControlOutput(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_oxbot_interfaces
size_t max_serialized_size_oxbot_interfaces__msg__MotionControlOutput(
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

  // member: mc_output
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_oxbot_interfaces__msg__HoverboardFeedback(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _MotionControlOutput__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_oxbot_interfaces__msg__MotionControlOutput(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MotionControlOutput = {
  "oxbot_interfaces::msg",
  "MotionControlOutput",
  _MotionControlOutput__cdr_serialize,
  _MotionControlOutput__cdr_deserialize,
  _MotionControlOutput__get_serialized_size,
  _MotionControlOutput__max_serialized_size
};

static rosidl_message_type_support_t _MotionControlOutput__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MotionControlOutput,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, oxbot_interfaces, msg, MotionControlOutput)() {
  return &_MotionControlOutput__type_support;
}

#if defined(__cplusplus)
}
#endif
