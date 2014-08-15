#ifndef CONFIGURATION_MANAGER_HPP
#define CONFIGURATION_MANAGER_HPP

#include <string>

namespace config {

class ConfigurationManager
{
  public:

    static ConfigurationManager& instance();

    static const std::string& applicationDirectory();

    static const std::string& fontDirectory();

  private:

    ConfigurationManager();
};

} // config

#endif // CONFIGURATION_MANAGER_HPP
