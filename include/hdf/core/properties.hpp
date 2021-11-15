#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>
#include <hdf/core/property_class.hpp>

namespace hdf
{
class file_access_properties;

class properties
{
public:
  using iterate_function_type = std::function<herr_t(const properties&, const std::string&)>;

  explicit properties   (const property_class& property_class)
  : managed_(true)   , native_(H5Pcreate(property_class.native()))
  {
    
  }
  explicit properties   (const void* encoded)
  : managed_(true)   , native_(H5Pdecode(encoded))
  {
    
  }
  explicit properties   (const hid_t native, const bool managed)
  : managed_(managed), native_(native)
  {
    
  }
  properties            (const properties&  that)
  : managed_(true), native_(H5Pcopy(that.native_))
  {
    
  }
  properties            (      properties&& temp) noexcept
  : managed_(temp.managed_), native_(temp.native_)
  {
    temp.managed_ = false;
    temp.native_  = 0;
  }
  virtual ~properties   ()
  {
    if (managed_)
      HDF_CHECK_ERROR_CODE(H5Pclose, (native_))
  }
  properties& operator= (const properties&  that)
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
  properties& operator= (      properties&& temp) noexcept
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
  friend bool operator==(const properties&  lhs, const properties& rhs) noexcept
  {
    return H5Pequal(lhs.native_, rhs.native_);
  }
  friend bool operator!=(const properties&  lhs, const properties& rhs) noexcept
  {
    return !(lhs == rhs);
  }

  template <typename type = std::byte> [[nodiscard]]
  std::vector<type> encode        (const file_access_properties& props) const;

#ifdef HDF_USE_LATEST
  [[nodiscard]]
  bool              collective    () const
  {
    bool result;
    HDF_CHECK_ERROR_CODE(H5Pget_all_coll_metadata_ops, (native_, &result))
    return result;
  }
  void              set_collective(const bool collective) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_all_coll_metadata_ops, (native_, collective))
  }
#endif

  [[nodiscard]]
  bool              is_class      (const property_class& property_class) const
  {
    return H5Pisa_class(native_, property_class.native());
  }
  [[nodiscard]]
  property_class    property_class() const
  {
    return hdf::property_class(H5Pget_class(native_), false); // Unmanaged.
  }

  [[nodiscard]]
  std::size_t       size          () const
  {
    std::size_t result;
    HDF_CHECK_ERROR_CODE(H5Pget_nprops, (native_, &result))
    return result;
  }
  [[nodiscard]]
  std::size_t       property_size (const std::string& name) const
  {
    std::size_t value;
    HDF_CHECK_ERROR_CODE(H5Pget_size, (native_, name.c_str(), &value))
    return value;
  }
  [[nodiscard]]
  bool              exists        (const std::string& name) const
  {
    return H5Pexist(native_, name.c_str());
  }

  template <typename type> [[nodiscard]]
  type              get           (const std::string& name) const
  {
    type value;
    H5Pget(native_, name.c_str(), static_cast<void*>(&value));
    return value;
  }
  template <typename type>
  void              set           (const std::string& name, const type&       value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset, (native_, name.c_str(), &value))
  }
  void              copy          (const std::string& name, const properties& that ) const
  {
    HDF_CHECK_ERROR_CODE(H5Pcopy_prop, (native_, that.native_, name.c_str()))
  }
  void              remove        (const std::string& name) const
  {
    HDF_CHECK_ERROR_CODE(H5Premove, (native_, name.c_str()))
  }

  void              iterate       (iterate_function_type function, std::int32_t start_index = 0) const
  {
    HDF_CHECK_ERROR_CODE(H5Piterate, (native_, &start_index, [ ] (const hid_t id, const char* name, void* data)
    {
      return static_cast<iterate_function_type*>(data)->operator()(properties(id, false), name); // Unmanaged.
    }, &function))
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
}
