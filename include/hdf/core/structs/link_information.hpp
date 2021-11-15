#pragma once

#include <cstdint>

namespace hdf
{
struct link_information
{
  std::uint32_t estimate_links       = 0;
  std::uint32_t estimate_name_length = 0;
};
}