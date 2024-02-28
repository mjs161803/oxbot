// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__TRAITS_HPP_
#define OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "oxbot_interfaces/msg/detail/hoverboard_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace oxbot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HoverboardCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: start_frame
  {
    out << "start_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.start_frame, out);
    out << ", ";
  }

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

  // member: xor_checksum
  {
    out << "xor_checksum: ";
    rosidl_generator_traits::value_to_yaml(msg.xor_checksum, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HoverboardCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.start_frame, out);
    out << "\n";
  }

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

  // member: xor_checksum
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xor_checksum: ";
    rosidl_generator_traits::value_to_yaml(msg.xor_checksum, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HoverboardCommand & msg, bool use_flow_style = false)
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
  const oxbot_interfaces::msg::HoverboardCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  oxbot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use oxbot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const oxbot_interfaces::msg::HoverboardCommand & msg)
{
  return oxbot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<oxbot_interfaces::msg::HoverboardCommand>()
{
  return "oxbot_interfaces::msg::HoverboardCommand";
}

template<>
inline const char * name<oxbot_interfaces::msg::HoverboardCommand>()
{
  return "oxbot_interfaces/msg/HoverboardCommand";
}

template<>
struct has_fixed_size<oxbot_interfaces::msg::HoverboardCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<oxbot_interfaces::msg::HoverboardCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<oxbot_interfaces::msg::HoverboardCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__TRAITS_HPP_
