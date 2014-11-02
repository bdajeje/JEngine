#include "settings.hpp"

#include "pazaak/defines.hpp"

namespace pazaak {
namespace views {

Settings::Settings(const std::shared_ptr<game::SignalManager>& signal_receiver)
  : game::views::Menu( signal_receiver, {0, 0}, {main_menu::WIDTH, main_menu::HEIGHT},
                       texture::TextureManager::get(Texture::MenuBackground),
                       {(main_menu::WIDTH - main_menu::BUTTONS_WIDTH) / 2, main_menu::HEIGHT / 4}, {main_menu::BUTTONS_WIDTH, main_menu::HEIGHT / 2}
                       , "Settings")
{
  const graphics::TextProperties text_props {text::DEFAULT_FONT, text::DEFAULT_SIZE, text::DEFAULT_COLOR, 0};
  const graphics::ObjectProperties object_props {0, 0, main_menu::BUTTONS_WIDTH, main_menu::BUTTONS_HEIGHT};

  m_sound_choices = std::make_shared<graphics::MultiChoice>(signal_receiver, std::vector<std::string>{"Sound On", "Sound Off"}, text_props, object_props, 0);
  m_music_choices = std::make_shared<graphics::MultiChoice>(signal_receiver, std::vector<std::string>{"Music On", "Music Off"}, text_props, object_props, 0);

  m_sound_volume = std::make_shared<graphics::SlideBar>(signal_receiver, 0, 100, 25, 1, text_props, object_props, 0);
  m_music_volume = std::make_shared<graphics::SlideBar>(signal_receiver, 0, 100, 50, 1, text_props, object_props, 0);

  m_vlayout->addItem(m_sound_choices);
  m_vlayout->addItem(m_sound_volume);
  m_vlayout->addItem(m_music_choices);
  m_vlayout->addItem(m_music_volume);
}

} // views
} // pazaak
