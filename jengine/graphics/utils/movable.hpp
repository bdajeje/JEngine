#ifndef JENGINE_MOVABLE_HPP
#define JENGINE_MOVABLE_HPP

#include <SFML/System/Vector2.hpp>

namespace graphics {
namespace utils {

class Movable
{
  public:

    Movable(const sf::Vector2f& size, const sf::Vector2f& position);

    const sf::Vector2f& getSize() const { return m_size; }

    const sf::Vector2f& getPosition() const { return m_position; }

  protected:

    sf::Vector2f m_size;

    sf::Vector2f m_position;
};

} // utils
} // graphics

#endif // JENGINE_MOVABLE_HPP
