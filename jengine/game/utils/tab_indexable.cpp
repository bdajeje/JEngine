#include "tab_indexable.hpp"

#include "jengine/utils/logging/easylogging++.h"

namespace game {
namespace utils {

void TabIndexable::setNext( Direction direction, std::shared_ptr<TabIndexable> next )
{
  m_targets[direction] = next;
}

std::shared_ptr<TabIndexable> TabIndexable::next( Direction direction )
{
  auto found = m_targets.find(direction);
  if( found == m_targets.end() )
    return nullptr;

  return found->second;
}

std::shared_ptr<TabIndexable> TabIndexable::next( sf::Keyboard::Key key )
{
  switch(key)
  {
    case sf::Keyboard::Up:    return next(Direction::Up); break;
    case sf::Keyboard::Down:  return next(Direction::Down); break;
    case sf::Keyboard::Left:  return next(Direction::Left); break;
    case sf::Keyboard::Right: return next(Direction::Right); break;
    default: return nullptr;
  }
}

} // utils
} // game
