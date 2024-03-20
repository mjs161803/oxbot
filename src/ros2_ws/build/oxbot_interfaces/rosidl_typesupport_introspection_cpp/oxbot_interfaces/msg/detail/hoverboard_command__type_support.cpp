// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "oxbot_interfaces/msg/detail/hoverboard_command__struct.hpp"
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

void HoverboardCommand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) oxbot_interfaces::msg::HoverboardCommand(_init);
}

void HoverboardCommand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<oxbot_interfaces::msg::HoverboardCommand *>(message_memory);
  typed_message->~HoverboardCommand();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HoverboardCommand_message_member_array[4] = {
  {
    "start_frame",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(oxbot_interfaces::msg::HoverboardCommand, start_frame),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "steer_or_brake",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(oxbot_interfaces::msg::HoverboardCommand, steer_or_brake),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed_or_throttle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(oxbot_interfaces::msg::HoverboardCommand, speed_or_throttle),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "xor_checksum",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(oxbot_interfaces::msg::HoverboardCommand, xor_checksum),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HoverboardCommand_message_members = {
  "oxbot_interfaces::msg",  // message namespace
  "HoverboardCommand",  // message name
  4,  // number of fields
  sizeof(oxbot_interfaces::msg::HoverboardCommand),
  HoverboardCommand_message_member_array,  // message members
  HoverboardCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  HoverboardCommand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HoverboardCommand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HoverboardCommand_message_members,
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
get_message_type_support_handle<oxbot_interfaces::msg::HoverboardCommand>()
{
  return &::oxbot_interfaces::msg::rosidl_typesupport_introspection_cpp::HoverboardCommand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, oxbot_interfaces, msg, HoverboardCommand)() {
  return &::oxbot_interfaces::msg::rosidl_typesupport_introspection_cpp::HoverboardCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
