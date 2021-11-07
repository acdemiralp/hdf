#pragma once

#include <string>

#include <hdf/core/enums/persistence.hpp>
#include <hdf/core/structs/conversion_function.hpp>
#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
class file;

class data_type
{
public:
  data_type            ()
  {
    H5Tcreate(H5T_class_t(), 42);
  }
  explicit data_type   (const hid_t native, const bool managed)
  : managed_(managed), native_(native)
  {
    
  }
  data_type            (const data_type&  that)
  : managed_(true), native_(H5Tcopy(that.native_))
  {
    
  }
  data_type            (      data_type&& temp) noexcept
  : managed_(temp.managed_), native_(temp.native_)
  {
    temp.managed_ = false;
    temp.native_  = 0;
  }
  virtual ~data_type   ()
  {
    if (managed_)
      HDF_CHECK_ERROR_CODE(H5Tclose, (native_))
  }
  data_type& operator= (const data_type&  that)
  {
    if (this != &that)
    {
      if (managed_)
        HDF_CHECK_ERROR_CODE(H5Tclose, (native_))

      managed_ = true;
      native_  = H5Tcopy(that.native_);
    }
    return *this;
  }
  data_type& operator= (      data_type&& temp) noexcept
  {
    if (this != &temp)
    {
      if (managed_)
        HDF_CHECK_ERROR_CODE(H5Tclose, (native_))
      
      managed_      = temp.managed_;
      native_       = temp.native_ ;
      
      temp.managed_ = false;
      temp.native_  = 0;
    }
    return *this;
  }
  bool       operator==(const data_type&  that) const
  {
    return static_cast<bool>(H5Tequal(native_, that.native_));
  }

  [[nodiscard]]
  bool  committed() const
  {
    return static_cast<bool>(H5Tcommitted(native_));
  }

  void  refresh  () const
  {
    HDF_CHECK_ERROR_CODE(H5Trefresh, (native_))
  }
  void  flush    () const
  {
    HDF_CHECK_ERROR_CODE(H5Tflush  , (native_))
  }
  void  lock     () const
  {
    HDF_CHECK_ERROR_CODE(H5Tlock   , (native_))
  }

  [[nodiscard]]
  bool  managed  () const
  {
    return managed_;
  }
  [[nodiscard]]
  hid_t native   () const
  {
    return native_;
  }

protected:
  bool  managed_ = false;
  hid_t native_  = 0;
};

inline void register_conversion_function(
  const persistence         persistence, 
  const std::string&        name       , 
  const data_type&          source     , 
  const data_type&          target     , 
  const conversion_function function   )
{
  HDF_CHECK_ERROR_CODE(H5Tregister  , (static_cast<H5T_pers_t>(persistence), name.c_str(), source.native(), target.native(), function))
}
inline void unregister_conversion_function(
  const persistence         persistence, 
  const std::string&        name       , 
  const data_type&          source     , 
  const data_type&          target     , 
  const conversion_function function   )
{
  HDF_CHECK_ERROR_CODE(H5Tunregister, (static_cast<H5T_pers_t>(persistence), name.c_str(), source.native(), target.native(), function))
}
}