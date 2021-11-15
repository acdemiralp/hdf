#pragma once

#include <hdf/core/hdf.hpp>

namespace hdf
{
enum class character_set
{
  error = H5T_CSET_ERROR,
  ascii = H5T_CSET_ASCII,
  utf8  = H5T_CSET_UTF8
};
}