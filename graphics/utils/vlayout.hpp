#ifndef VLAYOUT_HPP
#define VLAYOUT_HPP

#include "graphics/object.hpp"
#include "graphics/view.hpp"

namespace graphics {
namespace utils {

class VLayout final : public View
{
  public:

    VLayout(const sf::Vector2f position, const sf::Vector2f size, const std::string& name);

    void addItem(JDrawable* item) { addGraphicObject(item); updatePosition(); }

    void addItems(const std::vector<JDrawable*>& items) { addGraphicObjects(items); updatePosition(); }

  protected:

    /* Update position of all items */
    void updatePosition();
};

} // utils
} // graphics

#endif // VLAYOUT_HPP
