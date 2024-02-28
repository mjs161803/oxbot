// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__STRUCT_HPP_
#define OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__oxbot_interfaces__msg__HoverboardCommand __attribute__((deprecated))
#else
# define DEPRECATED__oxbot_interfaces__msg__HoverboardCommand __declspec(deprecated)
#endif

namespace oxbot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HoverboardCommand_
{
  using Type = HoverboardCommand_<ContainerAllocator>;

  explicit HoverboardCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start_frame = 0;
      this->steer_or_brake = 0;
      this->speed_or_throttle = 0;
      this->xor_checksum = 0;
    }
  }

  explicit HoverboardCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start_frame = 0;
      this->steer_or_brake = 0;
      this->speed_or_throttle = 0;
      this->xor_checksum = 0;
    }
  }

  // field types and members
  using _start_frame_type =
    uint16_t;
  _start_frame_type start_frame;
  using _steer_or_brake_type =
    int16_t;
  _steer_or_brake_type steer_or_brake;
  using _speed_or_throttle_type =
    int16_t;
  _speed_or_throttle_type speed_or_throttle;
  using _xor_checksum_type =
    uint16_t;
  _xor_checksum_type xor_checksum;

  // setters for named parameter idiom
  Type & set__start_frame(
    const uint16_t & _arg)
  {
    this->start_frame = _arg;
    return *this;
  }
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
  Type & set__xor_checksum(
    const uint16_t & _arg)
  {
    this->xor_checksum = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__oxbot_interfaces__msg__HoverboardCommand
    std::shared_ptr<oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__oxbot_interfaces__msg__HoverboardCommand
    std::shared_ptr<oxbot_interfaces::msg::HoverboardCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoverboardCommand_ & other) const
  {
    if (this->start_frame != other.start_frame) {
      return false;
    }
    if (this->steer_or_brake != other.steer_or_brake) {
      return false;
    }
    if (this->speed_or_throttle != other.speed_or_throttle) {
      return false;
    }
    if (this->xor_checksum != other.xor_checksum) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoverboardCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoverboardCommand_

// alias to use template instance with default allocator
using HoverboardCommand =
  oxbot_interfaces::msg::HoverboardCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace oxbot_interfaces

#endif  // OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__STRUCT_HPP_
