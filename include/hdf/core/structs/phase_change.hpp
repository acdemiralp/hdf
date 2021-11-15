#pragma once

#include <cstdint>

namespace hdf
{
struct phase_change
{
  std::uint32_t maximum_compact_storage = 0;
  std::uint32_t minimum_dense_storage   = 0;
};
}