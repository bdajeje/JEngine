#ifndef JENGINE_VLAYOUT_HPP
#define JENGINE_VLAYOUT_HPP

#include "jengine/graphics/utils/layout.hpp"

#include <memory>

namespace graphics {
namespace utils {

class VLayout final : public Layout
{
  public:

    VLayout(const std::shared_ptr<game::SignalManager>& signal_receiver, const sf::Vector2f position, const sf::Vector2f size, const std::string& name);

  protected:

    /* Update position of all items */
    void updatePosition();
};

} // utils
} // graphics

#endif // JENGINE_VLAYOUT_HPP
