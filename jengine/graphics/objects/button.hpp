#ifndef JENGINE_BUTTON_HPP
#define JENGINE_BUTTON_HPP

#include <SFML/Graphics/RenderTarget.hpp>

#include "jengine/game/utils/tab_indexable.hpp"
#include "jengine/graphics/object.hpp"
#include "jengine/graphics/objects/rectangle.hpp"
#include "jengine/graphics/objects/text.hpp"
#include "jengine/graphics/objects/sprite.hpp"
#include "jengine/graphics/utils/container.hpp"
#include "jengine/graphics/utils/properties.hpp"
#include "jengine/graphics/utils/jdrawable.hpp"

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

    void setBackground( const std::shared_ptr<sf::Texture> texture );
    void setBackgroundSelected( const std::shared_ptr<sf::Texture> texture );

    // Set position of the button
    // Note: Buttons have to take care of their borders.
    //       Their positions are taking into account the size of the borders
    virtual void setPosition(float x, float y);

  protected:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

  private:

    /* Text inside the button */
    Text m_text;

    /* Button background */
    std::unique_ptr<Sprite> m_background_image;

    /* Button background when selected */
    std::unique_ptr<Sprite> m_background_selected_image;
};

} // graphics

#endif // JENGINE_BUTTON_HPP
