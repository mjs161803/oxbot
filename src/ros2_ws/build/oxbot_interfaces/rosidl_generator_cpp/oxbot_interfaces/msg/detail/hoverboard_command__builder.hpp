// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__BUILDER_HPP_
#define OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "oxbot_interfaces/msg/detail/hoverboard_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace oxbot_interfaces
{

namespace msg
{

namespace builder
{

class Init_HoverboardCommand_xor_checksum
{
public:
  explicit Init_HoverboardCommand_xor_checksum(::oxbot_interfaces::msg::HoverboardCommand & msg)
  : msg_(msg)
  {}
  ::oxbot_interfaces::msg::HoverboardCommand xor_checksum(::oxbot_interfaces::msg::HoverboardCommand::_xor_checksum_type arg)
  {
    msg_.xor_checksum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardCommand msg_;
};

class Init_HoverboardCommand_speed_or_throttle
{
public:
  explicit Init_HoverboardCommand_speed_or_throttle(::oxbot_interfaces::msg::HoverboardCommand & msg)
  : msg_(msg)
  {}
  Init_HoverboardCommand_xor_checksum speed_or_throttle(::oxbot_interfaces::msg::HoverboardCommand::_speed_or_throttle_type arg)
  {
    msg_.speed_or_throttle = std::move(arg);
    return Init_HoverboardCommand_xor_checksum(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardCommand msg_;
};

class Init_HoverboardCommand_steer_or_brake
{
public:
  explicit Init_HoverboardCommand_steer_or_brake(::oxbot_interfaces::msg::HoverboardCommand & msg)
  : msg_(msg)
  {}
  Init_HoverboardCommand_speed_or_throttle steer_or_brake(::oxbot_interfaces::msg::HoverboardCommand::_steer_or_brake_type arg)
  {
    msg_.steer_or_brake = std::move(arg);
    return Init_HoverboardCommand_speed_or_throttle(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardCommand msg_;
};

class Init_HoverboardCommand_start_frame
{
public:
  Init_HoverboardCommand_start_frame()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoverboardCommand_steer_or_brake start_frame(::oxbot_interfaces::msg::HoverboardCommand::_start_frame_type arg)
  {
    msg_.start_frame = std::move(arg);
    return Init_HoverboardCommand_steer_or_brake(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::oxbot_interfaces::msg::HoverboardCommand>()
{
  return oxbot_interfaces::msg::builder::Init_HoverboardCommand_start_frame();
}

}  // namespace oxbot_interfaces

#endif  // OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__BUILDER_HPP_
