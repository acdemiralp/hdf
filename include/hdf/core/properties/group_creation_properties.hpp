#pragma once

#include <cstddef>
#include <cstdint>

#include <hdf/core/enums/creation_order.hpp>
#include <hdf/core/structs/link_information.hpp>
#include <hdf/core/structs/phase_change.hpp>
#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class group_creation_properties : public properties
{
public:
  group_creation_properties           ()
  : properties(group_creation_properties_class)
  {

  }
  explicit group_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit group_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  group_creation_properties           (const group_creation_properties&  that) = default;
  group_creation_properties           (      group_creation_properties&& temp) = default;
 ~group_creation_properties           () override                              = default;
  group_creation_properties& operator=(const group_creation_properties&  that) = default;
  group_creation_properties& operator=(      group_creation_properties&& temp) = default;

  [[nodiscard]]
  creation_order   creation_order          () const
  {
    std::uint32_t result;
    HDF_CHECK_ERROR_CODE(H5Pget_link_creation_order, (native_, &result))
    return static_cast<hdf::creation_order>(result);
  }
  void             set_creation_order      (const hdf::creation_order    value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_link_creation_order, (native_, static_cast<std::uint32_t>(value)))
  }

  [[nodiscard]]
  link_information link_information        () const
  {
    hdf::link_information result;
    HDF_CHECK_ERROR_CODE(H5Pget_est_link_info, (native_, &result.estimate_links, &result.estimate_name_length))
    return result;
  }
  void             set_link_information    (const hdf::link_information& value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_est_link_info, (native_, value.estimate_links  , value.estimate_name_length  ))
  }

  [[nodiscard]]
  std::size_t      local_heap_size_hint    () const
  {
    std::size_t result;
    HDF_CHECK_ERROR_CODE(H5Pget_local_heap_size_hint, (native_, &result))
    return result;
  }
  void             set_local_heap_size_hint(const std::size_t            value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_local_heap_size_hint, (native_, value))
  }
  
  [[nodiscard]]
  phase_change     phase_change            () const
  {
    hdf::phase_change result;
    HDF_CHECK_ERROR_CODE(H5Pget_link_phase_change, (native_, &result.maximum_compact_storage, &result.minimum_dense_storage))
    return result;
  }
  void             set_phase_change        (const hdf::phase_change&     value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_link_phase_change, (native_, value.maximum_compact_storage, value.minimum_dense_storage))
  }
  
};
}