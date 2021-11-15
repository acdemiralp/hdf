#pragma once

#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class map_access_properties : public properties
{
public:
  map_access_properties           ()
  : properties(map_access_properties_class)
  {

  }
  explicit map_access_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit map_access_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  map_access_properties           (const map_access_properties&  that) = default;
  map_access_properties           (      map_access_properties&& temp) = default;
 ~map_access_properties           () override                          = default;
  map_access_properties& operator=(const map_access_properties&  that) = default;
  map_access_properties& operator=(      map_access_properties&& temp) = default;
};
}