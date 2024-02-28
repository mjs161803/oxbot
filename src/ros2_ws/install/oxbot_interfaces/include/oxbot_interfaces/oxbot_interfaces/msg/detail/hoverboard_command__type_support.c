// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "oxbot_interfaces/msg/detail/hoverboard_command__rosidl_typesupport_introspection_c.h"
#include "oxbot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "oxbot_interfaces/msg/detail/hoverboard_command__functions.h"
#include "oxbot_interfaces/msg/detail/hoverboard_command__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  oxbot_interfaces__msg__HoverboardCommand__init(message_memory);
}

void oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_fini_function(void * message_memory)
{
  oxbot_interfaces__msg__HoverboardCommand__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_message_member_array[4] = {
  {
    "start_frame",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(oxbot_interfaces__msg__HoverboardCommand, start_frame),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "steer_or_brake",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(oxbot_interfaces__msg__HoverboardCommand, steer_or_brake),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed_or_throttle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(oxbot_interfaces__msg__HoverboardCommand, speed_or_throttle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xor_checksum",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(oxbot_interfaces__msg__HoverboardCommand, xor_checksum),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_message_members = {
  "oxbot_interfaces__msg",  // message namespace
  "HoverboardCommand",  // message name
  4,  // number of fields
  sizeof(oxbot_interfaces__msg__HoverboardCommand),
  oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_message_member_array,  // message members
  oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_message_type_support_handle = {
  0,
  &oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_oxbot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, oxbot_interfaces, msg, HoverboardCommand)() {
  if (!oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_message_type_support_handle.typesupport_identifier) {
    oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &oxbot_interfaces__msg__HoverboardCommand__rosidl_typesupport_introspection_c__HoverboardCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
