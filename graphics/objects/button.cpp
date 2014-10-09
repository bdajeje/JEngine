#include "button.hpp"

namespace graphics {

Button::Button( const std::string& text, const TextProperties& text_properties,
                const ObjectProperties& object_properties, const utils::ContainerProperties& container_properties )
  : utils::Container{ container_properties }
  , utils::JDrawable{ object_properties.size, object_properties.position }
  , m_text( text, text_properties )
  , m_background{ object_properties.size, sf::Color::White, sf::Color::Black }
{}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw( m_background, states );

  if( m_background_selected_image && isSelected() )
    target.draw( *m_background_selected_image, states );
  else if(m_background_image)
    target.draw( *m_background_image, states );

  target.draw( m_text, states );
}

void Button::setPosition(float x, float y)
{
  m_background.setPosition(x, y);

  // Position the text relatively to the background position
  m_text.setPosition( getChildPosition( m_background.getPosition(), m_background.getSize(), m_text.getSize() ) );
}

void Button::setBackground( const sf::Texture& texture )
{
  m_background_image.reset( new Sprite{texture, ObjectProperties{m_size, m_position}} );
}

void Button::setBackgroundSelected( const sf::Texture& texture )
{
  m_background_selected_image.reset( new Sprite{texture, ObjectProperties{m_size, m_position}} );
}

} // graphics
