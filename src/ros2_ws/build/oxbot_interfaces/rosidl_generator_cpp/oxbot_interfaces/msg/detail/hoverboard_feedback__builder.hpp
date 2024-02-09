// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from oxbot_interfaces:msg/HoverboardFeedback.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__BUILDER_HPP_
#define OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "oxbot_interfaces/msg/detail/hoverboard_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace oxbot_interfaces
{

namespace msg
{

namespace builder
{

class Init_HoverboardFeedback_led
{
public:
  explicit Init_HoverboardFeedback_led(::oxbot_interfaces::msg::HoverboardFeedback & msg)
  : msg_(msg)
  {}
  ::oxbot_interfaces::msg::HoverboardFeedback led(::oxbot_interfaces::msg::HoverboardFeedback::_led_type arg)
  {
    msg_.led = std::move(arg);
    return std::move(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardFeedback msg_;
};

class Init_HoverboardFeedback_temperature
{
public:
  explicit Init_HoverboardFeedback_temperature(::oxbot_interfaces::msg::HoverboardFeedback & msg)
  : msg_(msg)
  {}
  Init_HoverboardFeedback_led temperature(::oxbot_interfaces::msg::HoverboardFeedback::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_HoverboardFeedback_led(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardFeedback msg_;
};

class Init_HoverboardFeedback_batt_voltage_x100
{
public:
  explicit Init_HoverboardFeedback_batt_voltage_x100(::oxbot_interfaces::msg::HoverboardFeedback & msg)
  : msg_(msg)
  {}
  Init_HoverboardFeedback_temperature batt_voltage_x100(::oxbot_interfaces::msg::HoverboardFeedback::_batt_voltage_x100_type arg)
  {
    msg_.batt_voltage_x100 = std::move(arg);
    return Init_HoverboardFeedback_temperature(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardFeedback msg_;
};

class Init_HoverboardFeedback_left_wheel_rpm
{
public:
  explicit Init_HoverboardFeedback_left_wheel_rpm(::oxbot_interfaces::msg::HoverboardFeedback & msg)
  : msg_(msg)
  {}
  Init_HoverboardFeedback_batt_voltage_x100 left_wheel_rpm(::oxbot_interfaces::msg::HoverboardFeedback::_left_wheel_rpm_type arg)
  {
    msg_.left_wheel_rpm = std::move(arg);
    return Init_HoverboardFeedback_batt_voltage_x100(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardFeedback msg_;
};

class Init_HoverboardFeedback_right_wheel_rpm
{
public:
  explicit Init_HoverboardFeedback_right_wheel_rpm(::oxbot_interfaces::msg::HoverboardFeedback & msg)
  : msg_(msg)
  {}
  Init_HoverboardFeedback_left_wheel_rpm right_wheel_rpm(::oxbot_interfaces::msg::HoverboardFeedback::_right_wheel_rpm_type arg)
  {
    msg_.right_wheel_rpm = std::move(arg);
    return Init_HoverboardFeedback_left_wheel_rpm(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardFeedback msg_;
};

class Init_HoverboardFeedback_speed_or_throttle
{
public:
  explicit Init_HoverboardFeedback_speed_or_throttle(::oxbot_interfaces::msg::HoverboardFeedback & msg)
  : msg_(msg)
  {}
  Init_HoverboardFeedback_right_wheel_rpm speed_or_throttle(::oxbot_interfaces::msg::HoverboardFeedback::_speed_or_throttle_type arg)
  {
    msg_.speed_or_throttle = std::move(arg);
    return Init_HoverboardFeedback_right_wheel_rpm(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardFeedback msg_;
};

class Init_HoverboardFeedback_steer_or_brake
{
public:
  Init_HoverboardFeedback_steer_or_brake()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoverboardFeedback_speed_or_throttle steer_or_brake(::oxbot_interfaces::msg::HoverboardFeedback::_steer_or_brake_type arg)
  {
    msg_.steer_or_brake = std::move(arg);
    return Init_HoverboardFeedback_speed_or_throttle(msg_);
  }

private:
  ::oxbot_interfaces::msg::HoverboardFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::oxbot_interfaces::msg::HoverboardFeedback>()
{
  return oxbot_interfaces::msg::builder::Init_HoverboardFeedback_steer_or_brake();
}

}  // namespace oxbot_interfaces

#endif  // OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__BUILDER_HPP_
