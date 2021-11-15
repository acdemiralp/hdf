#pragma once

#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class file_creation_properties : public properties
{
public:
  file_creation_properties           ()
  : properties(file_creation_properties_class)
  {

  }
  explicit file_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit file_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  file_creation_properties           (const file_creation_properties&  that) = default;
  file_creation_properties           (      file_creation_properties&& temp) = default;
 ~file_creation_properties           () override                             = default;
  file_creation_properties& operator=(const file_creation_properties&  that) = default;
  file_creation_properties& operator=(      file_creation_properties&& temp) = default;
};
}