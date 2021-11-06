#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class attribute_creation_properties : public properties
{
public:
  attribute_creation_properties           ()
  : properties(H5P_ATTRIBUTE_CREATE)
  {

  }
  explicit attribute_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit attribute_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  attribute_creation_properties           (const attribute_creation_properties&  that) = default;
  attribute_creation_properties           (      attribute_creation_properties&& temp) = default;
 ~attribute_creation_properties           () override                                  = default;
  attribute_creation_properties& operator=(const attribute_creation_properties&  that) = default;
  attribute_creation_properties& operator=(      attribute_creation_properties&& temp) = default;
};
}