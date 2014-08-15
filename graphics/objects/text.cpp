#include "text.hpp"

namespace graphics {

Text::Text(const std::string& text, const TextProperties& properties)
{
  setFont( font::FontManager::getFont(properties.font) );
  setCharacterSize(properties.size);
  setColor(properties.color);
  setStyle(properties.style);
  setString(text);
}

} // graphics
