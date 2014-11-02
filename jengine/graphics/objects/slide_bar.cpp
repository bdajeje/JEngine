#include "slide_bar.hpp"

namespace graphics {

SlideBar::SlideBar(const std::shared_ptr<game::SignalManager>& signal_receiver, int minimum, int maximum, int value, int step,
                   const TextProperties& text_props, const ObjectProperties& object_properties)
  : JDrawable(object_properties.size, object_properties.position)
  , graphics::View(signal_receiver, object_properties.position, object_properties.size, "SlideBar")
  , m_minimum(minimum)
  , m_maximum(maximum)
  , m_value(value)
  , m_step(step)
{
  // Verify values
  verifyInput(minimum, maximum, value, step);

 // Create widgets

  // Bars
  m_bar    = std::make_shared<graphics::Rectangle>(sf::Vector2f{object_properties.size.x, 25}, sf::Color::Green, sf::Color::Red);
  m_slider = std::make_shared<graphics::Rectangle>(sf::Vector2f{20, 50}, sf::Color::Blue, sf::Color::Blue);

  // Text
  m_text_minimum = std::make_shared<graphics::Text>(minimum, text_props);
  m_text_maximum = std::make_shared<graphics::Text>(maximum, text_props);
}

void SlideBar::setPosition(float x, float y)
{
  // Bar
  m_bar->setPosition(x, y);

  // Numbers
  m_text_minimum->setPosition(x, y);
  m_text_maximum->setPosition(x + m_size.x, y);

  // Slider
  int total_diff = Math.abs(m_maximum - m_minimum);
  int offset     = Math.abs(value - m_minimum);
  int percentage = offset * 100 / total_diff; // total_diff can't be null thx to previous input values checking
}

void SlideBar::verifyInput(int minimum, int maximum, int value, int step)
{
  std::string error;

  if( maximum - minimum <= 0 )
    error = "max: " << maximum << ", min: " << minimum;
  else if(step == 0)
    error = "step equals 0";
  else if(value < minimum)
    error = "value < minimum";
  else if(value > maximum)
    error = "value > maximum";

  if(error.empty())
    return;

  LOG(ERROR) << "Slidebar with incorrect input values!\n" << error;
}

} // graphics
