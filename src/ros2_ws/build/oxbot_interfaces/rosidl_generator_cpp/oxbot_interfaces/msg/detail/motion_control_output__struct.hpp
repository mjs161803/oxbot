// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from oxbot_interfaces:msg/MotionControlOutput.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__STRUCT_HPP_
#define OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'mc_output'
#include "oxbot_interfaces/msg/detail/hoverboard_feedback__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__oxbot_interfaces__msg__MotionControlOutput __attribute__((deprecated))
#else
# define DEPRECATED__oxbot_interfaces__msg__MotionControlOutput __declspec(deprecated)
#endif

namespace oxbot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotionControlOutput_
{
  using Type = MotionControlOutput_<ContainerAllocator>;

  explicit MotionControlOutput_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MotionControlOutput_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _mc_output_type =
    std::vector<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator>>>;
  _mc_output_type mc_output;

  // setters for named parameter idiom
  Type & set__mc_output(
    const std::vector<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<oxbot_interfaces::msg::HoverboardFeedback_<ContainerAllocator>>> & _arg)
  {
    this->mc_output = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator> *;
  using ConstRawPtr =
    const oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__oxbot_interfaces__msg__MotionControlOutput
    std::shared_ptr<oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__oxbot_interfaces__msg__MotionControlOutput
    std::shared_ptr<oxbot_interfaces::msg::MotionControlOutput_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotionControlOutput_ & other) const
  {
    if (this->mc_output != other.mc_output) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotionControlOutput_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotionControlOutput_

// alias to use template instance with default allocator
using MotionControlOutput =
  oxbot_interfaces::msg::MotionControlOutput_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace oxbot_interfaces

#endif  // OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__STRUCT_HPP_
