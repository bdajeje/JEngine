#include "jwindow.hpp"

#include "SFML/Window/Event.hpp"

#include "jengine/graphics/view.hpp"
#include "jengine/utils/logging/easylogging++.h"

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

} // namespace graphics
