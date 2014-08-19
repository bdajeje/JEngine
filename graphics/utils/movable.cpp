#include "movable.hpp"

namespace graphics {
namespace utils {

Movable::Movable(const sf::Vector2f& size, const sf::Vector2f& position)
  : m_size(size)
  , m_position(position)
{
}

} // utils
} // graphics
