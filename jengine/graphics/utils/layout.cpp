#include "layout.hpp"

namespace graphics {
namespace utils {

Layout::Layout(const std::shared_ptr<game::SignalManager>& signal_receiver, const sf::Vector2f position, const sf::Vector2f size, const std::string& name)
  : View{ signal_receiver, position, size, name }
{
}

} // utils
} // graphics
