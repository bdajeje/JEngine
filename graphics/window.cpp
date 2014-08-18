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
  while( isOpen() )
  {
    sf::Event event;
    while( pollEvent(event) )
    {
      if(event.type == sf::Event::Closed)
        close();
    }
LOG(DEBUG) << "test";
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
