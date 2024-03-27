// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
// generated code does not contain a copyright notice
#include "oxbot_interfaces/msg/detail/hoverboard_command__rosidl_typesupport_fastrtps_cpp.hpp"
#include "oxbot_interfaces/msg/detail/hoverboard_command__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace oxbot_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_oxbot_interfaces
cdr_serialize(
  const oxbot_interfaces::msg::HoverboardCommand & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: start_frame
  cdr << ros_message.start_frame;
  // Member: steer_or_brake
  cdr << ros_message.steer_or_brake;
  // Member: speed_or_throttle
  cdr << ros_message.speed_or_throttle;
  // Member: xor_checksum
  cdr << ros_message.xor_checksum;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_oxbot_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  oxbot_interfaces::msg::HoverboardCommand & ros_message)
{
  // Member: start_frame
  cdr >> ros_message.start_frame;

  // Member: steer_or_brake
  cdr >> ros_message.steer_or_brake;

  // Member: speed_or_throttle
  cdr >> ros_message.speed_or_throttle;

  // Member: xor_checksum
  cdr >> ros_message.xor_checksum;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_oxbot_interfaces
get_serialized_size(
  const oxbot_interfaces::msg::HoverboardCommand & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: start_frame
  {
    size_t item_size = sizeof(ros_message.start_frame);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: steer_or_brake
  {
    size_t item_size = sizeof(ros_message.steer_or_brake);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: speed_or_throttle
  {
    size_t item_size = sizeof(ros_message.speed_or_throttle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: xor_checksum
  {
    size_t item_size = sizeof(ros_message.xor_checksum);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_oxbot_interfaces
max_serialized_size_HoverboardCommand(
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


  // Member: start_frame
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: steer_or_brake
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: speed_or_throttle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: xor_checksum
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static bool _HoverboardCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const oxbot_interfaces::msg::HoverboardCommand *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HoverboardCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<oxbot_interfaces::msg::HoverboardCommand *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HoverboardCommand__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const oxbot_interfaces::msg::HoverboardCommand *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HoverboardCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_HoverboardCommand(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _HoverboardCommand__callbacks = {
  "oxbot_interfaces::msg",
  "HoverboardCommand",
  _HoverboardCommand__cdr_serialize,
  _HoverboardCommand__cdr_deserialize,
  _HoverboardCommand__get_serialized_size,
  _HoverboardCommand__max_serialized_size
};

static rosidl_message_type_support_t _HoverboardCommand__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HoverboardCommand__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace oxbot_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_oxbot_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<oxbot_interfaces::msg::HoverboardCommand>()
{
  return &oxbot_interfaces::msg::typesupport_fastrtps_cpp::_HoverboardCommand__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, oxbot_interfaces, msg, HoverboardCommand)() {
  return &oxbot_interfaces::msg::typesupport_fastrtps_cpp::_HoverboardCommand__handle;
}

#ifdef __cplusplus
}
#endif
