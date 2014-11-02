#include "button.hpp"

namespace graphics {

Button::Button( const std::string& text, const TextProperties& text_properties,
                const ObjectProperties& object_properties, const utils::ContainerProperties& container_properties )
  : utils::Container{ container_properties }
  , utils::JDrawable{ object_properties.size, object_properties.position }
  , m_text( text, text_properties )
{
  //LOG(DEBUG) << "Creating button: " << text;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  if( m_background_selected_image && isSelected() )
    target.draw( *m_background_selected_image, states );
  else if(m_background_image && !isSelected())
    target.draw( *m_background_image, states );

  target.draw( m_text, states );
}

void Button::setPosition(float x, float y)
{
  // Save new position
  m_position.x = x;
  m_position.y = y;

  // Update elements positions
  if( m_background_image )
    m_background_image->setPosition(x, y);
  if( m_background_selected_image )
  m_background_selected_image->setPosition(x, y);

  // Position the text relatively to the background position
  // Apply container margins on text
  m_text.setPosition( getChildPosition( m_position, m_size, m_text.getSize() ) );
}

void Button::setBackground( const std::shared_ptr<sf::Texture> texture )
{
  m_background_image.reset( new Sprite{texture, ObjectProperties{m_size, m_position}} );
}

void Button::setBackgroundSelected( const std::shared_ptr<sf::Texture> texture )
{
  m_background_selected_image.reset( new Sprite{texture, ObjectProperties{m_size, m_position}} );
}

} // graphics
