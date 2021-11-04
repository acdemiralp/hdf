#pragma once

#include <cstdint>

namespace hdf
{
struct free_list_limits
{
  std::int32_t regular_global = 0;
  std::int32_t regular_list   = 0;
  std::int32_t array_global   = 0;
  std::int32_t array_list     = 0;
  std::int32_t block_global   = 0;
  std::int32_t block_list     = 0;
};
}