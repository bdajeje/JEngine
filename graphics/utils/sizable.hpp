#ifndef SIZABLE_HPP
#define SIZABLE_HPP

#include "defines.hpp"

namespace graphics {
namespace utils {

class Sizable
{
  public:

    Sizable( uint width, uint height, bool fixed_size = true );

    bool isFixed() const { return m_fixed_size; }

  private:

    /* Width of the view */
    uint m_width;

    /* Height of the view */
    uint m_height;

    /* Can width/height be modified ? */
    bool m_fixed_size;
};

} // utils
} // graphics

#endif // SIZABLE_HPP
