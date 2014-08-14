#include "sizable.hpp"

namespace graphics {
namespace utils {

Sizable::Sizable( uint width, uint height, bool fixed_size )
  : m_width( width )
  , m_height( height )
  , m_fixed_size( fixed_size )
{}

} // utils
} // graphics
