#ifndef JENGINE_FONT_MANAGER_HPP
#define JENGINE_FONT_MANAGER_HPP

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Font.hpp>

#include "jengine/utils/fonts.hpp"

namespace font {

/* Takes care of loading and holding fonts */
class FontManager final
{
  public:

    /* Get the unique instance
     * \param font_directory where to find the fonts
     */
    static void init(const std::string& font_directory);

    /* Get the unique instance */
    static FontManager& instance() { return *s_instance; }

    /* Get a font
     * \param font to get
     * \return the font to use or nullptr if the font couldn't be loaded
     * \note This function loads the font if it's not in cache or take it directly from the cache
     */
    static const sf::Font& getFont(utils::Font font);

  private:

    /* Constructor
     * \param font_directory where to find the fonts
     */
    FontManager(const std::string& font_directory);

    /* Load a font */
    bool loadFont( utils::Font font );

    /* Get a font filepath from font constant
     * \param font_name to translate to file path
     * \return a file path to a font or empty string if not found
     */
    std::string getFontFilePath(utils::Font font_name) const;

  private:

    static std::unique_ptr<FontManager> s_instance;

    /* Directory when to find fonts */
    std::string m_directory;

    /* Loaded fonts */
    std::map<utils::Font, sf::Font> m_fonts;

    /* Default font */
    sf::Font m_default_font;
};

} // namespace font

#endif // JENGINE_FONT_MANAGER_HPP
