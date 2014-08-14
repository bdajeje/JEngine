#include "view.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include "utils/logging/easylogging++.h"

namespace graphics {

View::View( uint width, uint height, const std::string& name )
  : utils::Sizable(width, height)
  , m_name(name)
{}

bool View::addGraphicObject(const sf::Drawable* graphic_object)
{
  if( !graphic_object )
  {
    LOG(DEBUG) << "Trying to add a null graphical object to the view '" << m_name << "'";
    return false;
  }

  m_graphic_objects.push_back(graphic_object);
  return true;
}

void View::draw(sf::RenderTarget& render_target) const
{
  for( const auto* graphical_object : m_graphic_objects )
    render_target.draw(*graphical_object);
}

} // namespace graphics
