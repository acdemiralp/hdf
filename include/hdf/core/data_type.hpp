#pragma once

#include <hdf/core/hdf.hpp>

namespace hdf
{
class data_type
{
public:
  explicit data_type(const hid_t native, const bool managed = false)
  : managed_(managed), native_(native)
  {
    
  }

  [[nodiscard]]
  bool  managed() const
  {
    return managed_;
  }
  [[nodiscard]]
  hid_t native () const
  {
    return native_;
  }

protected:
  bool  managed_ = false;
  hid_t native_  = 0;
};
}