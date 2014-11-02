#include "multi_choice.hpp"

namespace graphics {

MultiChoice::MultiChoice(const std::shared_ptr<game::SignalManager>& signal_receiver, const std::vector<std::string>& choices,
                         const TextProperties& text_props, const ObjectProperties& object_properties, size_t /*selected_choice*/)
  : utils::JDrawable{ object_properties.size, object_properties.position }
{
  m_layout = std::make_shared<graphics::utils::HLayout>(signal_receiver, object_properties.position, object_properties.size, "MultiChoice layout");

  for( auto& choice : choices )
    m_layout->addItem( std::make_shared<graphics::Button>(choice, text_props, object_properties) );
}

void MultiChoice::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  m_layout->draw(target, states);
}

void MultiChoice::setPosition(float x, float y)
{
  m_layout->setPosition(x, y);
}

} // graphics
