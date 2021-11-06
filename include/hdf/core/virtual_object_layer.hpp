#pragma once

#include <cstdint>
#include <string>

#include <hdf/core/properties/vol_initialization_properties.hpp>
#include <hdf/core/structs/vol_class_information.hpp>
#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
inline bool is_connector_registered(const std::string& name )
{
  return H5VLis_connector_registered_by_name(name.c_str()) > 0;
}
inline bool is_connector_registered(const std::int32_t value)
{
  return H5VLis_connector_registered_by_value(value) > 0;
}

class virtual_object_layer
{
public:
  explicit virtual_object_layer  (const hid_t                  id         )
  : managed_(true), native_(H5VLget_connector_id(id))
  {

  }
  explicit virtual_object_layer  (const std::string&           name       )
  : managed_(true), native_(H5VLget_connector_id_by_name(name.c_str()))
  {
    
  }
  explicit virtual_object_layer  (const std::int32_t           value      )
  : managed_(true), native_(H5VLget_connector_id_by_value(value))
  {
    
  }
  explicit virtual_object_layer  (const vol_class_information& information, const vol_initialization_properties& props = vol_initialization_properties())
  : managed_(true), native_(H5VLregister_connector         (&information, props.native()))
  {
    
  }
  explicit virtual_object_layer  (const std::string&           name       , const vol_initialization_properties& props)
  : managed_(true), native_(H5VLregister_connector_by_name (name.c_str(), props.native()))
  {
    
  }
  explicit virtual_object_layer  (const std::int32_t           value      , const vol_initialization_properties& props)
  : managed_(true), native_(H5VLregister_connector_by_value(value       , props.native()))
  {
    
  }
  explicit virtual_object_layer  (const hid_t native, const bool managed)
  : managed_(managed), native_(native)
  {
    
  }
  virtual_object_layer           (const virtual_object_layer&  that) = delete;
  virtual_object_layer           (      virtual_object_layer&& temp) noexcept
  : managed_(temp.managed_), native_(temp.native_)
  {
    temp.managed_ = false;
    temp.native_  = 0;
  }
  virtual ~virtual_object_layer  ()
  {
    if (managed_)
      HDF_CHECK_ERROR_CODE(H5VLclose, (native_))
  }
  virtual_object_layer& operator=(const virtual_object_layer&  that) = delete;
  virtual_object_layer& operator=(      virtual_object_layer&& temp) noexcept
  {
    if (this != &temp)
    {
      if (managed_)
        HDF_CHECK_ERROR_CODE(H5VLclose, (native_))

      managed_      = temp.managed_;
      native_       = temp.native_ ;

      temp.managed_ = false;
      temp.native_  = 0;
    }
    return *this;
  }

  [[nodiscard]]
  std::string name         () const
  {
    std::string result(H5VLget_connector_name(native_, nullptr, 0), '\n');
    HDF_CHECK_ERROR_CODE(H5VLget_connector_name(native_, result.data(), result.size()))
    return result;
  }

  void        unregister   () const
  {
    HDF_CHECK_ERROR_CODE(H5VLunregister_connector, (native_))
  }

  [[nodiscard]]
  bool        is_registered() const
  {
    return is_connector_registered(name());
  }

  [[nodiscard]]
  bool        managed      () const
  {
    return managed_;
  }
  [[nodiscard]]
  hid_t       native       () const
  {
    return native_;
  }

protected:
  bool  managed_ = false;
  hid_t native_  = 0    ;
};
}