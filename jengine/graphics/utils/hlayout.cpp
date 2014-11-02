#include "hlayout.hpp"

namespace graphics {
namespace utils {

HLayout::HLayout(const std::shared_ptr<game::SignalManager>& signal_receiver, const sf::Vector2f position, const sf::Vector2f size, const std::string& name)
  : Layout{ signal_receiver, position, size, name }
{}

void HLayout::updatePosition()
{
  if(m_graphic_objects.empty())
    return;

  const sf::Vector2f& view_pos = getPosition();
  const auto shift = getSize().x / (m_graphic_objects.size() + 1);
  float pos_x      = view_pos.x + shift/2;

  for( auto object : m_graphic_objects )
  {
    object->setPosition( pos_x, object->getPosition().y );
    pos_x += shift;
  }
}

} // utils
} // graphics
