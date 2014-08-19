#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics/RenderTarget.hpp>

#include "graphics/object.hpp"
#include "graphics/objects/rectangle.hpp"
#include "graphics/objects/text.hpp"
#include "graphics/utils/container.hpp"
#include "graphics/utils/properties.hpp"
#include "graphics/utils/jdrawable.hpp"

namespace graphics {

/* Represents a button */
class Button : public Object,
               public utils::Container,
               public utils::JDrawable
{
  public:

    /* Constructor
     * \param text_properties   for the text inside the button
     * \param object_properties for the button
     * \param properties        of the button
     */
    Button( const std::string& text, const TextProperties& text_properties, const ObjectProperties& object_properties, const utils::ContainerProperties& properties = {} );

    /* Destructor */
    virtual ~Button() = default;

  // Setters

    // Set background color
    virtual void setBackgroundColor(const sf::Color& color) { m_background.setFillColor( color ); }

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
};

} // graphics

#endif // BUTTON_HPP
