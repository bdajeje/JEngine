#ifndef Object_HPP
#define Object_HPP

#include <vector>

#include <SFML/Graphics/Drawable.hpp>

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
  ObjectProperties(uint x, uint y, uint width, uint height)
    : x{x}
    , y{y}
    , width{width}
    , height{height}
  {}

  uint x;
  uint y;
  uint width;
  uint height;
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

    /* Is this element visible ? */
    bool isVisible() const { return m_shown; }

  private:

    /* Is this element visible */
    bool m_shown {true};
};

} // namespace graphics

#endif // Object_HPP
