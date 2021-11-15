#pragma once

#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class dataset_access_properties : public properties
{
public:
  dataset_access_properties           ()
  : properties(data_type_access_properties_class)
  {

  }
  explicit dataset_access_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit dataset_access_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  dataset_access_properties           (const dataset_access_properties&  that) = default;
  dataset_access_properties           (      dataset_access_properties&& temp) = default;
 ~dataset_access_properties           () override                              = default;
  dataset_access_properties& operator=(const dataset_access_properties&  that) = default;
  dataset_access_properties& operator=(      dataset_access_properties&& temp) = default;
};
}