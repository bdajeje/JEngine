#include "jdrawable.hpp"

namespace graphics {
namespace utils {

JDrawable::JDrawable(const sf::Vector2f& size, const sf::Vector2f& position)
  : Movable{size, position}
{
}

void JDrawable::translate(float x, float y)
{
  setPosition( m_position.x + x, m_position.y + y );
}

} // utils
} // graphics
