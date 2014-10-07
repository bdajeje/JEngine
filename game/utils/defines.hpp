#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <string> // This includes 'uint' :p

namespace window {
  constexpr uint WIDTH  { 1024 };
  constexpr uint HEIGHT { 768 };
} // window

namespace game {
namespace main_menu {
  constexpr uint WIDTH  { window::WIDTH };
  constexpr uint HEIGHT { window::HEIGHT };
  constexpr uint BUTTONS_WIDTH  { 200 };
  constexpr uint BUTTONS_HEIGHT { 50 };
} // main_menu

namespace pazaak {
} // pazaak

namespace ff8 {
} // ff8

} // game

#endif // DEFINES_HPP
