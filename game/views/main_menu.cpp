#include "main_menu.hpp"

#include "utils/logging/easylogging++.h"

namespace game {
namespace views {

MainMenu::MainMenu()
  : graphics::View(600, 600, "Game Main Menu")
{
  graphics::TextProperties text_properties {font::Font::FreeMono, 20, sf::Color::Yellow, 0};
  const uint buttons_width  = 200;
  const uint buttons_height = 50;

  graphics::ObjectProperties button_properties {0, 0, buttons_width, buttons_height};
  graphics::utils::ContainerProperties button_item_properties { graphics::utils::HAlign::Center, graphics::utils::VAlign::Middle };

  m_button_play = new graphics::Button( "PLAY", text_properties, button_properties, button_item_properties );
  m_button_play->setBackgroundColor( sf::Color::Blue );
  m_button_play->setPosition(0, 0);

  m_button_settings = new graphics::Button( "SETTINGS", text_properties, button_properties, button_item_properties );
  m_button_settings->setBackgroundColor( sf::Color::Red );
  m_button_settings->setPosition(0, 70);

  m_button_quit = new graphics::Button( "QUIT", text_properties, button_properties, button_item_properties );
  m_button_quit->setBackgroundColor( sf::Color::Green );
  m_button_quit->setPosition(0, 140);

  // Position buttons in a VLayout


  addGraphicObject( m_button_play );
  addGraphicObject( m_button_settings );
  addGraphicObject( m_button_quit );
}

MainMenu::~MainMenu()
{
}

} // views
} // game
