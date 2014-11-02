#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include "jengine/graphics/view.hpp"

namespace graphics {
namespace utils {

class Layout : public View
{
  public:

    Layout(const std::shared_ptr<game::SignalManager>& signal_receiver, const sf::Vector2f position, const sf::Vector2f size, const std::string& name);

    void addItem(std::shared_ptr<JDrawable> item) { addGraphicObject(item); updatePosition(); }

    void addItems(const std::vector<std::shared_ptr<JDrawable>>& items) { addGraphicObjects(items); updatePosition(); }

  protected:

    /* Update position of all items */
    virtual void updatePosition() = 0;
};

} // utils
} // graphics

#endif // LAYOUT_HPP
