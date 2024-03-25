// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from oxbot_interfaces:msg/MotionControlOutput.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__TRAITS_HPP_
#define OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "oxbot_interfaces/msg/detail/motion_control_output__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'mc_output'
#include "oxbot_interfaces/msg/detail/hoverboard_feedback__traits.hpp"

namespace oxbot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotionControlOutput & msg,
  std::ostream & out)
{
  out << "{";
  // member: mc_output
  {
    if (msg.mc_output.size() == 0) {
      out << "mc_output: []";
    } else {
      out << "mc_output: [";
      size_t pending_items = msg.mc_output.size();
      for (auto item : msg.mc_output) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotionControlOutput & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mc_output
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.mc_output.size() == 0) {
      out << "mc_output: []\n";
    } else {
      out << "mc_output:\n";
      for (auto item : msg.mc_output) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotionControlOutput & msg, bool use_flow_style = false)
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
  const oxbot_interfaces::msg::MotionControlOutput & msg,
  std::ostream & out, size_t indentation = 0)
{
  oxbot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use oxbot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const oxbot_interfaces::msg::MotionControlOutput & msg)
{
  return oxbot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<oxbot_interfaces::msg::MotionControlOutput>()
{
  return "oxbot_interfaces::msg::MotionControlOutput";
}

template<>
inline const char * name<oxbot_interfaces::msg::MotionControlOutput>()
{
  return "oxbot_interfaces/msg/MotionControlOutput";
}

template<>
struct has_fixed_size<oxbot_interfaces::msg::MotionControlOutput>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<oxbot_interfaces::msg::MotionControlOutput>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<oxbot_interfaces::msg::MotionControlOutput>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__TRAITS_HPP_
