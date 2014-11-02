#ifndef HLAYOUT_HPP
#define HLAYOUT_HPP

#include "jengine/graphics/utils/layout.hpp"

namespace graphics {
namespace utils {

class HLayout final : public Layout
{
  public:

    HLayout(const std::shared_ptr<game::SignalManager>& signal_receiver, const sf::Vector2f position, const sf::Vector2f size, const std::string& name);

  protected:

    /* Update position of all items */
    void updatePosition();
};

} // utils
} // graphics

#endif // HLAYOUT_HPP
