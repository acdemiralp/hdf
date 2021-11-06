#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class group_creation_properties : public properties
{
public:
  group_creation_properties           ()
  : properties(H5P_GROUP_CREATE)
  {

  }
  explicit group_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit group_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  group_creation_properties           (const group_creation_properties&  that) = default;
  group_creation_properties           (      group_creation_properties&& temp) = default;
 ~group_creation_properties           () override                              = default;
  group_creation_properties& operator=(const group_creation_properties&  that) = default;
  group_creation_properties& operator=(      group_creation_properties&& temp) = default;
};
}