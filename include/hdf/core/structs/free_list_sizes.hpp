#pragma once

#include <cstddef>

namespace hdf
{
struct free_list_sizes
{
  std::size_t regular = 0;
  std::size_t array   = 0;
  std::size_t block   = 0;
  std::size_t factory = 0;
};
}