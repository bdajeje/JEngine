#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "game/views/menu.hpp"
#include "graphics/objects/sprite.hpp"

#include <memory>

namespace game {
namespace views {

/* main menu of the game */
class MainMenu final : public Menu
{
  public:

    /* Constructor */
    MainMenu();

  private:

  // EVENTS

    void quit();

  private:

    /* Button play */
    std::shared_ptr<graphics::Button> m_button_play;

    /* Button settings */
    std::shared_ptr<graphics::Button> m_button_settings;

    /* Button to exit the application */
    std::shared_ptr<graphics::Button> m_button_quit;
};

} // views
} // game

#endif // MAIN_MENU_HPP
