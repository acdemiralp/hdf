#pragma once

#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
#ifdef HDF_USE_LATEST
struct error_information : H5ES_err_info_t
{
  error_information           () : H5ES_err_info_t()
  {
    
  }
  error_information           (const error_information&  that) = default;
  error_information           (      error_information&& temp) = default;
  virtual ~error_information  ()
  {
    // ... The strings retrieved for each error info must be released by calling H5free_memory(). ...
    if (api_name     ) HDF_CHECK_ERROR_CODE(H5free_memory, (static_cast<void*>(api_name     )))
    if (api_args     ) HDF_CHECK_ERROR_CODE(H5free_memory, (static_cast<void*>(api_args     )))
    if (app_file_name) HDF_CHECK_ERROR_CODE(H5free_memory, (static_cast<void*>(app_file_name)))
    if (app_func_name) HDF_CHECK_ERROR_CODE(H5free_memory, (static_cast<void*>(app_func_name)))
  }
  error_information& operator=(const error_information&  that) = default;
  error_information& operator=(      error_information&& temp) = default;
};
#endif
}