#ifndef Object_HPP
#define Object_HPP

#include <vector>

#include <SFML/Graphics/Drawable.hpp>

#include "utils/logging/easylogging++.h"

namespace graphics {

/* Helper struct to hold object properties */
struct ObjectProperties
{
  /* Constructor
   * \param x      position to set
   * \param y      position to set
   * \param width  to set
   * \param height to set
   */
  ObjectProperties(float x, float y, float width, float height)
    : position{x, y}
    , size{width, height}
  {}

  sf::Vector2f position;
  sf::Vector2f size;
};

/* Pure base class for all graphical objects */
class Object
{
  public:

    /* Constructor */
    Object() {}

    /* Destructor */
    virtual ~Object() {}

    /* Set this element as visible */
    void show() { m_shown = true; }

    /* Hide this element */
    void hide() { m_shown = false; }

    /* Is this element visible ? */
    bool isVisible() const { return m_shown; }

  private:

    /* Is this element visible */
    bool m_shown {true};
};

} // namespace graphics

#endif // Object_HPP
