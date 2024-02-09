// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from oxbot_interfaces:msg/HoverboardFeedback.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__FUNCTIONS_H_
#define OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "oxbot_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "oxbot_interfaces/msg/detail/hoverboard_feedback__struct.h"

/// Initialize msg/HoverboardFeedback message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * oxbot_interfaces__msg__HoverboardFeedback
 * )) before or use
 * oxbot_interfaces__msg__HoverboardFeedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__HoverboardFeedback__init(oxbot_interfaces__msg__HoverboardFeedback * msg);

/// Finalize msg/HoverboardFeedback message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__HoverboardFeedback__fini(oxbot_interfaces__msg__HoverboardFeedback * msg);

/// Create msg/HoverboardFeedback message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * oxbot_interfaces__msg__HoverboardFeedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
oxbot_interfaces__msg__HoverboardFeedback *
oxbot_interfaces__msg__HoverboardFeedback__create();

/// Destroy msg/HoverboardFeedback message.
/**
 * It calls
 * oxbot_interfaces__msg__HoverboardFeedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__HoverboardFeedback__destroy(oxbot_interfaces__msg__HoverboardFeedback * msg);

/// Check for msg/HoverboardFeedback message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__HoverboardFeedback__are_equal(const oxbot_interfaces__msg__HoverboardFeedback * lhs, const oxbot_interfaces__msg__HoverboardFeedback * rhs);

/// Copy a msg/HoverboardFeedback message.
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
oxbot_interfaces__msg__HoverboardFeedback__copy(
  const oxbot_interfaces__msg__HoverboardFeedback * input,
  oxbot_interfaces__msg__HoverboardFeedback * output);

/// Initialize array of msg/HoverboardFeedback messages.
/**
 * It allocates the memory for the number of elements and calls
 * oxbot_interfaces__msg__HoverboardFeedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__HoverboardFeedback__Sequence__init(oxbot_interfaces__msg__HoverboardFeedback__Sequence * array, size_t size);

/// Finalize array of msg/HoverboardFeedback messages.
/**
 * It calls
 * oxbot_interfaces__msg__HoverboardFeedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__HoverboardFeedback__Sequence__fini(oxbot_interfaces__msg__HoverboardFeedback__Sequence * array);

/// Create array of msg/HoverboardFeedback messages.
/**
 * It allocates the memory for the array and calls
 * oxbot_interfaces__msg__HoverboardFeedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
oxbot_interfaces__msg__HoverboardFeedback__Sequence *
oxbot_interfaces__msg__HoverboardFeedback__Sequence__create(size_t size);

/// Destroy array of msg/HoverboardFeedback messages.
/**
 * It calls
 * oxbot_interfaces__msg__HoverboardFeedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__HoverboardFeedback__Sequence__destroy(oxbot_interfaces__msg__HoverboardFeedback__Sequence * array);

/// Check for msg/HoverboardFeedback message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__HoverboardFeedback__Sequence__are_equal(const oxbot_interfaces__msg__HoverboardFeedback__Sequence * lhs, const oxbot_interfaces__msg__HoverboardFeedback__Sequence * rhs);

/// Copy an array of msg/HoverboardFeedback messages.
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
oxbot_interfaces__msg__HoverboardFeedback__Sequence__copy(
  const oxbot_interfaces__msg__HoverboardFeedback__Sequence * input,
  oxbot_interfaces__msg__HoverboardFeedback__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_FEEDBACK__FUNCTIONS_H_
