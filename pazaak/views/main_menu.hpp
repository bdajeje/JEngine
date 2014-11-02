#ifndef PAZAAK_MAIN_MENU_HPP
#define PAZAAK_MAIN_MENU_HPP

#include "jengine/game/views/menu.hpp"

#include <memory>

namespace pazaak {
namespace views {

/* main menu of the game */
class MainMenu final : public game::views::Menu
{
  public:

    enum Signal : uint {
      CLOSE,            /* Close */
      TO_PLAY_VIEW,     /* Show play view */
      TO_SETTINGS_VIEW  /* Show settings view */
    };

    /* Constructor */
    MainMenu(const std::shared_ptr<game::SignalManager>& signal_receiver);

  private:

  // EVENTS

    void settings();
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
} // pazaak

#endif // PAZAAK_MAIN_MENU_HPP
