#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include <hdf/core/exception.hpp>
#include <hdf/core/hdf.hpp>

namespace hdf
{
inline std::uint32_t            plugin_path_count  ()
{
  std::uint32_t result;
  HDF_CHECK_ERROR_CODE(H5PLsize, (&result))
  return result;
}
inline std::string              plugin_path        (const std::uint32_t index)
{
  std::string result(H5PLget(index, nullptr, 0), '\n');
  HDF_CHECK_ERROR_CODE(H5PLget, (index, result.data(), result.size()))
  return result;
}
inline std::vector<std::string> plugin_paths       ()
{
  std::vector<std::string> result(plugin_path_count());
  for (std::size_t i = 0; i < result.size(); ++i)
    result[i] = plugin_path(static_cast<std::uint32_t>(i));
  return result;
}

inline void                     append_plugin_path (const std::string&  path)
{
  HDF_CHECK_ERROR_CODE(H5PLappend , (path.c_str()))
}
inline void                     prepend_plugin_path(const std::string&  path)
{
  HDF_CHECK_ERROR_CODE(H5PLprepend, (path.c_str()))
}
inline void                     insert_plugin_path (const std::string&  path, const std::uint32_t index)
{
  HDF_CHECK_ERROR_CODE(H5PLinsert , (path.c_str(), index))
}
inline void                     replace_plugin_path(const std::string&  path, const std::uint32_t index)
{
  HDF_CHECK_ERROR_CODE(H5PLreplace, (path.c_str(), index))
}
inline void                     remove_plugin_path (                          const std::uint32_t index)
{
  HDF_CHECK_ERROR_CODE(H5PLremove , (index))
}

inline std::uint32_t            loading_state      ()
{
  std::uint32_t result;
  HDF_CHECK_ERROR_CODE(H5PLget_loading_state, (&result))
  return result;
}
inline void                     set_loading_state  (const std::uint32_t mask)
{
  HDF_CHECK_ERROR_CODE(H5PLset_loading_state, (mask))
}
}