#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class data_type_access_properties : public properties
{
public:
  data_type_access_properties           ()
  : properties(H5P_DATATYPE_ACCESS)
  {

  }
  explicit data_type_access_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit data_type_access_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  data_type_access_properties           (const data_type_access_properties&  that) = default;
  data_type_access_properties           (      data_type_access_properties&& temp) = default;
 ~data_type_access_properties           () override                                = default;
  data_type_access_properties& operator=(const data_type_access_properties&  that) = default;
  data_type_access_properties& operator=(      data_type_access_properties&& temp) = default;
};
}