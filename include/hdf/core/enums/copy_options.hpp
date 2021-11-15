#pragma once

#include <cstdint>

#include <hdf/core/utility/bitset_enum.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
enum class copy_options : std::uint32_t
{
  shallow_hierarchy         = H5O_COPY_SHALLOW_HIERARCHY_FLAG    ,
  expand_soft_link          = H5O_COPY_EXPAND_SOFT_LINK_FLAG     ,
  expand_external_link      = H5O_COPY_EXPAND_EXT_LINK_FLAG      ,
  expand_reference          = H5O_COPY_EXPAND_REFERENCE_FLAG     ,
  without_attributes        = H5O_COPY_WITHOUT_ATTR_FLAG         ,
  preserve_null_flag        = H5O_COPY_PRESERVE_NULL_FLAG        ,
  merge_committed_data_type = H5O_COPY_MERGE_COMMITTED_DTYPE_FLAG
};

template <>
struct is_bitset_enum<copy_options> : std::true_type {};
}