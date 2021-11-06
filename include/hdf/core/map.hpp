#pragma once

#include <hdf/core/properties/dataset_transfer_properties.hpp>
#include <hdf/core/properties/map_access_properties.hpp>
#include <hdf/core/properties/map_creation_properties.hpp>
#include <hdf/core/properties/link_access_properties.hpp>
#include <hdf/core/properties/link_creation_properties.hpp>
#include <hdf/core/data_type.hpp>
#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
class map
{
public:
  map           (
    const hid_t                     location            , 
    const data_type&                key_type            , 
    const data_type&                value_type          , 
    const map_creation_properties&  map_creation_props  = map_creation_properties(), 
    const map_access_properties&    map_access_props    = map_access_properties  ())
  : managed_(true), native_(H5Mcreate_anon(
      location                         , 
      key_type                .native(), 
      value_type              .native(), 
      map_creation_props      .native(),
      map_access_props        .native()))
  {
    
  }
  map           (
    const hid_t                     location            , 
    const std::string&              name                , 
    const data_type&                key_type            , 
    const data_type&                value_type          , 
    const link_creation_properties& link_creation_props = link_creation_properties(), 
    const map_creation_properties&  map_creation_props  = map_creation_properties (), 
    const map_access_properties&    map_access_props    = map_access_properties   ())
  : managed_(true), native_(H5Mcreate(
      location                         , 
      name                    .c_str (), 
      key_type                .native(), 
      value_type              .native(), 
      link_creation_props     .native(), 
      map_creation_props      .native(),
      map_access_props        .native()))
  {
    
  }
  map           (const hid_t location, const std::string& name, const map_access_properties& props = map_access_properties())
  : managed_(true), native_(H5Mopen  (location, name.c_str(), props.native()))
  {
    
  }
  explicit map  (const hid_t native, const bool managed = false)
  : managed_(managed), native_(native)
  {
    
  }
  map           (const map&  that) = delete;
  map           (      map&& temp) noexcept
  : managed_(temp.managed_), native_(temp.native_)
  {
    temp.managed_ = false;
    temp.native_  = 0;
  }
  virtual ~map  ()
  {
    if (managed_)
      HDF_CHECK_ERROR_CODE(H5Mclose, (native_))
  }
  map& operator=(const map&  that) = delete;
  map& operator=(      map&& temp) noexcept
  {
    if (this != &temp)
    {
      if (managed_)
        HDF_CHECK_ERROR_CODE(H5Mclose, (native_))

      managed_      = temp.managed_;
      native_       = temp.native_ ;

      temp.managed_ = false;
      temp.native_  = 0;
    }
    return *this;
  }

  [[nodiscard]]
  data_type               key_type           () const
  {
    return data_type(H5Mget_key_type(native_), true);
  }
  [[nodiscard]]
  data_type               value_type         () const
  {
    return data_type(H5Mget_val_type(native_), true);
  }
  [[nodiscard]]
  map_creation_properties creation_properties() const
  {
    return map_creation_properties(H5Mget_create_plist(native_), true);
  }
  [[nodiscard]]
  map_access_properties   access_properties  () const
  {
    return map_access_properties  (H5Mget_access_plist(native_), true);
  }

  [[nodiscard]]
  bool                    managed            () const
  {
    return managed_;
  }
  [[nodiscard]]
  hid_t                   native             () const
  {
    return native_;
  }

protected:
  bool  managed_ = false;
  hid_t native_  = 0    ;
};
}