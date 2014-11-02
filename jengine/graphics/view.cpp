#include "view.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include "jengine/utils/logging/easylogging++.h"

namespace graphics {

View::View(const std::shared_ptr<game::SignalManager>& signal_receiver, const sf::Vector2f position, const sf::Vector2f size, const std::string& name)
  : utils::JDrawable(size, position)
  , game::Signaler(signal_receiver)
  , m_name(name)
{}

bool View::addGraphicObject(std::shared_ptr<JDrawable> graphic_object)
{
  if( !graphic_object )
  {
    LOG(DEBUG) << "Trying to add a null graphical object to the view '" << m_name << "'";
    return false;
  }

  // Apply to new object position translation into the view
  setPositionInView(graphic_object);

  // Add new object to the list of objects
  m_graphic_objects.push_back(graphic_object);

  return true;
}

void View::draw(sf::RenderTarget& render_target, sf::RenderStates states) const
{
  for( const auto& graphical_object : m_graphic_objects )
    render_target.draw(*graphical_object, states);
}

void View::setPosition(float x, float y)
{
  m_position.x = x;
  m_position.y = y;

  for( auto& graphical_object : m_graphic_objects )
    setPositionInView(graphical_object);
}

void View::setPositionInView( std::shared_ptr<JDrawable> graphical_object ) const
{
  const sf::Vector2f& position = graphical_object->getPosition();
  graphical_object->setPosition( m_position.x + position.x, m_position.y + position.y );
}

void View::setCurrentSelected( std::shared_ptr<JDrawable> graphic_item )
{
  if(!graphic_item)
    return;

  // Unselect previous one
  if(m_current_selected_object)
    m_current_selected_object->unselect();

  // Select new one
  m_current_selected_object = graphic_item;
  m_current_selected_object->select();
}

std::shared_ptr<utils::JDrawable> View::last() const
{
  if(m_graphic_objects.empty())
    return nullptr;

  return m_graphic_objects.back();
}

} // namespace graphics
