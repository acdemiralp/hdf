#pragma once

#include <cstddef>

#include <hdf/core/enums/creation_order.hpp>
#include <hdf/core/structs/phase_change.hpp>
#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{

class object_creation_properties : public properties
{
public:
  object_creation_properties           ()
  : properties(object_creation_properties_class)
  {

  }
  explicit object_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit object_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  object_creation_properties           (const object_creation_properties&  that) = default;
  object_creation_properties           (      object_creation_properties&& temp) = default;
 ~object_creation_properties           () override                               = default;
  object_creation_properties& operator=(const object_creation_properties&  that) = default;
  object_creation_properties& operator=(      object_creation_properties&& temp) = default;

  [[nodiscard]]
  creation_order creation_order    () const
  {
    std::uint32_t result;
    HDF_CHECK_ERROR_CODE(H5Pget_attr_creation_order, (native_, &result))
    return static_cast<hdf::creation_order>(result);
  }
  void           set_creation_order(const hdf::creation_order value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_attr_creation_order, (native_, static_cast<std::uint32_t>(value)))
  }

  [[nodiscard]]
  phase_change   phase_change      () const
  {
    hdf::phase_change result;
    HDF_CHECK_ERROR_CODE(H5Pget_attr_phase_change, (native_, &result.maximum_compact_storage, &result.minimum_dense_storage))
    return result;
  }
  void           set_phase_change  (const hdf::phase_change& value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_attr_phase_change, (native_, value.maximum_compact_storage, value.minimum_dense_storage))
  }
  
  [[nodiscard]]
  bool           track_times       () const
  {
    bool result;
    HDF_CHECK_ERROR_CODE(H5Pget_obj_track_times, (native_, &result))
    return result;
  }
  void           set_track_times   (const bool value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_obj_track_times, (native_, value))
  }
};
}