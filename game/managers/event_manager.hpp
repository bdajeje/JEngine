#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include "SFML/Window/Event.hpp"

#include <functional>
#include <map>
#include <vector>

namespace game {

/* Receive and manages events
 * The EventManager receives incoming events and call respective callbacks.
 * One event could be bind to one or several callbacks.
 */
class EventManager
{
  public:

    EventManager() = default;

    void incomingEvent(const sf::Event::EventType& event) const;

    void addEvent(sf::Event::EventType event_type, std::function<void(sf::Event::EventType)> callback);

  private:

    /* Map an event to a list of callbacks */
    std::map<sf::Event::EventType, std::vector<std::function<void(sf::Event::EventType)>>> m_bindings;
};

} // game

#endif // EVENT_MANAGER_HPP
