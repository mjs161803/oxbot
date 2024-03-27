// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from oxbot_interfaces:msg/HoverboardFeedback.idl
// generated code does not contain a copyright notice
#include "oxbot_interfaces/msg/detail/hoverboard_feedback__rosidl_typesupport_fastrtps_cpp.hpp"
#include "oxbot_interfaces/msg/detail/hoverboard_feedback__struct.hpp"

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
  const oxbot_interfaces::msg::HoverboardFeedback & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: steer_or_brake
  cdr << ros_message.steer_or_brake;
  // Member: speed_or_throttle
  cdr << ros_message.speed_or_throttle;
  // Member: right_wheel_rpm
  cdr << ros_message.right_wheel_rpm;
  // Member: left_wheel_rpm
  cdr << ros_message.left_wheel_rpm;
  // Member: batt_voltage_x100
  cdr << ros_message.batt_voltage_x100;
  // Member: temperature
  cdr << ros_message.temperature;
  // Member: led
  cdr << ros_message.led;
  // Member: timestamp_ns
  cdr << ros_message.timestamp_ns;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_oxbot_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  oxbot_interfaces::msg::HoverboardFeedback & ros_message)
{
  // Member: steer_or_brake
  cdr >> ros_message.steer_or_brake;

  // Member: speed_or_throttle
  cdr >> ros_message.speed_or_throttle;

  // Member: right_wheel_rpm
  cdr >> ros_message.right_wheel_rpm;

  // Member: left_wheel_rpm
  cdr >> ros_message.left_wheel_rpm;

  // Member: batt_voltage_x100
  cdr >> ros_message.batt_voltage_x100;

  // Member: temperature
  cdr >> ros_message.temperature;

  // Member: led
  cdr >> ros_message.led;

  // Member: timestamp_ns
  cdr >> ros_message.timestamp_ns;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_oxbot_interfaces
get_serialized_size(
  const oxbot_interfaces::msg::HoverboardFeedback & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

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
  // Member: right_wheel_rpm
  {
    size_t item_size = sizeof(ros_message.right_wheel_rpm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_wheel_rpm
  {
    size_t item_size = sizeof(ros_message.left_wheel_rpm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: batt_voltage_x100
  {
    size_t item_size = sizeof(ros_message.batt_voltage_x100);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temperature
  {
    size_t item_size = sizeof(ros_message.temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: led
  {
    size_t item_size = sizeof(ros_message.led);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: timestamp_ns
  {
    size_t item_size = sizeof(ros_message.timestamp_ns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_oxbot_interfaces
max_serialized_size_HoverboardFeedback(
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

  // Member: right_wheel_rpm
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: left_wheel_rpm
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: batt_voltage_x100
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: temperature
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: led
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: timestamp_ns
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _HoverboardFeedback__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const oxbot_interfaces::msg::HoverboardFeedback *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HoverboardFeedback__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<oxbot_interfaces::msg::HoverboardFeedback *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HoverboardFeedback__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const oxbot_interfaces::msg::HoverboardFeedback *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HoverboardFeedback__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_HoverboardFeedback(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _HoverboardFeedback__callbacks = {
  "oxbot_interfaces::msg",
  "HoverboardFeedback",
  _HoverboardFeedback__cdr_serialize,
  _HoverboardFeedback__cdr_deserialize,
  _HoverboardFeedback__get_serialized_size,
  _HoverboardFeedback__max_serialized_size
};

static rosidl_message_type_support_t _HoverboardFeedback__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HoverboardFeedback__callbacks,
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
get_message_type_support_handle<oxbot_interfaces::msg::HoverboardFeedback>()
{
  return &oxbot_interfaces::msg::typesupport_fastrtps_cpp::_HoverboardFeedback__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, oxbot_interfaces, msg, HoverboardFeedback)() {
  return &oxbot_interfaces::msg::typesupport_fastrtps_cpp::_HoverboardFeedback__handle;
}

#ifdef __cplusplus
}
#endif
