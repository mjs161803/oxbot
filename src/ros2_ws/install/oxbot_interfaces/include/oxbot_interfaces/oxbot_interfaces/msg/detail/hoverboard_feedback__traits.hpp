// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from oxbot_interfaces:msg/HoverboardFeedback.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__TRAITS_HPP_
#define OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "oxbot_interfaces/msg/detail/hoverboard_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace oxbot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HoverboardFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: steer_or_brake
  {
    out << "steer_or_brake: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_or_brake, out);
    out << ", ";
  }

  // member: speed_or_throttle
  {
    out << "speed_or_throttle: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_or_throttle, out);
    out << ", ";
  }

  // member: right_wheel_rpm
  {
    out << "right_wheel_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.right_wheel_rpm, out);
    out << ", ";
  }

  // member: left_wheel_rpm
  {
    out << "left_wheel_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.left_wheel_rpm, out);
    out << ", ";
  }

  // member: batt_voltage_x100
  {
    out << "batt_voltage_x100: ";
    rosidl_generator_traits::value_to_yaml(msg.batt_voltage_x100, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: led
  {
    out << "led: ";
    rosidl_generator_traits::value_to_yaml(msg.led, out);
    out << ", ";
  }

  // member: timestamp_ns
  {
    out << "timestamp_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_ns, out);
    out << ", ";
  }

  // member: front_or_back
  {
    out << "front_or_back: ";
    rosidl_generator_traits::value_to_yaml(msg.front_or_back, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HoverboardFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: steer_or_brake
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steer_or_brake: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_or_brake, out);
    out << "\n";
  }

  // member: speed_or_throttle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_or_throttle: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_or_throttle, out);
    out << "\n";
  }

  // member: right_wheel_rpm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_wheel_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.right_wheel_rpm, out);
    out << "\n";
  }

  // member: left_wheel_rpm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_wheel_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.left_wheel_rpm, out);
    out << "\n";
  }

  // member: batt_voltage_x100
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "batt_voltage_x100: ";
    rosidl_generator_traits::value_to_yaml(msg.batt_voltage_x100, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: led
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "led: ";
    rosidl_generator_traits::value_to_yaml(msg.led, out);
    out << "\n";
  }

  // member: timestamp_ns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_ns, out);
    out << "\n";
  }

  // member: front_or_back
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_or_back: ";
    rosidl_generator_traits::value_to_yaml(msg.front_or_back, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HoverboardFeedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace oxbot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use oxbot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const oxbot_interfaces::msg::HoverboardFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  oxbot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use oxbot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const oxbot_interfaces::msg::HoverboardFeedback & msg)
{
  return oxbot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<oxbot_interfaces::msg::HoverboardFeedback>()
{
  return "oxbot_interfaces::msg::HoverboardFeedback";
}

template<>
inline const char * name<oxbot_interfaces::msg::HoverboardFeedback>()
{
  return "oxbot_interfaces/msg/HoverboardFeedback";
}

template<>
struct has_fixed_size<oxbot_interfaces::msg::HoverboardFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<oxbot_interfaces::msg::HoverboardFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<oxbot_interfaces::msg::HoverboardFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__TRAITS_HPP_
