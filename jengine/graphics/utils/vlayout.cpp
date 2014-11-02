#include "vlayout.hpp"

namespace graphics {
namespace utils {

VLayout::VLayout(const std::shared_ptr<game::SignalManager>& signal_receiver, const sf::Vector2f position, const sf::Vector2f size, const std::string& name)
  : Layout{ signal_receiver, position, size, name }
{}

void VLayout::updatePosition()
{
  if(m_graphic_objects.empty())
    return;

  const sf::Vector2f& view_pos = getPosition();
  const auto shift = getSize().y / (m_graphic_objects.size() + 1);
  float pos_y      = view_pos.y + shift/2;

  for( auto object : m_graphic_objects )
  {
    object->setPosition( object->getPosition().x, pos_y );
    pos_y += shift;
  }
}

} // utils
} // graphics
