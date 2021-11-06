#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class link_access_properties : public properties
{
public:
  link_access_properties           ()
  : properties(H5P_LINK_ACCESS)
  {

  }
  explicit link_access_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit link_access_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  link_access_properties           (const link_access_properties&  that) = default;
  link_access_properties           (      link_access_properties&& temp) = default;
 ~link_access_properties           () override                           = default;
  link_access_properties& operator=(const link_access_properties&  that) = default;
  link_access_properties& operator=(      link_access_properties&& temp) = default;
};
}