#include "tab_indexable.hpp"

namespace game {
namespace utils {

void TabIndexable::setNext( Direction direction, const TabIndexable* next )
{
  m_targets[direction] = next;
}

const TabIndexable* TabIndexable::next( Direction direction ) const
{
  auto found = m_targets.find(direction);
  if( found == m_targets.end() )
    return nullptr;

  return found->second;
}

} // utils
} // game
