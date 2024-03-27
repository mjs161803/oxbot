// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from oxbot_interfaces:msg/MotionControlOutput.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__FUNCTIONS_H_
#define OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "oxbot_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "oxbot_interfaces/msg/detail/motion_control_output__struct.h"

/// Initialize msg/MotionControlOutput message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * oxbot_interfaces__msg__MotionControlOutput
 * )) before or use
 * oxbot_interfaces__msg__MotionControlOutput__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__MotionControlOutput__init(oxbot_interfaces__msg__MotionControlOutput * msg);

/// Finalize msg/MotionControlOutput message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__MotionControlOutput__fini(oxbot_interfaces__msg__MotionControlOutput * msg);

/// Create msg/MotionControlOutput message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * oxbot_interfaces__msg__MotionControlOutput__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
oxbot_interfaces__msg__MotionControlOutput *
oxbot_interfaces__msg__MotionControlOutput__create();

/// Destroy msg/MotionControlOutput message.
/**
 * It calls
 * oxbot_interfaces__msg__MotionControlOutput__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__MotionControlOutput__destroy(oxbot_interfaces__msg__MotionControlOutput * msg);

/// Check for msg/MotionControlOutput message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__MotionControlOutput__are_equal(const oxbot_interfaces__msg__MotionControlOutput * lhs, const oxbot_interfaces__msg__MotionControlOutput * rhs);

/// Copy a msg/MotionControlOutput message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__MotionControlOutput__copy(
  const oxbot_interfaces__msg__MotionControlOutput * input,
  oxbot_interfaces__msg__MotionControlOutput * output);

/// Initialize array of msg/MotionControlOutput messages.
/**
 * It allocates the memory for the number of elements and calls
 * oxbot_interfaces__msg__MotionControlOutput__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__MotionControlOutput__Sequence__init(oxbot_interfaces__msg__MotionControlOutput__Sequence * array, size_t size);

/// Finalize array of msg/MotionControlOutput messages.
/**
 * It calls
 * oxbot_interfaces__msg__MotionControlOutput__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__MotionControlOutput__Sequence__fini(oxbot_interfaces__msg__MotionControlOutput__Sequence * array);

/// Create array of msg/MotionControlOutput messages.
/**
 * It allocates the memory for the array and calls
 * oxbot_interfaces__msg__MotionControlOutput__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
oxbot_interfaces__msg__MotionControlOutput__Sequence *
oxbot_interfaces__msg__MotionControlOutput__Sequence__create(size_t size);

/// Destroy array of msg/MotionControlOutput messages.
/**
 * It calls
 * oxbot_interfaces__msg__MotionControlOutput__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__MotionControlOutput__Sequence__destroy(oxbot_interfaces__msg__MotionControlOutput__Sequence * array);

/// Check for msg/MotionControlOutput message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__MotionControlOutput__Sequence__are_equal(const oxbot_interfaces__msg__MotionControlOutput__Sequence * lhs, const oxbot_interfaces__msg__MotionControlOutput__Sequence * rhs);

/// Copy an array of msg/MotionControlOutput messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__MotionControlOutput__Sequence__copy(
  const oxbot_interfaces__msg__MotionControlOutput__Sequence * input,
  oxbot_interfaces__msg__MotionControlOutput__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OXBOT_INTERFACES__MSG__DETAIL__MOTION_CONTROL_OUTPUT__FUNCTIONS_H_
