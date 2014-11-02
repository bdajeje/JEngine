#include "container.hpp"

#include "jengine/utils/logging/easylogging++.h"

namespace graphics {
namespace utils {

Container::Container( const ContainerProperties& properties )
  : m_properties( properties )
{}

sf::Vector2f Container::getChildPosition(const sf::Vector2f& parent_positions, const sf::Vector2f& parent_size, const sf::Vector2f& child_size ) const
{
  sf::Vector2f result;

  // Horizontal
  switch(m_properties.halign)
  {
    case HAlign::Left:
      result.x = parent_positions.x;
      break;
    case HAlign::Center:
      result.x = parent_positions.x + ( parent_size.x - child_size.x ) / 2;
      break;
    case HAlign::Right:
      result.x = parent_positions.x + parent_size.x - child_size.x;
      break;
  }

  // Vertical
  switch(m_properties.valign)
  {
    case VAlign::Top:
      result.y = parent_positions.y;
      break;
    case VAlign::Middle:
      result.y = parent_positions.y + ( parent_size.y - child_size.y ) / 2;
      break;
    case VAlign::Bottom:
      result.y = parent_positions.y + parent_size.y - child_size.y;
      break;
  }

  result.x += m_properties.margins.left;
  result.y += m_properties.margins.top;

  return result;
}

} // utils
} // graphics
