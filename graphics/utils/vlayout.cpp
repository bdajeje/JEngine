#include "vlayout.hpp"

namespace graphics {
namespace utils {

VLayout::VLayout(const sf::Vector2f position, const sf::Vector2f size, const std::string& name)
  : View{ size, position, name }
{}

void VLayout::updatePosition()
{
  if(m_graphic_objects.empty())
    return;

  const sf::Vector2f& view_pos   = getPosition();
  const auto shift = getSize().y / m_graphic_objects.size();
  float pos_y      = view_pos.y;
  for( JDrawable* object : m_graphic_objects ) {
    object->setPosition( view_pos.x, pos_y - (object->getSize().y / 2) );
    LOG(DEBUG) << view_pos.x << "/" << pos_y - (object->getSize().y / 2);
    pos_y += shift;
  }
}

} // utils
} // graphics
