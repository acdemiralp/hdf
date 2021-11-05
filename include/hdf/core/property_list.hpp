#pragma once

#include <vector>

#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

#include "property_list.hpp"

namespace hdf
{
class file_access_properties;

class properties
{
public:
  explicit properties  (const hid_t properties_class)
  : managed_(true)   , native_(H5Pcreate(properties_class))
  {
    
  }
  explicit properties  (const void* encoded)
  : managed_(true)   , native_(H5Pdecode(encoded))
  {
    
  }
  explicit properties  (const hid_t native, const bool managed)
  : managed_(managed), native_(native)
  {
    
  }
  properties           (const properties&  that)
  : managed_(true), native_(H5Pcopy(that.native_))
  {
    
  }
  properties           (      properties&& temp)
  : managed_(temp.managed_), native_(temp.native_)
  {
    temp.managed_ = false;
    temp.native_  = 0;
  }
  virtual ~properties  ()
  {
    if (managed_)
      HDF_CHECK_ERROR_CODE(H5Pclose, (native_))
  }
  properties& operator=(const properties&  that)
  {
    if (this != &that)
    {
      if (managed_)
        HDF_CHECK_ERROR_CODE(H5Pclose, (native_))

      managed_ = true;
      native_  = H5Pcopy(that.native_);
    }
    return *this;
  }
  properties& operator=(      properties&& temp) noexcept
  {
    if (this != &temp)
    {
      if (managed_)
        HDF_CHECK_ERROR_CODE(H5Pclose, (native_))

      managed_      = temp.managed_;
      native_       = temp.native_ ;

      temp.managed_ = false;
      temp.native_  = 0;
    }
    return *this;
  }

  // TODO: Move outside class scope.
  template <typename type = std::byte> [[nodiscard]]
  std::vector<type> encode        (const file_access_properties& props = file_access_properties()) const
  {
    std::size_t size;
    H5Pencode2(native_, nullptr                          , &size, props.native());
    std::vector<type> result(size);
    H5Pencode2(native_, static_cast<void*>(result.data()), &size, props.native());
    return result;
  }

  [[nodiscard]]
  hid_t             property_class() const
  {
    return H5Pget_class(native_);
  }

  [[nodiscard]]
  bool              managed       () const
  {
    return managed_;
  }
  [[nodiscard]]
  hid_t             native        () const
  {
    return native_;
  }

protected:
  bool  managed_ = false;
  hid_t native_  = 0;
};

class file_creation_property_list : public properties
{
public:
  file_creation_property_list           ()
  : properties(H5P_FILE_CREATE)
  {

  }
  explicit file_creation_property_list  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  file_creation_property_list           (const file_creation_property_list&  that) = default;
  file_creation_property_list           (      file_creation_property_list&& temp) = default;
  virtual ~file_creation_property_list ()                                          = default;
  file_creation_property_list& operator=(const file_creation_property_list&  that) = default;
  file_creation_property_list& operator=(      file_creation_property_list&& temp) = default;

protected:

};

}
