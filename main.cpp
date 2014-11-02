// JEngine
#include "jengine/utils/logging/easylogging++.h"
#include "jengine/managers/configuration_manager.hpp"
#include "jengine/managers/font_manager.hpp"
#include "jengine/managers/texture_manager.hpp"

// Pazaak
#include "pazaak/game.hpp"

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

  // Run main application loop
  auto pazaak = std::make_shared<pazaak::Game>();
  pazaak->create();
  pazaak->run();

  return EXIT_SUCCESS;
}
