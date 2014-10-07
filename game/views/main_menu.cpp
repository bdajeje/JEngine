#include "main_menu.hpp"

#include "game/utils/defines.hpp"
#include "managers/texture_manager.hpp"
#include "utils/logging/easylogging++.h"

namespace game {
namespace views {

MainMenu::MainMenu()
  : graphics::View({0, 0}, {main_menu::WIDTH, main_menu::HEIGHT}, "Game Main Menu")
{
  // Object properties
  const graphics::TextProperties text_props {font::Font::FreeMono, 20, sf::Color::Yellow, 0};
  const graphics::ObjectProperties button_props {0, 0, main_menu::BUTTONS_WIDTH, main_menu::BUTTONS_HEIGHT};
  const graphics::utils::ContainerProperties container_props { graphics::utils::HAlign::Center, graphics::utils::VAlign::Middle };

  // Background
  m_background = new graphics::Sprite( texture::TextureManager::get( Texture::MenuBackground ), {0, 0, main_menu::WIDTH, main_menu::HEIGHT} );

  // Play button
  m_button_play = createButton("PLAY", text_props, button_props, container_props);

  // Settings button
  m_button_settings = createButton("SETTINGS", text_props, button_props, container_props);

  // Quit button
  m_button_quit = createButton("QUIT", text_props, button_props, container_props);

  // Position buttons in a VLayout
  m_vlayout = new graphics::utils::VLayout({0, 0}, {600, 500}, "Main Menu Buttons VLayout");
  m_vlayout->addItem(m_button_play);
  m_vlayout->addItem(m_button_settings);
  m_vlayout->addItem(m_button_quit);

  // Add objects to the view
  addGraphicObject( m_background );
  addGraphicObject( m_vlayout );

  // Item selection order
  setCurrentSelected( m_button_play );

  setTabIndexables();
}

void MainMenu::setTabIndexables()
{
  // Play button
  m_button_play->setNext( utils::TabIndexable::Top, m_button_quit );
  m_button_play->setNext( utils::TabIndexable::Bottom, m_button_settings );

  // Settings button
  m_button_settings->setNext( utils::TabIndexable::Top, m_button_play );
  m_button_settings->setNext( utils::TabIndexable::Bottom, m_button_quit );

  // Quit button
  m_button_quit->setNext( utils::TabIndexable::Top, m_button_settings );
  m_button_quit->setNext( utils::TabIndexable::Bottom, m_button_play );
}

graphics::Button* MainMenu::createButton(const std::string& text, const graphics::TextProperties& text_props,
                                         const graphics::ObjectProperties& object_props, const graphics::utils::ContainerProperties& container_props)
{
  auto button = new graphics::Button( text, text_props, object_props, container_props );
  button->setBackgroundColor( sf::Color::White );
  button->setBackground( texture::TextureManager::get( Texture::ButtonBackground ) );
  button->setBackgroundSelected( texture::TextureManager::get( Texture::ButtonBackgroundSelected ) );

  return button;
}

} // views
} // game
