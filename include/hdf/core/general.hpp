#pragma once

#include <cstddef>

#include <hdf/core/structs/allocation_stats.hpp>
#include <hdf/core/structs/free_list_limits.hpp>
#include <hdf/core/structs/free_list_sizes.hpp>
#include <hdf/core/structs/version.hpp>
#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
inline void             initialize             ()
{
  HDF_CHECK_ERROR_CODE(H5open , ())
}
inline void             finalize               ()
{
  HDF_CHECK_ERROR_CODE(H5close, ())
}

inline version          get_version            ()
{
  version result;
  HDF_CHECK_ERROR_CODE(H5get_libversion, (&result.major, &result.minor, &result.release))
  return result;
}
inline void             check_version          (const version& version)
{
  HDF_CHECK_ERROR_CODE(H5check_version, (version.major, version.minor, version.release))
}
inline bool             is_version_greater_than(const version& version)
{
  return H5_VERSION_GE(version.major, version.minor, version.release);
}
inline bool             is_version_less_than   (const version& version)
{
  return H5_VERSION_LE(version.major, version.minor, version.release);
}

inline bool             is_thread_safe         ()
{
  bool result;
  HDF_CHECK_ERROR_CODE(H5is_library_threadsafe, (&result))
  return result;
}
inline void             do_not_at_exit         ()
{
  HDF_CHECK_ERROR_CODE(H5dont_atexit, ())
}
inline void             garbage_collect        ()
{
  HDF_CHECK_ERROR_CODE(H5garbage_collect, ())
}

inline allocation_stats get_allocation_stats   ()
{
  allocation_stats result;
  HDF_CHECK_ERROR_CODE(H5get_alloc_stats, (&result))
  return result;
}
inline free_list_sizes  get_free_list_sizes    ()
{
  free_list_sizes result;
  HDF_CHECK_ERROR_CODE(H5get_free_list_sizes, (
    &result.regular, 
    &result.array  , 
    &result.block  , 
    &result.factory))
  return result;
}
inline void             set_free_list_limits   (const free_list_limits& limits)
{
  HDF_CHECK_ERROR_CODE(H5set_free_list_limits, (
    limits.regular_global, 
    limits.regular_list  , 
    limits.array_global  , 
    limits.array_list    , 
    limits.block_global  , 
    limits.block_list    ))
}

template <typename type>
type*                   allocate_memory        (const std::size_t size, const bool clear)
{
  return static_cast<type*>(H5allocate_memory(size, clear));
}
template <typename type>
type*                   resize_memory          (type* memory, const std::size_t size)
{
  return static_cast<type*>(H5resize_memory(static_cast<void*>(memory), size));
}
template <typename type>
void                    free_memory            (type* memory)
{
  HDF_CHECK_ERROR_CODE(H5free_memory, (static_cast<void*>(memory)))
}
}