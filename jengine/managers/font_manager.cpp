#include "font_manager.hpp"

#include "jengine/managers/configuration_manager.hpp"
#include "jengine/utils/logging/easylogging++.h"
#include "jengine/utils/directory.hpp"

namespace font {

std::unique_ptr<FontManager> FontManager::s_instance;

void FontManager::init(const std::string& font_directory)
{
  s_instance.reset( new FontManager(font_directory) );
}

FontManager::FontManager(const std::string& font_directory)
  : m_directory( utils::ensureDirectoryEnd(font_directory ))
{
  const auto default_font = utils::Font::FreeMono;
  if(!loadFont(default_font))
    LOG(ERROR) << "Can't load default font !";
  m_default_font = m_fonts[default_font];
}

const sf::Font& FontManager::getFont(utils::Font font_name)
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

bool FontManager::loadFont( utils::Font font_name )
{
  const std::string& font_path = getFontFilePath(font_name);

  sf::Font font;
  if(!font.loadFromFile( font_path )) {
    LOG(ERROR) << "Font can't be loaded: " << font_path;
    return false;
  }

  //LOG(DEBUG) << "Font loaded: " << font_path;
  m_fonts[font_name] = std::move(font);
  return true;
}

std::string FontManager::getFontFilePath(utils::Font font_name) const
{
  std::string font_path = m_directory;

  switch( font_name )
  {
    case utils::Font::FreeMono: font_path += "FreeMono.ttf"; break;
    default:
    {
      LOG(ERROR) << "Trying to load an unknown font: " << font_name;
      return {};
    }
  }

  return font_path;
}

} // namespace font
