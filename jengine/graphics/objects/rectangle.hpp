#ifndef JENGINE_RECTANGLE_HPP
#define JENGINE_RECTANGLE_HPP

#include <SFML/Graphics/RectangleShape.hpp>

#include "jengine/graphics/object.hpp"

namespace graphics {

class Rectangle : public Object
                , public sf::RectangleShape
{
  public:

    Rectangle(const sf::Vector2f size,
              const sf::Color& background_color, const sf::Color& border_color);
};

} // graphics

#endif // JENGINE_RECTANGLE_HPP
