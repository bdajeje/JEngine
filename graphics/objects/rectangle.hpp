#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics/RectangleShape.hpp>

#include "graphics/object.hpp"

namespace graphics {

class Rectangle : public Object
                , public sf::RectangleShape
{
  public:

    Rectangle(const sf::Vector2f size,
              const sf::Color& background_color, const sf::Color& border_color);
};

} // graphics

#endif // RECTANGLE_HPP
