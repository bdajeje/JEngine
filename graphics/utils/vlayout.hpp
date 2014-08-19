#ifndef VLAYOUT_HPP
#define VLAYOUT_HPP

#include "graphics/object.hpp"
#include "graphics/view.hpp"

namespace graphics {
namespace utils {

class VLayout final : public Object,
                      public View
{
  public:

    VLayout(const sf::Vector2f position, const sf::Vector2f size, const std::string& name);

    void addItem(JDrawable* item) { m_graphic_objects.push_back(item); updatePosition(); }

    void addItems(std::vector<JDrawable*> items) { m_graphic_objects.insert(m_graphic_objects.end(), items.begin(), items.end()); updatePosition(); }

  protected:

    /* Update position of all items */
    void updatePosition();
};

} // utils
} // graphics

#endif // VLAYOUT_HPP
