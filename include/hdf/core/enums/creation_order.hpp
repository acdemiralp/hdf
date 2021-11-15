#pragma once

#include <cstdint>

#include <hdf/core/hdf.hpp>

namespace hdf
{
enum class creation_order : std::uint32_t
{
  tracked = H5P_CRT_ORDER_TRACKED,
  indexed = H5P_CRT_ORDER_INDEXED
};
}