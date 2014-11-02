#include "event_manager.hpp"

namespace game {

void EventManager::bindEvent(sf::Event::EventType event_type, EventCallback callback)
{
  m_general_bindings[event_type].push_back(callback);
}

void EventManager::bindEventKeyboard(sf::Keyboard::Key key, EventCallback callback)
{
  m_keyboard_bindings[key].push_back(callback);
}

void EventManager::incomingEvent(const sf::Event& event) const
{
  switch(event.type)
  {
    case sf::Event::KeyPressed:
    {
      auto found = m_keyboard_bindings.find(event.key.code);
      if(found != m_keyboard_bindings.end())
        callCallbacks( found->second, event );
      break;
    }
    default:
    {
      auto found = m_general_bindings.find(event.type);
      if(found != m_general_bindings.end())
        callCallbacks( found->second, event );
      break;
    }
  }
}

void EventManager::callCallbacks(const CallbackList& callbacks, const sf::Event& event) const
{
  // Call each registered callback
  for( auto& callback : callbacks )
    callback(event);
}

} // game
