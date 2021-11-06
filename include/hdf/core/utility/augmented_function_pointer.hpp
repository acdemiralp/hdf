#pragma once

#include <functional>

namespace hdf
{
// Allows a function pointer to capture, given its final argument is a void* for user data.
template <typename return_type, typename... argument_types>
struct augmented_function_pointer
{
  using function_type         = std::function<return_type(argument_types...)>;
  using function_pointer_type = return_type (*) (argument_types..., void*);

  static function_pointer_type function_pointer()
  {
    return [ ] (argument_types... arguments, void* user_data)
    {
      return (*static_cast<function_type*>(user_data))(arguments...);
    };
  }
  void*                        user_data       ()
  {
    return static_cast<void*>(&function);
  }

  function_type function;
};
}