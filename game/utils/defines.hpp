#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <functional>
#include <map>
#include <string> // This includes 'uint' :p

namespace window {
  constexpr uint WIDTH  { 1024 };
  constexpr uint HEIGHT { 768 };
} // window

namespace game {

typedef std::function<void()> Callback;

enum class ViewEvent {
  NOTHING,          /* Represents no event */
  CLOSE,            /* Exit the view */
  TO_PLAY_VIEW,     /* Show play view */
  TO_SETTINGS_VIEW  /* Show settings view */
};

typedef std::map<ViewEvent, Callback> ViewEvents;

namespace main_menu {
  constexpr uint WIDTH  { window::WIDTH };
  constexpr uint HEIGHT { window::HEIGHT };
  constexpr uint BUTTONS_WIDTH  { 194 };
  constexpr uint BUTTONS_HEIGHT { 35 };
} // main_menu

namespace pazaak {
} // pazaak

namespace ff8 {
} // ff8

} // game

#endif // DEFINES_HPP
