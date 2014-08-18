#ifndef CONFIGURATION_MANAGER_HPP
#define CONFIGURATION_MANAGER_HPP

#include <memory>
#include <string>

namespace config {

class ConfigurationManager final
{
  public:

    /* Initialize the configuration manager unique instance
     * \warning This method has to be called before using the ConfigurationManager
     * \param argc from command line
     * \parma argv from command line
     */
    static void init(int argc, char** argv);

    static ConfigurationManager& instance();

    static const std::string& applicationDirectory();

    static const std::string& fontDirectory();

  private:

    /* Hidden constructor
     * \param argc from command line
     * \parma argv from command line
     */
    ConfigurationManager(int argc, char** argv);

  private:

    /* Application directory */
    const std::string m_application_directory;

    /* Unique instance */
    static std::unique_ptr<ConfigurationManager> s_instance;
};

} // config

#endif // CONFIGURATION_MANAGER_HPP
