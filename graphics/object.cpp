#include "object.hpp"

namespace graphics {

Object::Object(uint x, uint y, uint width, uint height)
  : utils::Sizable(width, height)
  , utils::Movable(x, y)
{}

} // namespace graphics
