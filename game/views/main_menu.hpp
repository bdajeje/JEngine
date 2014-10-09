#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "graphics/objects/button.hpp"
#include "graphics/objects/sprite.hpp"
#include "graphics/utils/vlayout.hpp"
#include "graphics/view.hpp"

#include <memory>

namespace game {
namespace views {

/* main menu of the game */
class MainMenu final : public graphics::View
{
  public:

    /* Constructor */
    MainMenu();

  private:

    static std::shared_ptr<graphics::Button> createButton(const std::string& text, const graphics::TextProperties& text_props,
                                                          const graphics::ObjectProperties& object_props,
                                                          const graphics::utils::ContainerProperties& container_props);

    void setTabIndexables();
    void setEvents();

  private:

    /* Background */
    std::shared_ptr<graphics::Sprite> m_background;

    /* Button play */
    std::shared_ptr<graphics::Button> m_button_play;

    /* Button settings */
    std::shared_ptr<graphics::Button> m_button_settings;

    /* Button to exit the application */
    std::shared_ptr<graphics::Button> m_button_quit;

    /* Buttons vertical layout */
    std::shared_ptr<graphics::utils::VLayout> m_vlayout;
};

} // views
} // game

#endif // MAIN_MENU_HPP
