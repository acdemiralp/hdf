#pragma once

#include <stdexcept>
#include <string>

#include <hdf/core/hdf.hpp>

namespace hdf
{
class exception : public std::runtime_error
{
public:
  explicit exception  (const std::string& function_name, const herr_t code)
  : std::runtime_error(std::string(function_name + " failed with code " + std::to_string(code) + "."))
  , function_name_    (function_name)
  , code_             (code)
  {
    
  }
  exception           (const exception&  that) = default;
  exception           (      exception&& temp) = default;
 ~exception           () override              = default;
  exception& operator=(const exception&  that) = default;
  exception& operator=(      exception&& temp) = default;

  [[nodiscard]]
  const std::string& function_name() const
  {
    return function_name_;
  }
  [[nodiscard]]
  herr_t             code         () const
  {
    return code_;
  }

protected:
  std::string function_name_;
  herr_t      code_         ;
};
}

#ifdef HDF_USE_EXCEPTIONS
#define HDF_CHECK_ERROR_CODE(FUNC, ARGS)                           \
auto code = FUNC ARGS;                                             \
if (code < 0)                                                      \
  throw hdf::exception(std::string(#FUNC), mpi::error_code(code));
#else
#define HDF_CHECK_ERROR_CODE(FUNC, ARGS) FUNC ARGS;
#endif