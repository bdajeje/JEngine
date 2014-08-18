#ifndef JVIEW_HPP
#define JVIEW_HPP

#include <string>
#include <vector>

#include <SFML/Graphics/Drawable.hpp>

#include "graphics/utils/sizable.hpp"

namespace graphics {

/* Represents a view in the window
 * Holds one or several drawable objects to render on the screen
 */
class View : public utils::Sizable
{
  public:

    /* Constructor
     * \param width  of the view
     * \param height of the view
     * \param name   of the view
     */
    View( uint width, uint height, const std::string& name );

    /* Destrutor */
    virtual ~View();

    /* Draw the view
     * \param render_target where to draw the view
     */
    void draw(sf::RenderTarget& render_target) const;

    /* Add a graphical object to the view
     * \param graphic_object to add
     * \return true if the graphical object as been added to the view, false otherwise (example nullptr object)
     */
    bool addGraphicObject(const sf::Drawable* graphic_object);

  private:

    /* Name of this view */
    std::string m_name;

    /* Graphical objects contained in this view */
    std::vector<const sf::Drawable*> m_graphic_objects;
};

} // namespace graphics

#endif // JVIEW_HPP
