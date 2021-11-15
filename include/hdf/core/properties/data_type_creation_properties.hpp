#pragma once

#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class data_type_creation_properties : public properties
{
public:
  data_type_creation_properties           ()
  : properties(data_type_creation_properties_class)
  {

  }
  explicit data_type_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit data_type_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  data_type_creation_properties           (const data_type_creation_properties&  that) = default;
  data_type_creation_properties           (      data_type_creation_properties&& temp) = default;
 ~data_type_creation_properties           () override                                  = default;
  data_type_creation_properties& operator=(const data_type_creation_properties&  that) = default;
  data_type_creation_properties& operator=(      data_type_creation_properties&& temp) = default;
};
}