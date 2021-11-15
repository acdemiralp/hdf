#pragma once

#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class vol_initialization_properties : public properties
{
public:
  vol_initialization_properties           ()
  : properties(vol_initialization_properties_class)
  {

  }
  explicit vol_initialization_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit vol_initialization_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  vol_initialization_properties           (const vol_initialization_properties&  that) = default;
  vol_initialization_properties           (      vol_initialization_properties&& temp) = default;
 ~vol_initialization_properties           () override                                  = default;
  vol_initialization_properties& operator=(const vol_initialization_properties&  that) = default;
  vol_initialization_properties& operator=(      vol_initialization_properties&& temp) = default;
};
}