#include "event_manager.hpp"

namespace game {

void EventManager::addEvent(sf::Event::EventType event_type, std::function<void(sf::Event::EventType)> callback)
{
  m_bindings[event_type].push_back(callback);
}

void EventManager::incomingEvent(const sf::Event::EventType& event) const
{
  // Find callbacks for this event
  auto found = m_bindings.find(event);
  if(found == m_bindings.end())
    return;

  // Call each registered callback
  auto& callbacks = found->second;
  for( auto& callback : callbacks )
    callback(event);
}

} // game
