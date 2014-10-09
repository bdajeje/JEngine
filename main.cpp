#include "utils/logging/easylogging++.h"

#include "managers/configuration_manager.hpp"
#include "managers/font_manager.hpp"
#include "managers/texture_manager.hpp"
#include "game/views/main_menu.hpp"
#include "game/utils/defines.hpp"
#include "graphics/window.hpp"

_INITIALIZE_EASYLOGGINGPP

int main(int argc, char** argv)
{
  // Logging configuration
  {
    el::Configurations logging_configuration{"configurations/logging.conf"};
    el::Loggers::reconfigureAllLoggers(logging_configuration);
  }

  // Set some configurations
  config::ConfigurationManager::init(argc, argv);
  font::FontManager::init( config::ConfigurationManager::fontDirectory() );
  texture::TextureManager::init( config::ConfigurationManager::imageDirectory() );

  // Main menu view
  auto view_main_menu = std::make_shared<game::views::MainMenu>();

  // Window
  graphics::Window window {window::WIDTH, window::HEIGHT, "JEngine"};
  window.setCurrentView( view_main_menu );
  window.run();

  return EXIT_SUCCESS;
}
