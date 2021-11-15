#pragma once

#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class file_access_properties : public properties
{
public:
  file_access_properties           ()
  : properties(file_access_properties_class)
  {

  }
  explicit file_access_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit file_access_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  file_access_properties           (const file_access_properties&  that) = default;
  file_access_properties           (      file_access_properties&& temp) = default;
 ~file_access_properties           () override                           = default;
  file_access_properties& operator=(const file_access_properties&  that) = default;
  file_access_properties& operator=(      file_access_properties&& temp) = default;
};

template <typename type> [[nodiscard]]
std::vector<type> properties::encode(const file_access_properties& props) const
{
  std::size_t size;
  HDF_CHECK_ERROR_CODE(H5Pencode2, (native_, nullptr                          , &size, props.native()))
  std::vector<type> result(size);
  HDF_CHECK_ERROR_CODE(H5Pencode2, (native_, static_cast<void*>(result.data()), &size, props.native()))
  return result;
}
}