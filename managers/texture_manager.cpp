#include "texture_manager.hpp"

#include "utils/logging/easylogging++.h"

namespace texture {

std::unique_ptr<TextureManager> TextureManager::s_instance;
std::map<Texture, std::string> TextureManager::s_filepaths = {
  {Texture::DefaultError, "error.png"},
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
{
  loadTexture(Texture::DefaultError);
}

const sf::Texture& TextureManager::get(Texture texture)
{
  TextureManager& instance = TextureManager::instance();

  // Find texture
  auto found = instance.m_textures.find(texture);

  // Found, returns
  if( found != instance.m_textures.end() )
    return found->second;

  return instance.loadTexture(texture);
}

const sf::Texture& TextureManager::loadTexture(Texture code)
{
  // Convert code to file path
  const std::string& texture_filepath = getFilePath(code);

  // No file path? Take default error texture
  if( texture_filepath.empty() )
    return defaultTexture();

  // Load texture
  sf::Texture texture;
  if( !texture.loadFromFile( texture_filepath ) )
  {
    LOG(ERROR) << "Can't load texture: " << texture_filepath;
    texture = defaultTexture();
  }

  // Store texture in cache for future calls
  m_textures[code] = std::move(texture);

  return m_textures[code];
}

const sf::Texture& TextureManager::defaultTexture()
{
  return m_textures[Texture::DefaultError];
}

std::string TextureManager::getFilePath(Texture code)
{
  auto found  = s_filepaths.find(code);
  auto result = (found == s_filepaths.end()) ? s_filepaths.at(Texture::DefaultError) : found->second;
  return m_directory + result;
}

} // texture
