#ifndef JENGINE_TEXTURE_MANAGER_HPP
#define JENGINE_TEXTURE_MANAGER_HPP

#include <SFML/Graphics/Texture.hpp>

#include <map>
#include <memory>

enum class Texture {
  MenuBackground,
  ButtonBackground, ButtonBackgroundSelected
};

namespace texture {

typedef std::shared_ptr<sf::Texture> TexturePtr;

class TextureManager final
{
  public:

    static void init(const std::string& image_directory);

    /* Get the unique instance */
    static TextureManager& instance() { return *s_instance; }

    static const TexturePtr get(Texture texture);

  private:

    TextureManager(const std::string& image_directory);

    TexturePtr loadTexture(Texture texture);

    std::string getFilePath(Texture code);

  private:

    static std::unique_ptr<TextureManager> s_instance;
    static std::map<Texture, std::string> s_filepaths;

    /* Directory when to find fonts */
    std::string m_directory;

    /* Cached textures */
    std::map<Texture, TexturePtr> m_textures;
};

} // texture

#endif // JENGINE_TEXTURE_MANAGER_HPP
