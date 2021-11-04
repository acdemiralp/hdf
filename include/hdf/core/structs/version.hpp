#pragma once

#include <cstdint>

namespace hdf
{
struct version
{
  std::uint32_t major   = 0;
  std::uint32_t minor   = 0;
  std::uint32_t release = 0;
};
}