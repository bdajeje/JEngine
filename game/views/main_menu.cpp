#include "main_menu.hpp"

namespace game {
namespace views {

MainMenu::MainMenu()
  : graphics::View(600, 600, "Game Main Menu")
  , m_button_quit( "QUIT" )
{
  addGraphicObject( m_button_quit );
}

} // views
} // game
