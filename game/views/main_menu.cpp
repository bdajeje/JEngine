#include "main_menu.hpp"

#include "game/utils/defines.hpp"
#include "managers/texture_manager.hpp"
#include "utils/logging/easylogging++.h"

namespace game {
namespace views {

MainMenu::MainMenu()
  : Menu({0, 0}, {main_menu::WIDTH, main_menu::HEIGHT},
         texture::TextureManager::get(Texture::MenuBackground),
         {(main_menu::WIDTH - main_menu::BUTTONS_WIDTH) / 2, main_menu::HEIGHT / 4}, {main_menu::BUTTONS_WIDTH, main_menu::HEIGHT / 2}
         , "Main Menu")
{
  // Object properties
  const graphics::TextProperties text_props {font::Font::FreeMono, 20, sf::Color::Yellow, 0};
  const graphics::ObjectProperties button_props {0, 0, main_menu::BUTTONS_WIDTH, main_menu::BUTTONS_HEIGHT};
  const graphics::utils::ContainerProperties container_props { graphics::utils::HAlign::Center, graphics::utils::VAlign::Middle, graphics::utils::Margins{-8,0} };

  // Play button
  m_button_play = createButton("PLAY", text_props, button_props, container_props, Texture::ButtonBackground, Texture::ButtonBackgroundSelected);

  // Settings button
  m_button_settings = createButton("SETTINGS", text_props, button_props, container_props, Texture::ButtonBackground, Texture::ButtonBackgroundSelected);

  // Quit button
  m_button_quit = createButton("QUIT", text_props, button_props, container_props, Texture::ButtonBackground, Texture::ButtonBackgroundSelected);

  // Events
  setPressedEvent(m_button_quit, std::bind(&MainMenu::quit, this) );

  // Position buttons in a VLayout
  addButton(m_button_play);
  addButton(m_button_settings);
  addButton(m_button_quit);

  // Item selection order
  setCurrentSelected( m_button_play );
}

void MainMenu::quit()
{
  LOG(DEBUG) << "QUIT" << std::endl;
  m_view_event = game::ViewEvent::CLOSE;
}

} // views
} // game
