#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics/RenderTarget.hpp>

#include "game/utils/tab_indexable.hpp"
#include "graphics/object.hpp"
#include "graphics/objects/rectangle.hpp"
#include "graphics/objects/text.hpp"
#include "graphics/objects/sprite.hpp"
#include "graphics/utils/container.hpp"
#include "graphics/utils/properties.hpp"
#include "graphics/utils/jdrawable.hpp"

namespace graphics {

/* Represents a button */
class Button final : public utils::Container,
                     public utils::JDrawable,
                     public game::utils::TabIndexable
{
  public:

    /* Constructor
     * \param text_properties   for the text inside the button
     * \param object_properties for the button
     * \param properties        of the button
     */
    Button( const std::string& text, const TextProperties& text_properties, const ObjectProperties& object_properties, const utils::ContainerProperties& properties = {} );

    // Set background color
    void setBackgroundColor(const sf::Color& color) { m_background.setFillColor( color ); }

    void setBackground( const sf::Texture& texture );
    void setBackgroundSelected( const sf::Texture& texture );

    // Set position of the button
    // Note: Buttons have to take care of their borders.
    //       Their positions are taking into account the size of the borders
    virtual void setPosition(float x, float y);

  protected:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

  private:

    /* Text inside the button */
    Text m_text;

    /* Background and borders */
    Rectangle m_background;

    /* Button background */
    std::unique_ptr<Sprite> m_background_image;

    /* Button background when selected */
    std::unique_ptr<Sprite> m_background_selected_image;
};

} // graphics

#endif // BUTTON_HPP
