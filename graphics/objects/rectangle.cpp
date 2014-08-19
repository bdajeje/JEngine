#include "rectangle.hpp"

namespace graphics {

Rectangle::Rectangle(const sf::Vector2f size,
                     const sf::Color& background_color, const sf::Color& border_color)
  : sf::RectangleShape{ size }
{
  setFillColor( background_color );
  setOutlineColor( border_color );
}

} // graphics
