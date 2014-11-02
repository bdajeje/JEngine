#ifndef PAZAAK_GAME_HPP
#define PAZAAK_GAME_HPP

#include "jengine/graphics/jwindow.hpp"

namespace pazaak {
  namespace views {
    class MainMenu;
    class Settings;
  }
}

namespace pazaak {

class Game : public graphics::Window
{
  public:

    Game();

    void create();

  private:

    void showSettings();

  private:

    std::shared_ptr<pazaak::views::MainMenu> m_view_main_menu;
    std::shared_ptr<pazaak::views::Settings> m_view_settings;
};

} // pazaak

#endif // PAZAAK_GAME_HPP
