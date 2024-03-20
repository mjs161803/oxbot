// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from oxbot_interfaces:srv/ComputeRectangleArea.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__SRV__DETAIL__COMPUTE_RECTANGLE_AREA__BUILDER_HPP_
#define OXBOT_INTERFACES__SRV__DETAIL__COMPUTE_RECTANGLE_AREA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "oxbot_interfaces/srv/detail/compute_rectangle_area__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace oxbot_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeRectangleArea_Request_width
{
public:
  explicit Init_ComputeRectangleArea_Request_width(::oxbot_interfaces::srv::ComputeRectangleArea_Request & msg)
  : msg_(msg)
  {}
  ::oxbot_interfaces::srv::ComputeRectangleArea_Request width(::oxbot_interfaces::srv::ComputeRectangleArea_Request::_width_type arg)
  {
    msg_.width = std::move(arg);
    return std::move(msg_);
  }

private:
  ::oxbot_interfaces::srv::ComputeRectangleArea_Request msg_;
};

class Init_ComputeRectangleArea_Request_length
{
public:
  Init_ComputeRectangleArea_Request_length()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeRectangleArea_Request_width length(::oxbot_interfaces::srv::ComputeRectangleArea_Request::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_ComputeRectangleArea_Request_width(msg_);
  }

private:
  ::oxbot_interfaces::srv::ComputeRectangleArea_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::oxbot_interfaces::srv::ComputeRectangleArea_Request>()
{
  return oxbot_interfaces::srv::builder::Init_ComputeRectangleArea_Request_length();
}

}  // namespace oxbot_interfaces


namespace oxbot_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeRectangleArea_Response_area
{
public:
  Init_ComputeRectangleArea_Response_area()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::oxbot_interfaces::srv::ComputeRectangleArea_Response area(::oxbot_interfaces::srv::ComputeRectangleArea_Response::_area_type arg)
  {
    msg_.area = std::move(arg);
    return std::move(msg_);
  }

private:
  ::oxbot_interfaces::srv::ComputeRectangleArea_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::oxbot_interfaces::srv::ComputeRectangleArea_Response>()
{
  return oxbot_interfaces::srv::builder::Init_ComputeRectangleArea_Response_area();
}

}  // namespace oxbot_interfaces

#endif  // OXBOT_INTERFACES__SRV__DETAIL__COMPUTE_RECTANGLE_AREA__BUILDER_HPP_
