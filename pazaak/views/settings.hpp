#ifndef PAZAAK_SETTINGS_HPP
#define PAZAAK_SETTINGS_HPP

#include "jengine/game/views/menu.hpp"
#include "jengine/graphics/objects/multi_choice.hpp"

namespace pazaak {
namespace views {

/* Settings view */
class Settings final : public game::views::Menu
{
  public:

    Settings(const std::shared_ptr<game::SignalManager>& signal_receiver);

  private:

    std::shared_ptr<graphics::MultiChoice> m_sound_choices;
};

} // views
} // pazaak

#endif // PAZAAK_SETTINGS_HPP
