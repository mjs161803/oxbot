// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
// generated code does not contain a copyright notice

#ifndef OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__FUNCTIONS_H_
#define OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "oxbot_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "oxbot_interfaces/msg/detail/hoverboard_command__struct.h"

/// Initialize msg/HoverboardCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * oxbot_interfaces__msg__HoverboardCommand
 * )) before or use
 * oxbot_interfaces__msg__HoverboardCommand__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__HoverboardCommand__init(oxbot_interfaces__msg__HoverboardCommand * msg);

/// Finalize msg/HoverboardCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__HoverboardCommand__fini(oxbot_interfaces__msg__HoverboardCommand * msg);

/// Create msg/HoverboardCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * oxbot_interfaces__msg__HoverboardCommand__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
oxbot_interfaces__msg__HoverboardCommand *
oxbot_interfaces__msg__HoverboardCommand__create();

/// Destroy msg/HoverboardCommand message.
/**
 * It calls
 * oxbot_interfaces__msg__HoverboardCommand__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__HoverboardCommand__destroy(oxbot_interfaces__msg__HoverboardCommand * msg);

/// Check for msg/HoverboardCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__HoverboardCommand__are_equal(const oxbot_interfaces__msg__HoverboardCommand * lhs, const oxbot_interfaces__msg__HoverboardCommand * rhs);

/// Copy a msg/HoverboardCommand message.
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
oxbot_interfaces__msg__HoverboardCommand__copy(
  const oxbot_interfaces__msg__HoverboardCommand * input,
  oxbot_interfaces__msg__HoverboardCommand * output);

/// Initialize array of msg/HoverboardCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * oxbot_interfaces__msg__HoverboardCommand__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__HoverboardCommand__Sequence__init(oxbot_interfaces__msg__HoverboardCommand__Sequence * array, size_t size);

/// Finalize array of msg/HoverboardCommand messages.
/**
 * It calls
 * oxbot_interfaces__msg__HoverboardCommand__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__HoverboardCommand__Sequence__fini(oxbot_interfaces__msg__HoverboardCommand__Sequence * array);

/// Create array of msg/HoverboardCommand messages.
/**
 * It allocates the memory for the array and calls
 * oxbot_interfaces__msg__HoverboardCommand__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
oxbot_interfaces__msg__HoverboardCommand__Sequence *
oxbot_interfaces__msg__HoverboardCommand__Sequence__create(size_t size);

/// Destroy array of msg/HoverboardCommand messages.
/**
 * It calls
 * oxbot_interfaces__msg__HoverboardCommand__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
void
oxbot_interfaces__msg__HoverboardCommand__Sequence__destroy(oxbot_interfaces__msg__HoverboardCommand__Sequence * array);

/// Check for msg/HoverboardCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_oxbot_interfaces
bool
oxbot_interfaces__msg__HoverboardCommand__Sequence__are_equal(const oxbot_interfaces__msg__HoverboardCommand__Sequence * lhs, const oxbot_interfaces__msg__HoverboardCommand__Sequence * rhs);

/// Copy an array of msg/HoverboardCommand messages.
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
oxbot_interfaces__msg__HoverboardCommand__Sequence__copy(
  const oxbot_interfaces__msg__HoverboardCommand__Sequence * input,
  oxbot_interfaces__msg__HoverboardCommand__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OXBOT_INTERFACES__MSG__DETAIL__HOVERBOARD_COMMAND__FUNCTIONS_H_
