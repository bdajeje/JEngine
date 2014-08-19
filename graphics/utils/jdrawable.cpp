#include "jdrawable.hpp"

namespace graphics {
namespace utils {

JDrawable::JDrawable(const sf::Vector2f& size, const sf::Vector2f& position)
  : Movable{size, position}
{
}

} // utils
} // graphics
