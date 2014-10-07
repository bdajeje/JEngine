#ifndef JDRAWABLE_HPP
#define JDRAWABLE_HPP

#include <SFML/Graphics/Drawable.hpp>

#include "graphics/object.hpp"
#include "graphics/utils/movable.hpp"

namespace graphics {
namespace utils {

class JDrawable : public Movable,
                  public Object,
                  public sf::Drawable
{
  public:

    JDrawable(const sf::Vector2f& size, const sf::Vector2f& position);

    virtual ~JDrawable() {}

    virtual void draw(sf::RenderTarget& render_target, sf::RenderStates states = sf::RenderStates::Default) const = 0;

    virtual void setPosition(float x, float y) = 0;
};

} // utils
} // graphics

#endif // JDRAWABLE_HPP
