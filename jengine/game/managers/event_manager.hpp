#ifndef JENGINE_EVENT_MANAGER_HPP
#define JENGINE_EVENT_MANAGER_HPP

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

    typedef std::function<void(const sf::Event&)> EventCallback;
    typedef std::vector<EventCallback> CallbackList;

    EventManager() = default;

    void incomingEvent(const sf::Event& event) const;

    void bindEvent(sf::Event::EventType event_type, EventCallback callback);
    void bindEventKeyboard(sf::Keyboard::Key key, EventCallback callback);

  private:

    /* Helper function to call every callback functions inside a list of callbacks
     * \param callback_list list of callbacks to call
     */
    void callCallbacks(const CallbackList& list, const sf::Event& event) const;

  private:

    /* Map an event to a list of callbacks */
    std::map<sf::Event::EventType, CallbackList> m_general_bindings;
    std::map<sf::Keyboard::Key, CallbackList> m_keyboard_bindings;
};

} // game

#endif // JENGINE_EVENT_MANAGER_HPP
