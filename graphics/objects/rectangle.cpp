#include "rectangle.hpp"

namespace graphics {

Rectangle::Rectangle(uint width, uint height,
                     const sf::Color& background_color, const sf::Color& border_color)
  : sf::RectangleShape{sf::Vector2f(width, height)}
{ LOG(DEBUG) << "rectangle";
  setFillColor( background_color );
  setOutlineColor( border_color );
}

} // graphics
