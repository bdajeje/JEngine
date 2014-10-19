#include "menu.hpp"

namespace game {
namespace views {

Menu::Menu( const sf::Vector2f position, const sf::Vector2f size, const sf::Texture& background_texture,
            const sf::Vector2f layout_position, const sf::Vector2f layout_size, const std::string& name )
  : graphics::View(position, size, name)
{
  // Background
  m_background = std::make_shared<graphics::Sprite>( background_texture, graphics::ObjectProperties{sf::Vector2f{0, 0}, size} );

  // Main layout
  m_vlayout = std::make_shared<graphics::utils::VLayout>(layout_position, layout_size, name + " - vlayout");

  // Add objects to the view
  addGraphicObject( m_background );
  addGraphicObject( m_vlayout );

  // Events
  bindEventKeyboard( sf::Keyboard::Up, std::bind(&Menu::changeMenuSelection, this, std::placeholders::_1) );
  bindEventKeyboard( sf::Keyboard::Down, std::bind(&Menu::changeMenuSelection, this, std::placeholders::_1) );
  bindEventKeyboard( sf::Keyboard::Return, std::bind(&Menu::buttonPressed, this, std::placeholders::_1) );
}

void Menu::changeMenuSelection(const sf::Event& event)
{
  if(event.type != sf::Event::KeyPressed)
    return;

  // m_current_selected_object is a JDrawable we need to cast it to a TabIndexable
  // In order to do that, let's downcast to Button then upcast to TabIndexable
  // \todo Is there a better way to do that?

   auto next_selected = cast<JDrawable, graphics::Button, utils::TabIndexable>(m_current_selected_object)->next(event.key.code);
   if(next_selected)
    setCurrentSelected( cast<utils::TabIndexable, graphics::Button, JDrawable>(next_selected) );
}

void Menu::buttonPressed(const sf::Event& event)
{
  if(event.type != sf::Event::KeyPressed)
    return;

  auto found = m_buttons_pressed_events.find(m_current_selected_object);
  if(found == m_buttons_pressed_events.end())
    return;

  found->second();
}

std::shared_ptr<graphics::Button> Menu::createButton(const std::string& text, const graphics::TextProperties& text_props,
                                                     const graphics::ObjectProperties& object_props,
                                                     const graphics::utils::ContainerProperties& container_props,
                                                     Texture button_background, Texture button_background_selected)
{
  auto button = std::make_shared<graphics::Button>( text, text_props, object_props, container_props );
  button->setBackground( texture::TextureManager::get( button_background ) );
  button->setBackgroundSelected( texture::TextureManager::get( button_background_selected ) );

  return button;
}

void Menu::addButton(std::shared_ptr<graphics::Button> new_button)
{
  if(!new_button)
  {
    LOG(ERROR) << "Trying to add a null new button to menu";
    return;
  }

  // Link new button with others for tab indexing
  auto previous_button = cast<JDrawable, graphics::Button, utils::TabIndexable>(m_vlayout->last());
  if(previous_button)
  {
    previous_button->setNext( utils::TabIndexable::Down, new_button );
    new_button->setNext( utils::TabIndexable::Up, previous_button );
  }

  // Add the new button to the layout
  m_vlayout->addItem(new_button);
}

void Menu::setPressedEvent(std::shared_ptr<JDrawable> graphical_object, game::Callback callback)
{
  if(!graphical_object)
  {
    LOG(ERROR) << "Trying to bind a pressed event to a nullptr object";
    return;
  }

  m_buttons_pressed_events[graphical_object] = callback;
}

} // views
} // game
