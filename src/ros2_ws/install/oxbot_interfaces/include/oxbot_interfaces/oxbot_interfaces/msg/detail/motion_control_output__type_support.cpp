// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from oxbot_interfaces:msg/MotionControlOutput.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "oxbot_interfaces/msg/detail/motion_control_output__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace oxbot_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MotionControlOutput_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) oxbot_interfaces::msg::MotionControlOutput(_init);
}

void MotionControlOutput_fini_function(void * message_memory)
{
  auto typed_message = static_cast<oxbot_interfaces::msg::MotionControlOutput *>(message_memory);
  typed_message->~MotionControlOutput();
}

size_t size_function__MotionControlOutput__mc_output(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<oxbot_interfaces::msg::HoverboardFeedback> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotionControlOutput__mc_output(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<oxbot_interfaces::msg::HoverboardFeedback> *>(untyped_member);
  return &member[index];
}

void * get_function__MotionControlOutput__mc_output(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<oxbot_interfaces::msg::HoverboardFeedback> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotionControlOutput__mc_output(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const oxbot_interfaces::msg::HoverboardFeedback *>(
    get_const_function__MotionControlOutput__mc_output(untyped_member, index));
  auto & value = *reinterpret_cast<oxbot_interfaces::msg::HoverboardFeedback *>(untyped_value);
  value = item;
}

void assign_function__MotionControlOutput__mc_output(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<oxbot_interfaces::msg::HoverboardFeedback *>(
    get_function__MotionControlOutput__mc_output(untyped_member, index));
  const auto & value = *reinterpret_cast<const oxbot_interfaces::msg::HoverboardFeedback *>(untyped_value);
  item = value;
}

void resize_function__MotionControlOutput__mc_output(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<oxbot_interfaces::msg::HoverboardFeedback> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotionControlOutput_message_member_array[1] = {
  {
    "mc_output",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<oxbot_interfaces::msg::HoverboardFeedback>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(oxbot_interfaces::msg::MotionControlOutput, mc_output),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotionControlOutput__mc_output,  // size() function pointer
    get_const_function__MotionControlOutput__mc_output,  // get_const(index) function pointer
    get_function__MotionControlOutput__mc_output,  // get(index) function pointer
    fetch_function__MotionControlOutput__mc_output,  // fetch(index, &value) function pointer
    assign_function__MotionControlOutput__mc_output,  // assign(index, value) function pointer
    resize_function__MotionControlOutput__mc_output  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotionControlOutput_message_members = {
  "oxbot_interfaces::msg",  // message namespace
  "MotionControlOutput",  // message name
  1,  // number of fields
  sizeof(oxbot_interfaces::msg::MotionControlOutput),
  MotionControlOutput_message_member_array,  // message members
  MotionControlOutput_init_function,  // function to initialize message memory (memory has to be allocated)
  MotionControlOutput_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotionControlOutput_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotionControlOutput_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace oxbot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<oxbot_interfaces::msg::MotionControlOutput>()
{
  return &::oxbot_interfaces::msg::rosidl_typesupport_introspection_cpp::MotionControlOutput_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, oxbot_interfaces, msg, MotionControlOutput)() {
  return &::oxbot_interfaces::msg::rosidl_typesupport_introspection_cpp::MotionControlOutput_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
