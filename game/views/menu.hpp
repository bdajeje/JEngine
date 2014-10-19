#ifndef MENU_HPP
#define MENU_HPP

#include "game/utils/defines.hpp"
#include "graphics/objects/button.hpp"
#include "graphics/utils/vlayout.hpp"
#include "graphics/view.hpp"
#include "managers/texture_manager.hpp"

namespace game {
namespace views {

class Menu : public graphics::View
{
  public:

    Menu( const sf::Vector2f position, const sf::Vector2f size, const sf::Texture& background_texture,
          const sf::Vector2f layout_position, const sf::Vector2f layout_size, const std::string& name = {} );

  protected:

    static std::shared_ptr<graphics::Button> createButton(const std::string& text, const graphics::TextProperties& text_props,
                                                          const graphics::ObjectProperties& object_props,
                                                          const graphics::utils::ContainerProperties& container_props,
                                                          Texture button_background, Texture button_background_selected);

    virtual void addButton(std::shared_ptr<graphics::Button> button);

  /* Events */
    virtual void changeMenuSelection(const sf::Event& event);
    virtual void buttonPressed(const sf::Event& event);

  protected:

    void setPressedEvent(std::shared_ptr<JDrawable> graphical_object, game::Callback callback);

  private:

    template<class A, class B, class C>
    std::shared_ptr<C> cast(std::shared_ptr<A> drawable)
    {
      if(!drawable)
        return nullptr;

      auto downcasted = std::static_pointer_cast<B>(drawable);
      return std::static_pointer_cast<C>(downcasted);
    }

  protected:

    /* Background */
    std::shared_ptr<graphics::Sprite> m_background;

    /* Buttons vertical layout */
    std::shared_ptr<graphics::utils::VLayout> m_vlayout;

    /* Menu buttons */
    std::vector<std::shared_ptr<graphics::Button>> m_buttons;

    std::map<std::shared_ptr<JDrawable>, game::Callback> m_buttons_pressed_events;
};

} // views
} // game

#endif // MENU_HPP
