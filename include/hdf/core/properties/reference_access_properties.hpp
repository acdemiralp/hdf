#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class reference_access_properties : public properties
{
public:
  reference_access_properties           ()
  : properties(H5P_REFERENCE_ACCESS)
  {

  }
  explicit reference_access_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit reference_access_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  reference_access_properties           (const reference_access_properties&  that) = default;
  reference_access_properties           (      reference_access_properties&& temp) = default;
 ~reference_access_properties           () override                                = default;
  reference_access_properties& operator=(const reference_access_properties&  that) = default;
  reference_access_properties& operator=(      reference_access_properties&& temp) = default;
};
}