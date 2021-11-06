#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class object_creation_properties : public properties
{
public:
  object_creation_properties           ()
  : properties(H5P_OBJECT_CREATE)
  {

  }
  explicit object_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit object_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  object_creation_properties           (const object_creation_properties&  that) = default;
  object_creation_properties           (      object_creation_properties&& temp) = default;
 ~object_creation_properties           () override                               = default;
  object_creation_properties& operator=(const object_creation_properties&  that) = default;
  object_creation_properties& operator=(      object_creation_properties&& temp) = default;
};
}