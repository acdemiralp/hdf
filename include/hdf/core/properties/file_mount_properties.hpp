#pragma once

#include <hdf/core/properties.hpp>

namespace hdf
{
class file_mount_properties : public properties
{
public:
  file_mount_properties           ()
  : properties(H5P_FILE_MOUNT)
  {

  }
  explicit file_mount_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit file_mount_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  file_mount_properties           (const file_mount_properties&  that) = default;
  file_mount_properties           (      file_mount_properties&& temp) = default;
 ~file_mount_properties           () override                          = default;
  file_mount_properties& operator=(const file_mount_properties&  that) = default;
  file_mount_properties& operator=(      file_mount_properties&& temp) = default;
};
}