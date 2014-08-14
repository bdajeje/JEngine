#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "defines.hpp"

namespace graphics {
namespace utils {

/* Represents something having a position in a 2D plan */
class Movable
{
  public:

    /* Default constructor */
    Movable() = default;

    /* Constructor
     * \param x position
     * \param y position
     */
    Movable(uint x, uint y);

    /* Destructor */
    virtual ~Movable() = default;

  private:

    /* Position on x axe */
    uint m_x {0};

    /* Position on y axe */
    uint m_y {0};
};

} // utils
} // graphics

#endif // MOVABLE_HPP
