#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class map_creation_properties : public properties
{
public:
  map_creation_properties           ()
  : properties(H5P_MAP_CREATE)
  {

  }
  explicit map_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit map_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  map_creation_properties           (const map_creation_properties&  that) = default;
  map_creation_properties           (      map_creation_properties&& temp) = default;
 ~map_creation_properties           () override                            = default;
  map_creation_properties& operator=(const map_creation_properties&  that) = default;
  map_creation_properties& operator=(      map_creation_properties&& temp) = default;
};
}