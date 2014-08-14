#ifndef Object_HPP
#define Object_HPP

#include <vector>

#include <SFML/Graphics/Drawable.hpp>

#include "graphics/utils/movable.hpp"
#include "graphics/utils/sizable.hpp"

namespace graphics {

/* Pure base class for all graphical objects */
class Object : public utils::Sizable, public utils::Movable
{
  public:

    /* Default constructor */
    Object() = default;

    /* Constructor with positions
     * \param x      position to set
     * \param y      position to set
     * \param width  to set
     * \param height to set
     */
    Object(uint x, uint y, uint width, uint height);

    /* Set this element as visible */
    void show() { m_shown = true; }

    /* Hide this element */
    void hide() { m_shown = false; }

    /* Is this element visible ? */
    bool isVisible() const { return m_shown; }

  private:

    /* Is this element visible */
    bool m_shown;
};

} // namespace graphics

#endif // Object_HPP
