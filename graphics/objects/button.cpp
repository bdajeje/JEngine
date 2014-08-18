#include "button.hpp"

namespace graphics {

Button::Button( const std::string& text, const TextProperties& text_properties,
                const ObjectProperties& object_properties, const utils::ContainerProperties& container_properties )
  : utils::Container{ container_properties }
  , m_text( text, text_properties )
  , m_background{ object_properties.width, object_properties.height, sf::Color::White, sf::Color::Black }
{
  LOG(DEBUG) << "creating button";
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw( m_background, states );
}

void Button::setBorderSize(uint size)
{
  // Don't do anything if size is already set to this input value
  if( size == m_background.getOutlineThickness() )
    return;

  // Update border size
  m_background.setOutlineThickness(size);

  // Update position after updating border size
  const auto& position = m_background.getPosition();
  setPosition( position.x, position.y );
}

void Button::setPosition(float x, float y)
{
  const auto border_size = m_background.getOutlineThickness();
  const float new_x = x + border_size;
  const float new_y = y + border_size;

  m_background.setPosition(new_x, new_y);
}

} // graphics
