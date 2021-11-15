#pragma once

#include <hdf/core/hdf.hpp>

namespace hdf
{
enum class merge_committed_data_type_search
{
  error     = H5O_MCDT_SEARCH_ERROR,
  continue_ = H5O_MCDT_SEARCH_CONT ,
  stop      = H5O_MCDT_SEARCH_STOP
};
}