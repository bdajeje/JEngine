#include "text.hpp"

namespace graphics {

Text::Text(const std::string& text, const TextProperties& properties)
{ LOG(DEBUG) << "text";
  auto font = font::FontManager::getFont(properties.font); LOG(DEBUG) << "10";
  setFont( font );  LOG(DEBUG) << "20";
  setCharacterSize(properties.size);
  setColor(properties.color);
  setStyle(properties.style);
  setString(text);
  LOG(DEBUG) << "text done";
}

} // graphics
