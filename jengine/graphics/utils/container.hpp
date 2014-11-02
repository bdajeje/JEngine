#ifndef JENGINE_CONTAINER_HPP
#define JENGINE_CONTAINER_HPP

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>

#include "jengine/graphics/utils/properties.hpp"

namespace graphics {
namespace utils {

/* Represents margin on a block
 * top and left accept negative values
 */
struct Margins
{
  Margins(int top, int left)
    : top(top)
    , left(left)
  {}

  int top {0};
  int left {0};
};

/* Helper struct to hold properties */
struct ContainerProperties
{
  /* Constructor */
    ContainerProperties( HAlign halign = HAlign::Center, VAlign valign = VAlign::Middle, Margins margins = {0,0} )
    : halign{halign}
    , valign{valign}
    , margins{margins}
  {}

  HAlign  halign {HAlign::Center};
  VAlign  valign {VAlign::Middle};
  Margins margins;
};

/* Reprensents an object that can contains other objects
 * This is an helper class to position objects, like a <div> in HTML
 */
class Container
{
  public:

    /* Constructor
     * \param properties of the container
     */
    Container( const ContainerProperties& properties );

    /* Destructor */
    ~Container() = default;

  protected:

    /* Get relative positions of a child depending on container position rules
     * \param parent_positions position of the parent element
     * \param parent_size      size  of the parent element
     * \param child_size       size of the child element
     * \return new positions for child element in order to respect container position rules
     */
    sf::Vector2f getChildPosition(const sf::Vector2f& parent_positions, const sf::Vector2f& parent_size, const sf::Vector2f& child_size ) const;

  protected:

    /* Properties of this container */
    ContainerProperties m_properties;
};

} // utils
} // graphics

#endif // JENGINE_CONTAINER_HPP
