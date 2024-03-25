// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from oxbot_interfaces:msg/MotionControlOutput.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "oxbot_interfaces/msg/detail/motion_control_output__rosidl_typesupport_introspection_c.h"
#include "oxbot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "oxbot_interfaces/msg/detail/motion_control_output__functions.h"
#include "oxbot_interfaces/msg/detail/motion_control_output__struct.h"


// Include directives for member types
// Member `mc_output`
#include "oxbot_interfaces/msg/hoverboard_feedback.h"
// Member `mc_output`
#include "oxbot_interfaces/msg/detail/hoverboard_feedback__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  oxbot_interfaces__msg__MotionControlOutput__init(message_memory);
}

void oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_fini_function(void * message_memory)
{
  oxbot_interfaces__msg__MotionControlOutput__fini(message_memory);
}

size_t oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__size_function__MotionControlOutput__mc_output(
  const void * untyped_member)
{
  const oxbot_interfaces__msg__HoverboardFeedback__Sequence * member =
    (const oxbot_interfaces__msg__HoverboardFeedback__Sequence *)(untyped_member);
  return member->size;
}

const void * oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__get_const_function__MotionControlOutput__mc_output(
  const void * untyped_member, size_t index)
{
  const oxbot_interfaces__msg__HoverboardFeedback__Sequence * member =
    (const oxbot_interfaces__msg__HoverboardFeedback__Sequence *)(untyped_member);
  return &member->data[index];
}

void * oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__get_function__MotionControlOutput__mc_output(
  void * untyped_member, size_t index)
{
  oxbot_interfaces__msg__HoverboardFeedback__Sequence * member =
    (oxbot_interfaces__msg__HoverboardFeedback__Sequence *)(untyped_member);
  return &member->data[index];
}

void oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__fetch_function__MotionControlOutput__mc_output(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const oxbot_interfaces__msg__HoverboardFeedback * item =
    ((const oxbot_interfaces__msg__HoverboardFeedback *)
    oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__get_const_function__MotionControlOutput__mc_output(untyped_member, index));
  oxbot_interfaces__msg__HoverboardFeedback * value =
    (oxbot_interfaces__msg__HoverboardFeedback *)(untyped_value);
  *value = *item;
}

void oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__assign_function__MotionControlOutput__mc_output(
  void * untyped_member, size_t index, const void * untyped_value)
{
  oxbot_interfaces__msg__HoverboardFeedback * item =
    ((oxbot_interfaces__msg__HoverboardFeedback *)
    oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__get_function__MotionControlOutput__mc_output(untyped_member, index));
  const oxbot_interfaces__msg__HoverboardFeedback * value =
    (const oxbot_interfaces__msg__HoverboardFeedback *)(untyped_value);
  *item = *value;
}

bool oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__resize_function__MotionControlOutput__mc_output(
  void * untyped_member, size_t size)
{
  oxbot_interfaces__msg__HoverboardFeedback__Sequence * member =
    (oxbot_interfaces__msg__HoverboardFeedback__Sequence *)(untyped_member);
  oxbot_interfaces__msg__HoverboardFeedback__Sequence__fini(member);
  return oxbot_interfaces__msg__HoverboardFeedback__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_message_member_array[1] = {
  {
    "mc_output",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(oxbot_interfaces__msg__MotionControlOutput, mc_output),  // bytes offset in struct
    NULL,  // default value
    oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__size_function__MotionControlOutput__mc_output,  // size() function pointer
    oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__get_const_function__MotionControlOutput__mc_output,  // get_const(index) function pointer
    oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__get_function__MotionControlOutput__mc_output,  // get(index) function pointer
    oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__fetch_function__MotionControlOutput__mc_output,  // fetch(index, &value) function pointer
    oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__assign_function__MotionControlOutput__mc_output,  // assign(index, value) function pointer
    oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__resize_function__MotionControlOutput__mc_output  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_message_members = {
  "oxbot_interfaces__msg",  // message namespace
  "MotionControlOutput",  // message name
  1,  // number of fields
  sizeof(oxbot_interfaces__msg__MotionControlOutput),
  oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_message_member_array,  // message members
  oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_init_function,  // function to initialize message memory (memory has to be allocated)
  oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_message_type_support_handle = {
  0,
  &oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_oxbot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, oxbot_interfaces, msg, MotionControlOutput)() {
  oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, oxbot_interfaces, msg, HoverboardFeedback)();
  if (!oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_message_type_support_handle.typesupport_identifier) {
    oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &oxbot_interfaces__msg__MotionControlOutput__rosidl_typesupport_introspection_c__MotionControlOutput_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
