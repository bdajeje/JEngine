#include "main_menu.hpp"

#include "utils/logging/easylogging++.h"

namespace game {
namespace views {

MainMenu::MainMenu()
  : graphics::View({0, 0}, {600, 600}, "Game Main Menu")
{
  graphics::TextProperties text_properties {font::Font::FreeMono, 20, sf::Color::Yellow, 0};
  const uint buttons_width  = 200;
  const uint buttons_height = 50;

  graphics::ObjectProperties button_properties {0, 0, buttons_width, buttons_height};
  graphics::utils::ContainerProperties button_item_properties { graphics::utils::HAlign::Center, graphics::utils::VAlign::Middle };

  // Play button
  m_button_play = new graphics::Button( "PLAY", text_properties, button_properties, button_item_properties );
  m_button_play->setBackgroundColor( sf::Color::Blue );

  // Settings button
  m_button_settings = new graphics::Button( "SETTINGS", text_properties, button_properties, button_item_properties );
  m_button_settings->setBackgroundColor( sf::Color::Red );

  // Quit button
  m_button_quit = new graphics::Button( "QUIT", text_properties, button_properties, button_item_properties );
  m_button_quit->setBackgroundColor( sf::Color::Green );

  // Position buttons in a VLayout
  m_vlayout = new graphics::utils::VLayout({0, 0}, {100, 500}, "Main Menu Buttons VLayout");
  m_vlayout->addItem(m_button_play);
  m_vlayout->addItem(m_button_settings);
  m_vlayout->addItem(m_button_quit);

  // Add objects to the view
  addGraphicObject( m_vlayout );
}

} // views
} // game
