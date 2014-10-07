#include "configuration_manager.hpp"

#include "utils/directory.hpp"
#include "utils/logging/easylogging++.h"

namespace config {

std::unique_ptr<ConfigurationManager> ConfigurationManager::s_instance;

void ConfigurationManager::init(int argc, char **argv)
{
  s_instance.reset( new ConfigurationManager(argc, argv) );
}

ConfigurationManager& ConfigurationManager::instance()
{
  return *s_instance;
}

ConfigurationManager::ConfigurationManager(int /*argc*/, char **argv)
  : m_application_directory( utils::getDirectory(argv[0]) )
{
  // \todo load configurations
}

const std::string& ConfigurationManager::applicationDirectory()
{
  return instance().m_application_directory;
}

const std::string& ConfigurationManager::fontDirectory()
{
  static const std::string result = applicationDirectory() + "fonts/";
  return result;
}

const std::string& ConfigurationManager::imageDirectory()
{
  static const std::string result = applicationDirectory() + "images/";
  return result;
}

} // config
