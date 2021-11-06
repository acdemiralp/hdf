#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class dataset_transfer_properties : public properties
{
public:
  dataset_transfer_properties           ()
  : properties(H5P_DATASET_XFER)
  {

  }
  explicit dataset_transfer_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit dataset_transfer_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  dataset_transfer_properties           (const dataset_transfer_properties&  that) = default;
  dataset_transfer_properties           (      dataset_transfer_properties&& temp) = default;
 ~dataset_transfer_properties           () override                                = default;
  dataset_transfer_properties& operator=(const dataset_transfer_properties&  that) = default;
  dataset_transfer_properties& operator=(      dataset_transfer_properties&& temp) = default;
};
}