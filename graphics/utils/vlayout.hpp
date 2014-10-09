#ifndef VLAYOUT_HPP
#define VLAYOUT_HPP

#include "graphics/object.hpp"
#include "graphics/view.hpp"

#include <memory>

namespace graphics {
namespace utils {

class VLayout final : public View
{
  public:

    VLayout(const sf::Vector2f position, const sf::Vector2f size, const std::string& name);

    void addItem(std::shared_ptr<JDrawable> item) { addGraphicObject(item); updatePosition(); }

    void addItems(const std::vector<std::shared_ptr<JDrawable>>& items) { addGraphicObjects(items); updatePosition(); }

  protected:

    /* Update position of all items */
    void updatePosition();
};

} // utils
} // graphics

#endif // VLAYOUT_HPP
