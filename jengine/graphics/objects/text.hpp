#ifndef JENGINE_TEXT_HPP
#define JENGINE_TEXT_HPP

#include <SFML/Graphics/Text.hpp>

#include "jengine/graphics/object.hpp"
#include "jengine/managers/font_manager.hpp"
#include "jengine/utils/fonts.hpp"

namespace graphics {

/* Holds properties of a text */
struct TextProperties
{
  utils::Font font;
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

#endif // JENGINE_TEXT_HPP
