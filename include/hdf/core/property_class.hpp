#pragma once

#include <cstddef>
#include <functional>
#include <string>

#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
class property_class
{
public:
  using create_function_type  = std::function<herr_t(hid_t)>;
  using copy_function_type    = std::function<herr_t(hid_t, hid_t)>;
  using close_function_type   = std::function<herr_t(hid_t)>;
  using iterate_function_type = std::function<herr_t(hid_t, const std::string&)>;

  property_class(
    const property_class&       parent         ,
    const std::string&          name           ,
    const create_function_type& create_function,
    const copy_function_type&   copy_function  ,
    const close_function_type&  close_function )
  : managed_        (true           )
  , native_         (H5Pcreate_class(parent.native(), name.c_str(), 
    [ ] (const hid_t id, void* data)
    {
      return static_cast<property_class*>(data)->create_function_(id);
    },
    this,
    [ ] (const hid_t destination, const hid_t source, void* data)
    {
      return static_cast<property_class*>(data)->copy_function_  (destination, source);
    },
    this,
    [ ] (const hid_t id, void* data)
    {
      return static_cast<property_class*>(data)->close_function_ (id);
    },
    this))
  , create_function_(create_function)
  , copy_function_  (copy_function  )
  , close_function_ (close_function )
  {
  
  }
  explicit property_class   (const hid_t native, const bool managed = false)
  : managed_(managed), native_(native)
  {
    
  }
  property_class            (const property_class&  that) = delete;
  property_class            (      property_class&& temp) noexcept
  : managed_(temp.managed_), native_(temp.native_)
  {
    temp.managed_ = false;
    temp.native_  = 0    ;
  }
  virtual ~property_class   ()
  {
    if (managed_)
      HDF_CHECK_ERROR_CODE(H5Pclose_class, (native_))
  }
  property_class& operator= (const property_class&  that) = delete;
  property_class& operator= (      property_class&& temp) noexcept
  {
    if (this != &temp)
    {
      if (managed_)
        HDF_CHECK_ERROR_CODE(H5Pclose_class, (native_))

      managed_      = temp.managed_;
      native_       = temp.native_ ;

      temp.managed_ = false;
      temp.native_  = 0    ;
    }
    return *this;
  }
  friend bool     operator==(const property_class&  lhs, const property_class& rhs) noexcept
  {
    return H5Pequal(lhs.native_, rhs.native_);
  }
  friend bool     operator!=(const property_class&  lhs, const property_class& rhs) noexcept
  {
    return !(lhs == rhs);
  }

  [[nodiscard]]
  std::string    name         () const
  {
    const auto raw_result = H5Pget_class_name(native_);
    auto result = std::string(raw_result);
    HDF_CHECK_ERROR_CODE(H5free_memory(raw_result))
    return result;
  }
  [[nodiscard]]
  property_class parent       () const
  {
    return property_class(H5Pget_class_parent(native_), false); // Unmanaged.
  }

  [[nodiscard]]
  std::size_t    size         () const
  {
    std::size_t result;
    HDF_CHECK_ERROR_CODE(H5Pget_nprops, (native_, &result))
    return result;
  }
  [[nodiscard]]
  std::size_t    property_size(const std::string& name) const
  {
    std::size_t value;
    HDF_CHECK_ERROR_CODE(H5Pget_size, (native_, name.c_str(), &value))
    return value;
  }
  [[nodiscard]]
  bool           exists       (const std::string& name) const
  {
    return H5Pexist(native_, name.c_str());
  }
  
  void           copy         (const std::string& name, const property_class& that) const
  {
    HDF_CHECK_ERROR_CODE(H5Pcopy_prop, (native_, that.native_, name.c_str()))
  }
  void           remove       (const std::string& name) const
  {
    HDF_CHECK_ERROR_CODE(H5Punregister, (native_, name.c_str()))
  }

  void           iterate      (iterate_function_type function, std::int32_t start_index = 0) const
  {
    HDF_CHECK_ERROR_CODE(H5Piterate, (native_, &start_index, [ ] (const hid_t id, const char* name, void* data) -> herr_t
    {
      return static_cast<iterate_function_type*>(data)->operator()(id, name);
    }, &function))
  }

  [[nodiscard]]
  bool           managed      () const
  {
    return managed_;
  }
  [[nodiscard]]
  hid_t          native       () const
  {
    return native_;
  }

protected:
  bool                  managed_          = false;
  hid_t                 native_           = 0 ;
  create_function_type  create_function_  = {};
  copy_function_type    copy_function_    = {};
  close_function_type   close_function_   = {};
};

inline const property_class null_property_class                 = property_class(0                    , false);
inline const property_class attribute_access_property_class     = property_class(H5P_ATTRIBUTE_ACCESS , false);
inline const property_class attribute_creation_properties_class = property_class(H5P_ATTRIBUTE_CREATE , false);
inline const property_class data_type_access_properties_class   = property_class(H5P_DATATYPE_ACCESS  , false);
inline const property_class data_type_creation_properties_class = property_class(H5P_DATATYPE_CREATE  , false);
inline const property_class dataset_access_properties_class     = property_class(H5P_DATASET_ACCESS   , false);
inline const property_class dataset_creation_properties_class   = property_class(H5P_DATASET_CREATE   , false);
inline const property_class dataset_transfer_properties_class   = property_class(H5P_DATASET_XFER     , false);
inline const property_class file_access_properties_class        = property_class(H5P_FILE_ACCESS      , false);
inline const property_class file_creation_properties_class      = property_class(H5P_FILE_CREATE      , false);
inline const property_class file_mount_properties_class         = property_class(H5P_FILE_MOUNT       , false);
inline const property_class group_access_properties_class       = property_class(H5P_GROUP_ACCESS     , false);
inline const property_class group_creation_properties_class     = property_class(H5P_GROUP_CREATE     , false);
inline const property_class link_access_properties_class        = property_class(H5P_LINK_ACCESS      , false);
inline const property_class link_creation_properties_class      = property_class(H5P_LINK_CREATE      , false);
inline const property_class map_access_properties_class         = property_class(H5P_MAP_ACCESS       , false);
inline const property_class map_creation_properties_class       = property_class(H5P_MAP_CREATE       , false);
inline const property_class object_copy_properties_class        = property_class(H5P_OBJECT_COPY      , false);
inline const property_class object_creation_properties_class    = property_class(H5P_OBJECT_CREATE    , false);
inline const property_class reference_access_properties_class   = property_class(H5P_REFERENCE_ACCESS , false);
inline const property_class string_creation_properties_class    = property_class(H5P_STRING_CREATE    , false);
inline const property_class vol_initialization_properties_class = property_class(H5P_VOL_INITIALIZE   , false);
}