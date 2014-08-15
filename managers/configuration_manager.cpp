#include "configuration_manager.hpp"

namespace config {

ConfigurationManager& ConfigurationManagerinstance()
{
  static ConfigurationManager s_instance;
  return s_instance;
}

ConfigurationManager::ConfigurationManager()
{
  // \todo load configurations
}

std::string ConfigurationManager::applicationDirectory()
{

}

const std::string& ConfigurationManager::fontDirectory()
{
  static const std::string result = applicationDirectory() + "fonts/";
  return result;
}

} // config
