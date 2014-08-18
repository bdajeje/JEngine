#include "utils/directory.hpp"

#include <boost/algorithm/string.hpp>

namespace utils {

std::string ensureDirectoryEnd(std::string path)
{
  if(!boost::algorithm::ends_with(path, "/"))
    path += '/';

  return path;
}

std::string getDirectory(const std::string& path)
{
  const size_t index = path.find_last_of('/');
  if(index == std::string::npos)
    return {};

  return path.substr(0, index + 1);
}

} // utils
