#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class string_creation_properties : public properties
{
public:
  string_creation_properties           ()
  : properties(H5P_STRING_CREATE)
  {

  }
  explicit string_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit string_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  string_creation_properties           (const string_creation_properties&  that) = default;
  string_creation_properties           (      string_creation_properties&& temp) = default;
 ~string_creation_properties           () override                               = default;
  string_creation_properties& operator=(const string_creation_properties&  that) = default;
  string_creation_properties& operator=(      string_creation_properties&& temp) = default;
};
}