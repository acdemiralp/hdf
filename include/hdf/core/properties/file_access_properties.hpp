#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class file_access_properties : public properties
{
public:
  file_access_properties           ()
  : properties(H5P_FILE_ACCESS)
  {

  }
  explicit file_access_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit file_access_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  file_access_properties           (const file_access_properties&  that) = default;
  file_access_properties           (      file_access_properties&& temp) = default;
 ~file_access_properties           () override                           = default;
  file_access_properties& operator=(const file_access_properties&  that) = default;
  file_access_properties& operator=(      file_access_properties&& temp) = default;
};
}