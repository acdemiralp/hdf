#pragma once

#include <cstdint>

#include <hdf/core/structs/filter_class.hpp>
#include <hdf/core/structs/filter_information.hpp>
#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
inline void               register_filter  (const filter_class& filter   )
{
  HDF_CHECK_ERROR_CODE(H5Zregister  , (&filter  ))
}
inline void               unregister_filter(const std::int32_t  filter_id)
{
  HDF_CHECK_ERROR_CODE(H5Zunregister, (filter_id))
}

inline bool               filter_available (const std::int32_t  filter_id)
{
  return H5Zfilter_avail(filter_id) > 0;
}
inline filter_information filter_info      (const std::int32_t  filter_id)
{
  std::uint32_t flags;
  HDF_CHECK_ERROR_CODE(H5Zget_filter_info, (filter_id, &flags))
  return filter_information
  {
    static_cast<bool>(flags & H5Z_FILTER_CONFIG_ENCODE_ENABLED),
    static_cast<bool>(flags & H5Z_FILTER_CONFIG_DECODE_ENABLED)
  };
}
}