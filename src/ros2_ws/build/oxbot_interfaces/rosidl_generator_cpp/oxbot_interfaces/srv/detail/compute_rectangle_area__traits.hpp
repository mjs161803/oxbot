// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from oxbot_interfaces:srv/ComputeRectangleArea.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__SRV__DETAIL__COMPUTE_RECTANGLE_AREA__TRAITS_HPP_
#define OXBOT_INTERFACES__SRV__DETAIL__COMPUTE_RECTANGLE_AREA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "oxbot_interfaces/srv/detail/compute_rectangle_area__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace oxbot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeRectangleArea_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: length
  {
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeRectangleArea_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeRectangleArea_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace oxbot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use oxbot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const oxbot_interfaces::srv::ComputeRectangleArea_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  oxbot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use oxbot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const oxbot_interfaces::srv::ComputeRectangleArea_Request & msg)
{
  return oxbot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<oxbot_interfaces::srv::ComputeRectangleArea_Request>()
{
  return "oxbot_interfaces::srv::ComputeRectangleArea_Request";
}

template<>
inline const char * name<oxbot_interfaces::srv::ComputeRectangleArea_Request>()
{
  return "oxbot_interfaces/srv/ComputeRectangleArea_Request";
}

template<>
struct has_fixed_size<oxbot_interfaces::srv::ComputeRectangleArea_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<oxbot_interfaces::srv::ComputeRectangleArea_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<oxbot_interfaces::srv::ComputeRectangleArea_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace oxbot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeRectangleArea_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: area
  {
    out << "area: ";
    rosidl_generator_traits::value_to_yaml(msg.area, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeRectangleArea_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: area
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "area: ";
    rosidl_generator_traits::value_to_yaml(msg.area, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeRectangleArea_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace oxbot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use oxbot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const oxbot_interfaces::srv::ComputeRectangleArea_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  oxbot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use oxbot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const oxbot_interfaces::srv::ComputeRectangleArea_Response & msg)
{
  return oxbot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<oxbot_interfaces::srv::ComputeRectangleArea_Response>()
{
  return "oxbot_interfaces::srv::ComputeRectangleArea_Response";
}

template<>
inline const char * name<oxbot_interfaces::srv::ComputeRectangleArea_Response>()
{
  return "oxbot_interfaces/srv/ComputeRectangleArea_Response";
}

template<>
struct has_fixed_size<oxbot_interfaces::srv::ComputeRectangleArea_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<oxbot_interfaces::srv::ComputeRectangleArea_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<oxbot_interfaces::srv::ComputeRectangleArea_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<oxbot_interfaces::srv::ComputeRectangleArea>()
{
  return "oxbot_interfaces::srv::ComputeRectangleArea";
}

template<>
inline const char * name<oxbot_interfaces::srv::ComputeRectangleArea>()
{
  return "oxbot_interfaces/srv/ComputeRectangleArea";
}

template<>
struct has_fixed_size<oxbot_interfaces::srv::ComputeRectangleArea>
  : std::integral_constant<
    bool,
    has_fixed_size<oxbot_interfaces::srv::ComputeRectangleArea_Request>::value &&
    has_fixed_size<oxbot_interfaces::srv::ComputeRectangleArea_Response>::value
  >
{
};

template<>
struct has_bounded_size<oxbot_interfaces::srv::ComputeRectangleArea>
  : std::integral_constant<
    bool,
    has_bounded_size<oxbot_interfaces::srv::ComputeRectangleArea_Request>::value &&
    has_bounded_size<oxbot_interfaces::srv::ComputeRectangleArea_Response>::value
  >
{
};

template<>
struct is_service<oxbot_interfaces::srv::ComputeRectangleArea>
  : std::true_type
{
};

template<>
struct is_service_request<oxbot_interfaces::srv::ComputeRectangleArea_Request>
  : std::true_type
{
};

template<>
struct is_service_response<oxbot_interfaces::srv::ComputeRectangleArea_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // OXBOT_INTERFACES__SRV__DETAIL__COMPUTE_RECTANGLE_AREA__TRAITS_HPP_
