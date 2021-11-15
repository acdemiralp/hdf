#pragma once

#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class attribute_access_properties : public properties
{
public:
  attribute_access_properties           ()
  : properties(attribute_access_property_class)
  {

  }
  explicit attribute_access_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit attribute_access_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  attribute_access_properties           (const attribute_access_properties&  that) = default;
  attribute_access_properties           (      attribute_access_properties&& temp) = default;
 ~attribute_access_properties           () override                                = default;
  attribute_access_properties& operator=(const attribute_access_properties&  that) = default;
  attribute_access_properties& operator=(      attribute_access_properties&& temp) = default;
};
}