#include "game.hpp"

#include "pazaak/defines.hpp"
#include "pazaak/views/main_menu.hpp"
#include "pazaak/views/settings.hpp"

namespace pazaak {

Game::Game()
  : graphics::Window(window::WIDTH, window::HEIGHT, "Pazaak")
{}

void Game::create()
{
  // Main menu view
  m_view_main_menu = std::make_shared<pazaak::views::MainMenu>(shared_from_this());

  // Subscribes to events
  connect(m_view_main_menu, views::MainMenu::Signal::CLOSE, std::bind(&graphics::Window::close, this) );
  connect(m_view_main_menu, views::MainMenu::Signal::TO_SETTINGS_VIEW, std::bind(&Game::showSettings, this) );

  // Set current view
  setCurrentView( m_view_main_menu );
}

void Game::showSettings()
{
  if(!m_view_settings)
    m_view_settings = std::make_shared<pazaak::views::Settings>(shared_from_this());

  setCurrentView(m_view_settings);
}

} // pazaak
