#include "main_menu.hpp"

namespace game {
namespace views {

MainMenu::MainMenu()
  : graphics::View(600, 600, "Game Main Menu")
{
  graphics::TextProperties text_properties {font::Font::FreeMono, 20, sf::Color::Yellow, 0};
  const uint buttons_width  = 200;
  const uint buttons_height = 50;

  m_button_quit = new graphics::Button( "QUIT", text_properties, {0, 0, buttons_width, buttons_height} );
  m_button_quit->setBackgroundColor( sf::Color::Blue );
  m_button_quit->setBorderColor( sf::Color::Red );
  m_button_quit->setBorderSize(10);
  m_button_quit->setPosition(0, 0);

  addGraphicObject( m_button_quit );
}

MainMenu::~MainMenu()
{
  delete m_button_quit;
}

} // views
} // game
