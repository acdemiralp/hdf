#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class group_access_properties : public properties
{
public:
  group_access_properties           ()
  : properties(H5P_GROUP_ACCESS)
  {

  }
  explicit group_access_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit group_access_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  group_access_properties           (const group_access_properties&  that) = default;
  group_access_properties           (      group_access_properties&& temp) = default;
 ~group_access_properties           () override                            = default;
  group_access_properties& operator=(const group_access_properties&  that) = default;
  group_access_properties& operator=(      group_access_properties&& temp) = default;
};
}