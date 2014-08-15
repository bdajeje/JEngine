#include "font_manager.hpp"

#include "managers/configuration_manager.hpp"
#include "utils/logging/easylogging++.h"
#include "utils/directory.hpp"

namespace font {

FontManager& FontManager::instance()
{
  static FontManager s_instance(ConfigurationManager::instance().fontDirectory() + "fonts/");
  return s_instance;
}

FontManager::FontManager(const std::string& font_directory)
  : m_directory( utils::ensureDirectoryEnd(font_directory ))
{
  loadFont(Font::FreeMono);
  m_default_font = getFont(Font::FreeMono);
}

const sf::Font& FontManager::getFont(Font font_name)
{
  FontManager& instance = FontManager::instance();

  auto iterator = instance.m_fonts.find(font_name);
  if(iterator == instance.m_fonts.end() &&
     !instance.loadFont(font_name))
  {
    LOG(ERROR) << "Can't load font " << font_name;
    return instance.m_default_font;
  }

  return iterator->second;
}

bool FontManager::loadFont( Font font_name )
{
  sf::Font font;
  if(!font.loadFromFile( getFontFilePath(font_name) ))
    return false;

  m_fonts[font_name] = std::move(font);
  return true;
}

std::string FontManager::getFontFilePath(Font font_name) const
{
  std::string font_path = m_directory;

  switch( font_name )
  {
    case Font::FreeMono: font_path += "FreeMono.ttf"; break;
    default:
    {
      LOG(ERROR) << "Trying to load an unknown font: " << font_name;
      return {};
    }
  }

  return font_path;
}

} // namespace font
