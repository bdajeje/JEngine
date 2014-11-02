#ifndef SLIDE_BAR_HPP
#define SLIDE_BAR_HPP

#include "jengine/game/utils/tab_indexable.hpp"
#include "jengine/graphics/objects/text.hpp"
#include "jengine/graphics/utils/jdrawable.hpp"
#include "jengine/graphics/view.hpp"
#include "jengine/graphics/objects/rectangle.hpp"

namespace graphics {

class SlideBar : public utils::JDrawable,
                 public game::utils::TabIndexable,
                 public graphics::View
{
  public:

    SlideBar(const std::shared_ptr<game::SignalManager>& signal_receiver, int minimum, int maximum, int value, int step,
             const TextProperties& text_props, const ObjectProperties& object_properties);

    void setPosition(float x, float y);

  private:

    std::shared_ptr<graphics::Rectangle> m_bar;
    std::shared_ptr<graphics::Rectangle> m_slider;
    std::shared_ptr<graphics::Text> m_text_minimum;
    std::shared_ptr<graphics::Text> m_text_maximum;

    int m_minimum;
    int m_maximum;
    int m_value;
    int m_step;
};

} // graphics

#endif // SLIDE_BAR_HPP
