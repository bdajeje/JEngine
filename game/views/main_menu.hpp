#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "graphics/objects/button.hpp"
#include "graphics/utils/vlayout.hpp"
#include "graphics/view.hpp"

namespace game {
namespace views {

/* Main menu of the game */
class MainMenu final : public graphics::View
{
  public:

    /* Constructor */
    MainMenu();

  private:

    /* Button play */
    graphics::Button* m_button_play;

    /* Button settings */
    graphics::Button* m_button_settings;

    /* Button to exit the application */
    graphics::Button* m_button_quit;

    /* Buttons vertical layout */
    graphics::utils::VLayout* m_vlayout;
};

} // views
} // game

#endif // MAIN_MENU_HPP
