#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "graphics/object.hpp"
#include "graphics/utils/jdrawable.hpp"

namespace graphics {

class Sprite final : public utils::JDrawable
{
  public:

    Sprite(const sf::Texture& texture, const ObjectProperties& properties);

    virtual void setPosition(float x, float y);

    sf::Sprite& sprite() { return m_sprite; }

  protected:

    virtual void draw(sf::RenderTarget& render_target, sf::RenderStates states = sf::RenderStates::Default) const;

  private:

    sf::Sprite m_sprite;
};

} // graphics

#endif // SPRITE_HPP
