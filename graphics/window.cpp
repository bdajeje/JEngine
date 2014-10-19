#include "window.hpp"

#include "SFML/Window/Event.hpp"

#include "graphics/view.hpp"
#include "utils/logging/easylogging++.h"

namespace graphics {

Window::Window(uint width, uint height, const std::string& title)
  : sf::RenderWindow( sf::VideoMode(width, height), title )
{}

bool Window::run()
{
  // Main application loop
  while( isOpen() )
  {
    sf::Event event;
    while( pollEvent(event) )
    {
      // Close the main window
      if(event.type == sf::Event::Closed)
        close();

      // Give incoming events to the current view
      if(m_current_view)
        m_current_view->incomingEvent( event );

      // Manage view events
      viewEvent();
    }

    // Update display
    updateDisplay();
  }

  return true;
}

void Window::updateDisplay()
{
  if( !m_current_view )
    return;

  // Clear screen between each frame
  clear();

  // Display all graphical objects of the window
  m_current_view->draw(*this);

  // Display everything
  display();
}

void Window::setViewSwitching(std::shared_ptr<const View> view, game::ViewEvent event, game::Callback callback)
{
  m_views_events[view][event] = callback;
}

void Window::viewEvent()
{
  auto found_view_events = m_views_events.find(m_current_view);
  if( found_view_events == m_views_events.end() )
    return;

  auto view_events = found_view_events->second;
  auto found_callback = view_events.find(m_current_view->viewEvent());
  if(found_callback == view_events.end())
    return;

  found_callback->second();
}

} // namespace graphics
