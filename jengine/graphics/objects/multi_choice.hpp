#ifndef JENGINE_MULTI_CHOICE_HPP
#define JENGINE_MULTI_CHOICE_HPP

#include <vector>

#include "jengine/graphics/objects/button.hpp"
#include "jengine/graphics/utils/hlayout.hpp"

namespace graphics {

class MultiChoice : public utils::JDrawable,
                    public game::utils::TabIndexable
{
  public:

    MultiChoice(const std::shared_ptr<game::SignalManager>& signal_receiver, const std::vector<std::string>& choices, const TextProperties& text_props,
                const ObjectProperties& object_properties, size_t selected_choice = 0);

    void draw(sf::RenderTarget& render_target, sf::RenderStates states = sf::RenderStates::Default) const;

    void setPosition(float x, float y);

  private:

    std::shared_ptr<graphics::utils::HLayout> m_layout;
};

} // graphics

#endif // JENGINE_MULTI_CHOICE_HPP
