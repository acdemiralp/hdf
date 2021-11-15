#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>
#include <string>

#include <hdf/core/enums/link_access_flags.hpp>
#include <hdf/core/properties/file_access_properties.hpp>
#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class link_access_properties : public properties
{
public:
  using callback_type = std::function<std::int32_t(const std::string&, const std::string&, const std::string&, const std::string&, link_access_flags, file_access_properties)>;

  link_access_properties           ()
  : properties(link_access_properties_class)
  {

  }
  explicit link_access_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit link_access_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  link_access_properties           (const link_access_properties&  that) = default;
  link_access_properties           (      link_access_properties&& temp) = default;
 ~link_access_properties           () override                           = default;
  link_access_properties& operator=(const link_access_properties&  that) = default;
  link_access_properties& operator=(      link_access_properties&& temp) = default;

  [[nodiscard]]
  link_access_flags      flags                     () const
  {
    std::uint32_t result;
    HDF_CHECK_ERROR_CODE(H5Pget_elink_acc_flags, (native_, &result))
    return static_cast<link_access_flags>(result);
  }
  void                   set_flags                 (const link_access_flags& value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_elink_acc_flags, (native_, static_cast<std::uint32_t>(value)))
  }

  [[nodiscard]]
  std::size_t            maximum_links             () const
  {
    std::size_t result;
    HDF_CHECK_ERROR_CODE(H5Pget_nlinks, (native_, &result))
    return result;
  }
  void                   set_maximum_links         (const std::size_t value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_nlinks, (native_, value))
  }

  [[nodiscard]]
  std::string            prefix                    () const
  {
    std::string result(H5Pget_elink_prefix(native_, nullptr, 0), '\n');
    HDF_CHECK_ERROR_CODE(H5Pget_elink_prefix, (native_, result.data(), result.size()))
    return result;
  }
  void                   set_prefix                (const std::string& value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_elink_prefix, (native_, value.c_str()))
  }

  [[nodiscard]]
  file_access_properties file_access_properties    () const
  {
    return hdf::file_access_properties(H5Pget_elink_fapl(native_), false); // Unmanaged.
  }
  void                   set_file_access_properties(const hdf::file_access_properties& value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_elink_fapl, (native_, value.native()))
  }

  [[nodiscard]]
  const callback_type&   callback                  () const
  {
    // Unused: H5Pget_elink_cb
    return callback_;
  }
  void                   set_callback              (const callback_type& value)
  {
    callback_ = value;
    HDF_CHECK_ERROR_CODE(H5Pset_elink_cb, (native_, [ ] (
      const char*    parent_file_name      , 
      const char*    parent_group_name     , 
      const char*    child_file_name       , 
      const char*    child_object_name     , 
      std::uint32_t* access_flags          , 
      const hid_t    file_access_properties, 
      void*          data                  )
    {
      const auto this_object = static_cast<link_access_properties*>(data);
      return this_object->callback_   (
        std::string                   (parent_file_name              ), 
        std::string                   (parent_group_name             ), 
        std::string                   (child_file_name               ),
        std::string                   (child_object_name             ),
        static_cast<link_access_flags>(*access_flags                 ), 
        hdf::file_access_properties   (file_access_properties, false));
    }, this))
  }

protected:
  callback_type callback_;
};
}