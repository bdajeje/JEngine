#ifndef PAZAAK_DEFINES_HPP
#define PAZAAK_DEFINES_HPP

#include <SFML/Graphics/Color.hpp>

#include "jengine/defines.hpp"
#include "jengine/utils/fonts.hpp"

namespace pazaak {

namespace window {
  constexpr uint WIDTH  { 1024 };
  constexpr uint HEIGHT { 768 };
} // window

namespace main_menu {
  constexpr uint WIDTH  { window::WIDTH };
  constexpr uint HEIGHT { window::HEIGHT };
  constexpr uint BUTTONS_WIDTH  { 194 };
  constexpr uint BUTTONS_HEIGHT { 35 };
} // main_menu

namespace text {
  constexpr uint DEFAULT_SIZE {20};
  constexpr utils::Font DEFAULT_FONT {utils::Font::FreeMono};
  const sf::Color DEFAULT_COLOR {sf::Color::Yellow};
}

}

#endif // PAZAAK_DEFINES_HPP
