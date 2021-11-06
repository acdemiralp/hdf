#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class dataset_creation_properties : public properties
{
public:
  dataset_creation_properties           ()
  : properties(H5P_DATASET_CREATE)
  {

  }
  explicit dataset_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit dataset_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  dataset_creation_properties           (const dataset_creation_properties&  that) = default;
  dataset_creation_properties           (      dataset_creation_properties&& temp) = default;
 ~dataset_creation_properties           () override                                = default;
  dataset_creation_properties& operator=(const dataset_creation_properties&  that) = default;
  dataset_creation_properties& operator=(      dataset_creation_properties&& temp) = default;
};
}