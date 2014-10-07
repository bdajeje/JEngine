#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics/Texture.hpp>

#include <map>
#include <memory>

enum class Texture {
  DefaultError, // Default returned texture on error
  MenuBackground,
  ButtonBackground, ButtonBackgroundSelected
};

namespace texture {

class TextureManager final
{
  public:

    static void init(const std::string& image_directory);

    /* Get the unique instance */
    static TextureManager& instance() { return *s_instance; }

    static const sf::Texture& get(Texture texture);

  private:

    TextureManager(const std::string& image_directory);

    const sf::Texture& loadTexture(Texture texture);

    const sf::Texture& defaultTexture();

    std::string getFilePath(Texture code);

  private:

    static std::unique_ptr<TextureManager> s_instance;
    static std::map<Texture, std::string> s_filepaths;

    /* Directory when to find fonts */
    std::string m_directory;

    /* Cached textures */
    std::map<Texture, sf::Texture> m_textures;
};

} // texture

#endif // TEXTURE_MANAGER_HPP
