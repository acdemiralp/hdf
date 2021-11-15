#pragma once

#include <cstdint>

#include <hdf/core/enums/character_set.hpp>
#include <hdf/core/hdf.hpp>
#include <hdf/core/properties.hpp>

namespace hdf
{
class attribute_creation_properties : public properties
{
public:
  attribute_creation_properties           ()
  : properties(attribute_creation_properties_class)
  {

  }
  explicit attribute_creation_properties  (const void* encoded)
  : properties(encoded)
  {
    
  }
  explicit attribute_creation_properties  (const hid_t native, const bool managed = false)
  : properties(native, managed)
  {
    
  }
  attribute_creation_properties           (const attribute_creation_properties&  that) = default;
  attribute_creation_properties           (      attribute_creation_properties&& temp) = default;
 ~attribute_creation_properties           () override                                  = default;
  attribute_creation_properties& operator=(const attribute_creation_properties&  that) = default;
  attribute_creation_properties& operator=(      attribute_creation_properties&& temp) = default;

  [[nodiscard]]
  character_set character_encoding           () const
  {
    H5T_cset_t result;
    HDF_CHECK_ERROR_CODE(H5Pget_char_encoding, (native_, &result))
    return static_cast<character_set>(result);
  }
  void          set_character_encoding       (const character_set value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_char_encoding, (native_, static_cast<H5T_cset_t>(value)))
  }

  [[nodiscard]]
  bool          create_intermediate_group    () const
  {
    std::uint32_t result;
    HDF_CHECK_ERROR_CODE(H5Pget_create_intermediate_group, (native_, &result))
    return result != 0;
  }
  void          set_create_intermediate_group(const bool value) const
  {
    HDF_CHECK_ERROR_CODE(H5Pset_create_intermediate_group, (native_, value))
  }
};
}