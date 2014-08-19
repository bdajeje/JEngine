#include "view.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include "utils/logging/easylogging++.h"

namespace graphics {

View::View( const sf::Vector2f position, const sf::Vector2f size, const std::string& name )
  : utils::JDrawable(size, position)
  , m_name(name)
{}

View::~View()
{
  // Delete all graphical objects inside the view
  for( const auto* graphical_object : m_graphic_objects )
    delete graphical_object;
}

bool View::addGraphicObject(JDrawable* graphic_object)
{
  if( !graphic_object )
  {
    LOG(DEBUG) << "Trying to add a null graphical object to the view '" << m_name << "'";
    return false;
  }

  m_graphic_objects.push_back(graphic_object);
  return true;
}

void View::draw(sf::RenderTarget& render_target, sf::RenderStates states) const
{
  //LOG(DEBUG) << "Drawing view " << m_name;

  for( const JDrawable* graphical_object : m_graphic_objects )
    render_target.draw(*graphical_object, states);
}

void View::setPosition(float x, float y)
{
  for( JDrawable* graphical_object : m_graphic_objects )
  {
    const sf::Vector2f& position = graphical_object->getPosition();
    graphical_object->setPosition( x + position.x, y + position.y );
  }
}

} // namespace graphics
