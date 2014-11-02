#include "texture_manager.hpp"

#include "jengine/utils/logging/easylogging++.h"

namespace texture {

std::unique_ptr<TextureManager> TextureManager::s_instance;
std::map<Texture, std::string> TextureManager::s_filepaths = {
  {Texture::MenuBackground, "backgrounds/application.png"},
  {Texture::ButtonBackground, "backgrounds/button.png"},
  {Texture::ButtonBackgroundSelected, "backgrounds/button_selected.png"}
};

void TextureManager::init(const std::string& image_directory)
{
  s_instance.reset( new TextureManager(image_directory) );
}

TextureManager::TextureManager(const std::string& image_directory)
  : m_directory(image_directory)
{}

const TexturePtr TextureManager::get(Texture texture)
{
  TextureManager& instance = TextureManager::instance();

  // Find texture
  auto found = instance.m_textures.find(texture);

  // Found, returns
  if( found != instance.m_textures.end() )
    return found->second;

  return instance.loadTexture(texture);
}

TexturePtr TextureManager::loadTexture(Texture code)
{
  // Convert code to file path
  const std::string& texture_filepath = getFilePath(code);

  // No file path? Take default error texture
  if( texture_filepath.empty() )
    return nullptr;

  // Load texture
  sf::Texture texture;
  if( !texture.loadFromFile( texture_filepath ) )
    LOG(ERROR) << "Can't load texture: " << texture_filepath;

  // Store texture in cache for future calls
  auto texture_ptr = std::make_shared<sf::Texture>(texture);
  m_textures[code] = texture_ptr;

  return texture_ptr;
}

std::string TextureManager::getFilePath(Texture code)
{
  auto found = s_filepaths.find(code);
  if(found == s_filepaths.end())
    return {};

  return m_directory + found->second;
}

} // texture
