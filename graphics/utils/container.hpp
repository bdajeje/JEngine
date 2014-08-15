#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <SFML/Graphics/Color.hpp>

#include "graphics/utils/properties.hpp"

namespace graphics {
namespace utils {

/* Helper struct to hold properties */
struct ContainerProperties
{
  /* Constructor */
  ContainerProperties( HAlign halign = HAlign::Center, VAlign valign = VAlign::Middle )
    : halign{halign}
    , valign{valign}
  {}

  HAlign halign {HAlign::Center};
  VAlign valign {VAlign::Middle};
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

    /* Properties of this container */
    ContainerProperties m_properties;
};

} // utils
} // graphics

#endif // CONTAINER_HPP
