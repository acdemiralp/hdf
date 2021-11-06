#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class object_copy_properties : public properties
{
public:
  object_copy_properties           ()
  : properties(H5P_OBJECT_COPY)
  {

  }
  explicit object_copy_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit object_copy_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  object_copy_properties           (const object_copy_properties&  that) = default;
  object_copy_properties           (      object_copy_properties&& temp) = default;
 ~object_copy_properties           () override                           = default;
  object_copy_properties& operator=(const object_copy_properties&  that) = default;
  object_copy_properties& operator=(      object_copy_properties&& temp) = default;
};
}