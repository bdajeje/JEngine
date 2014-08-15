#include "utils/logging/easylogging++.h"

#include "game/views/main_menu.hpp"
#include "graphics/window.hpp"

_INITIALIZE_EASYLOGGINGPP

int main()
{
  // Logging configuration
  {
    el::Configurations logging_configuration{"configurations/logging.conf"};
    el::Loggers::reconfigureAllLoggers(logging_configuration);
  }

  // Main menu view
  game::views::MainMenu* view_main_menu = new game::views::MainMenu{};

  // Window
  graphics::Window window{1200, 800, "JEngine"};
  window.setCurrentView( view_main_menu );
  window.run();

  // Clean
  delete view_main_menu;

  return EXIT_SUCCESS;
}
