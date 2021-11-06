#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class link_creation_properties : public properties
{
public:
  link_creation_properties           ()
  : properties(H5P_LINK_CREATE)
  {

  }
  explicit link_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit link_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  link_creation_properties           (const link_creation_properties&  that) = default;
  link_creation_properties           (      link_creation_properties&& temp) = default;
 ~link_creation_properties           () override                             = default;
  link_creation_properties& operator=(const link_creation_properties&  that) = default;
  link_creation_properties& operator=(      link_creation_properties&& temp) = default;
};
}