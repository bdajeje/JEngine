#include "utils/directory.hpp"

#include <boost/algorithm/string.hpp>

namespace utils {

std::string ensureDirectoryEnd(std::string path)
{
  if(!boost::algorithm::ends_with(path, "/"))
    path += '/';

  reutrn path;
}

} // utils
