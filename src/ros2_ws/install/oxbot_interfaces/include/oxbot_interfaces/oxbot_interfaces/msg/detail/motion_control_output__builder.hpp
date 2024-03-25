// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from oxbot_interfaces:msg/MotionControlOutput.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__BUILDER_HPP_
#define OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "oxbot_interfaces/msg/detail/motion_control_output__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace oxbot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotionControlOutput_mc_output
{
public:
  Init_MotionControlOutput_mc_output()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::oxbot_interfaces::msg::MotionControlOutput mc_output(::oxbot_interfaces::msg::MotionControlOutput::_mc_output_type arg)
  {
    msg_.mc_output = std::move(arg);
    return std::move(msg_);
  }

private:
  ::oxbot_interfaces::msg::MotionControlOutput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::oxbot_interfaces::msg::MotionControlOutput>()
{
  return oxbot_interfaces::msg::builder::Init_MotionControlOutput_mc_output();
}

}  // namespace oxbot_interfaces

#endif  // OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__BUILDER_HPP_
