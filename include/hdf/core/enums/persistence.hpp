#pragma once

#include <hdf/core/hdf.hpp>

namespace hdf
{
enum class persistence
{
  hard = H5T_PERS_HARD,
  soft = H5T_PERS_SOFT
};
}