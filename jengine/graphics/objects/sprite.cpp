#include "sprite.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include "jengine/utils/logging/easylogging++.h"

namespace graphics {

Sprite::Sprite(const std::shared_ptr<sf::Texture> texture, const ObjectProperties& properties)
  : utils::JDrawable{ properties.size, properties.position }
{
  if(!texture)
    LOG(ERROR) << "nullptr texture for sprite!";

  m_sprite.setTexture(*texture);
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
