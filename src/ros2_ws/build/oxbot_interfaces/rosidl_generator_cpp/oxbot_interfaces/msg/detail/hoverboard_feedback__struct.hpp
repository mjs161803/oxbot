// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from oxbot_interfaces:msg/HoverboardFeedback.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__STRUCT_HPP_
#define OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__oxbot_interfaces__msg__HoverboardFeedback __attribute__((deprecated))
#else
# define DEPRECATED__oxbot_interfaces__msg__HoverboardFeedback __declspec(deprecated)
#endif

namespace oxbot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HoverboardFeedback_
{
  using Type = HoverboardFeedback_<ContainerAllocator>;

  explicit HoverboardFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->steer_or_brake = 0;
      this->speed_or_throttle = 0;
      this->right_wheel_rpm = 0;
      this->left_wheel_rpm = 0;
      this->batt_voltage_x100 = 0;
      this->temperature = 0;
      this->led = 0;
      this->timestamp_ns = 0ull;
      this->front_or_back = "";
    }
  }

  explicit HoverboardFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : front_or_back(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->steer_or_brake = 0;
      this->speed_or_throttle = 0;
      this->right_wheel_rpm = 0;
      this->left_wheel_rpm = 0;
      this->batt_voltage_x100 = 0;
      this->temperature = 0;
      this->led = 0;
      this->timestamp_ns = 0ull;
      this->front_or_back = "";
    }
  }

  // field types and members
  using _steer_or_brake_type =
    int16_t;
  _steer_or_brake_type steer_or_brake;
  using _speed_or_throttle_type =
    int16_t;
  _speed_or_throttle_type speed_or_throttle;
  using _right_wheel_rpm_type =
    int16_t;
  _right_wheel_rpm_type right_wheel_rpm;
  using _left_wheel_rpm_type =
    int16_t;
  _left_wheel_rpm_type left_wheel_rpm;
  using _batt_voltage_x100_type =
    int16_t;
  _batt_voltage_x100_type batt_voltage_x100;
  using _temperature_type =
    int16_t;
  _temperature_type temperature;
  using _led_type =
    uint16_t;
  _led_type led;
  using _timestamp_ns_type =
    uint64_t;
  _timestamp_ns_type timestamp_ns;
  using _front_or_back_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _front_or_back_type front_or_back;

  // setters for named parameter idiom
  Type & set__steer_or_brake(
    const int16_t & _arg)
  {
    this->steer_or_brake = _arg;
    return *this;
  }
  Type & set__speed_or_throttle(
    const int16_t & _arg)
  {
    this->speed_or_throttle = _arg;
    return *this;
  }
  Type & set__right_wheel_rpm(
    const int16_t & _arg)
  {
    this->right_wheel_rpm = _arg;
    return *this;
  }
  Type & set__left_wheel_rpm(
    const int16_t & _arg)
  {
    this->left_wheel_rpm = _arg;
    return *this;
  }
  Type & set__batt_voltage_x100(
    const int16_t & _arg)
  {
    this->batt_voltage_x100 = _arg;
    return *this;
  }
  Type & set__temperature(
    const int16_t & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__led(
    const uint16_t & _arg)
  {
    this->led = _arg;
    return *this;
  }
  Type & set__timestamp_ns(
    const uint64_t & _arg)
  {
    this->timestamp_ns = _arg;
    return *this;
  }
  Type & set__front_or_back(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->front_or_back = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__oxbot_interfaces__msg__HoverboardFeedback
    std::shared_ptr<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__oxbot_interfaces__msg__HoverboardFeedback
    std::shared_ptr<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoverboardFeedback_ & other) const
  {
    if (this->steer_or_brake != other.steer_or_brake) {
      return false;
    }
    if (this->speed_or_throttle != other.speed_or_throttle) {
      return false;
    }
    if (this->right_wheel_rpm != other.right_wheel_rpm) {
      return false;
    }
    if (this->left_wheel_rpm != other.left_wheel_rpm) {
      return false;
    }
    if (this->batt_voltage_x100 != other.batt_voltage_x100) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->led != other.led) {
      return false;
    }
    if (this->timestamp_ns != other.timestamp_ns) {
      return false;
    }
    if (this->front_or_back != other.front_or_back) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoverboardFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoverboardFeedback_

// alias to use template instance with default allocator
using HoverboardFeedback =
  oxbot_interfaces::msg::HoverboardFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace oxbot_interfaces

#endif  // OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__STRUCT_HPP_
