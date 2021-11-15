#pragma once

#include <cstdint>

namespace hdf
{
enum class link_access_flags : std::uint32_t
{
  read_only  = 0x0000u,
  read_write = 0x0001u,
  default_   = 0xffffu
};
}