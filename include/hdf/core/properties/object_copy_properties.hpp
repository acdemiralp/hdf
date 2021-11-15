#pragma once

#include <cstdint>
#include <functional>
#include <string>

#include <hdf/core/enums/copy_options.hpp>
#include <hdf/core/enums/merge_committed_data_type_search.hpp>
#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class object_copy_properties : public properties
{
public:
  using callback_type = std::function<merge_committed_data_type_search()>;

  object_copy_properties           ()
  : properties(object_copy_properties_class)
  {

  }
  explicit object_copy_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit object_copy_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  object_copy_properties           (const object_copy_properties&  that) = default;
  object_copy_properties           (      object_copy_properties&& temp) = default;
 ~object_copy_properties           () override                           = default;
  object_copy_properties& operator=(const object_copy_properties&  that) = default;
  object_copy_properties& operator=(      object_copy_properties&& temp) = default;

  [[nodiscard]]
  copy_options         get_copy_object                              () const
  {
    std::uint32_t result;
    HDF_CHECK_ERROR_CODE(H5Pget_copy_object, (native_, &result))
    return static_cast<copy_options>(result);
  }
  void                 set_copy_object                              (const copy_options options) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_copy_object, (native_, static_cast<std::uint32_t>(options)))
  }

  [[nodiscard]]
  const callback_type& get_merge_committed_data_type_search_callback() const
  {
    // Unused. Just return the std::function instead.
    //H5O_mcdt_search_cb_t callback;
    //void*                data    ;
    //HDF_CHECK_ERROR_CODE(H5Pget_mcdt_search_cb, (native_, &callback, &data))
    return callback_;
  }
  void                 set_merge_committed_data_type_search_callback(const callback_type& callback)
  {
    callback_ = callback;
    HDF_CHECK_ERROR_CODE(H5Pset_mcdt_search_cb, (native_, [ ] (void* data)
    {
      const auto this_object = static_cast<object_copy_properties*>(data);
      return static_cast<H5O_mcdt_search_ret_t>(this_object->callback_());
    }, this))
  }
  
  void                 add_merge_committed_data_type_path           (const std::string& path) const
  {
    HDF_CHECK_ERROR_CODE(H5Padd_merge_committed_dtype_path  , (native_, path.c_str()))
  }
  void                 free_merge_committed_data_type_paths         () const
  {
    HDF_CHECK_ERROR_CODE(H5Pfree_merge_committed_dtype_paths, (native_))
  }

protected:
  callback_type callback_;
};
}