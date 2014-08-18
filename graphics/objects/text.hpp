#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics/Text.hpp>

#include "graphics/object.hpp"
#include "managers/font_manager.hpp"

namespace graphics {

/* Holds properties of a text */
struct TextProperties
{
  font::Font font;
  uint size;
  sf::Color color;
  sf::Uint32 style;
};

/* Represents some text */
class Text : public Object,
             public sf::Text
{
  public:

    Text( const std::string& text, const TextProperties& properties );

    /* Get size */
    sf::Vector2f getSize() const;
};

} // graphics

#endif // TEXT_HPP
