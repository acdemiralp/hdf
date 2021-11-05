#pragma once

#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
using group_information = H5G_info_t;

class group
{
public:
  group           ()
  : managed_(true)
  {
    H5Gcreate_anon     ();
    H5Gcreate2         ();
    H5Gopen2           ();

    H5Gget_info_by_idx ();
    H5Gget_info_by_name();

    H5Gget_create_plist();
  }
  explicit group  (const hid_t native, const bool managed = false)
  : managed_(managed), native_(native)
  {
    
  }
  group           (const group&  that) = delete;
  group           (      group&& temp) noexcept
  : managed_(temp.managed_), native_(temp.native_)
  {
    temp.managed_ = false;
    temp.native_  = 0;
  }
  virtual ~group  ()
  {
    if (managed_)
      HDF_CHECK_ERROR_CODE(H5Gclose, (native_))
  }
  group& operator=(const group&  that) = delete;
  group& operator=(      group&& temp) noexcept
  {
    if (this != &temp)
    {
      if (managed_)
        HDF_CHECK_ERROR_CODE(H5Gclose, (native_))

      managed_      = temp.managed_;
      native_       = temp.native_ ;

      temp.managed_ = false;
      temp.native_  = 0;
    }
    return *this;
  }

  [[nodiscard]]
  group_information information() const
  {
    group_information result;
    HDF_CHECK_ERROR_CODE(H5Gget_info, (native_, &result))
    return result;
  }

  void              flush      () const
  {
    HDF_CHECK_ERROR_CODE(H5Gflush  , (native_))
  }
  void              refresh    () const
  {
    HDF_CHECK_ERROR_CODE(H5Grefresh, (native_))
  }

  [[nodiscard]]
  bool              managed    () const
  {
    return managed_;
  }
  [[nodiscard]]
  hid_t             native     () const
  {
    return native_;
  }

protected:
  bool  managed_ = false;
  hid_t native_  = 0;
};
}