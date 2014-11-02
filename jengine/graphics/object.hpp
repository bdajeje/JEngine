#ifndef JENGINE_OBJECT_HPP
#define JENGINE_OBJECT_HPP

#include <vector>

#include <SFML/Graphics/Drawable.hpp>

#include "jengine/utils/logging/easylogging++.h"

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

  ObjectProperties(sf::Vector2f position, sf::Vector2f size)
    : ObjectProperties(position.x, position.y, size.x, size.y)
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
    virtual ~Object() = default;

    /* Set this element as visible */
    void show() { m_shown = true; }

    /* Hide this element */
    void hide() { m_shown = false; }

    void select() { m_selected = true; }

    void unselect() { m_selected = false; }

    /* Is this element visible ? */
    bool isVisible() const { return m_shown; }

    bool isSelected() const { return m_selected; }

  private:

    /* Is this element visible */
    bool m_shown {true};

    bool m_selected {false};
};

} // namespace graphics

#endif // JENGINE_OBJECT_HPP
