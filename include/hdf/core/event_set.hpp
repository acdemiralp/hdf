#pragma once

#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

#include <hdf/core/structs/error_information.hpp>
#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
#ifdef HDF_USE_LATEST
class event_set
{
public:
  event_set           () : managed_(true), native_(H5EScreate())
  {

  }
  explicit event_set  (const hid_t native, const bool managed = false) : managed_(managed), native_(native)
  {

  }
  event_set           (const event_set&  that) = delete;
  event_set           (      event_set&& temp) noexcept
  : managed_(temp.managed_), native_(temp.native_)
  {
    if (managed_)
      HDF_CHECK_ERROR_CODE(H5ESclose, (native_))

    temp.managed_ = false;
    temp.native_  = 0;
  }
  virtual ~event_set  ()
  {
    if (managed_)
      HDF_CHECK_ERROR_CODE(H5ESclose, (native_))
  }
  event_set& operator=(const event_set&  that) = delete;
  event_set& operator=(      event_set&& temp) noexcept
  {
    if (managed_)
      HDF_CHECK_ERROR_CODE(H5ESclose, (native_))

    managed_      = temp.managed_;
    native_       = temp.native_ ;

    temp.managed_ = false;
    temp.native_  = 0;

    return *this;
  }

  [[nodiscard]]
  std::size_t                    count            (const std::uint64_t timeout) const
  {
    std::size_t result;
    HDF_CHECK_ERROR_CODE(H5ESget_count     , (native_, &result))
    return result;
  }
  [[nodiscard]]
  std::uint64_t                  operation_counter() const
  {
    std::uint64_t result;
    HDF_CHECK_ERROR_CODE(H5ESget_op_counter, (native_, &result))
    return result;
  }
  [[nodiscard]]
  bool                           error_occurred   () const
  {
    bool result;
    HDF_CHECK_ERROR_CODE(H5ESget_err_status, (native_, &result))
    return result;
  }
  [[nodiscard]]
  std::size_t                    error_count      () const
  {
    std::size_t result;
    HDF_CHECK_ERROR_CODE(H5ESget_err_count , (native_, &result))
    return result;
  }
  [[nodiscard]]
  std::vector<error_information> error_information() const
  {
    std::vector<hdf::error_information> result (error_count());
    std::size_t                         cleared(0); // Unused (always equal to error_count()).
    HDF_CHECK_ERROR_CODE(H5ESget_err_info  , (native_, result.size(), result.data(), &cleared))
    return result;
  }
  [[nodiscard]]
  std::pair<std::size_t, bool>   wait             (const std::uint64_t timeout) const
  {
    std::pair<std::size_t, bool> result;
    HDF_CHECK_ERROR_CODE(H5ESwait          , (native_, timeout, &result.first, &result.second))
    return result;
  }

  [[nodiscard]]
  bool                           managed          () const
  {
    return managed_;
  }
  [[nodiscard]]
  hid_t                          native           () const
  {
    return native_;
  }

protected:
  bool  managed_ = false;
  hid_t native_  = 0;
};
#endif
}