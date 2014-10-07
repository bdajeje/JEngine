#include "sprite.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include "utils/logging/easylogging++.h"

namespace graphics {

Sprite::Sprite(const sf::Texture& texture, const ObjectProperties& properties)
  : utils::JDrawable{ properties.size, properties.position }
{
  m_sprite.setTexture(texture);
  //setPosition(properties.position.x, properties.position.y);
  //setPosition(0, 0);
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw( m_sprite, states );
}

void Sprite::setPosition(float x, float y)
{
  m_sprite.setPosition(x, y);
}

} // graphics
