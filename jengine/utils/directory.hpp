#ifndef JENGINE_DIRECTORY_HPP
#define JENGINE_DIRECTORY_HPP

#include <string>

namespace utils {

// Ensure '/' and the end of directory string
std::string ensureDirectoryEnd(std::string path);

/* Get the directory part of a filepath */
std::string getDirectory(const std::string& path);

} // utils

#endif // JENGINE_DIRECTORY_HPP
