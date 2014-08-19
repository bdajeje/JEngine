#ifndef JVIEW_HPP
#define JVIEW_HPP

#include <string>
#include <vector>

#include "graphics/utils/jdrawable.hpp"

namespace graphics {

/* Represents a view in the window
 * Holds one or several drawable objects to render on the screen
 */
class View : public utils::JDrawable
{
  public:

    /* Constructor
     * \param position of the view
     * \param size     of the view
     * \param name     of the view
     */
    View( const sf::Vector2f position, const sf::Vector2f size, const std::string& name = {} );

    /* Destrutor */
    virtual ~View();

    /* Draw the view
     * \param render_target where to draw the view
     */
    virtual void draw(sf::RenderTarget& render_target, sf::RenderStates states = sf::RenderStates::Default) const;

    /* Add a graphical object to the view
     * \param graphic_object to add
     * \return true if the graphical object as been added to the view, false otherwise (example nullptr object)
     */
    bool addGraphicObject(JDrawable* graphic_object);

    /* Move all elements of the view */
    virtual void setPosition(float x, float y);

  protected:

    /* Name of this view */
    std::string m_name;

    /* Graphical objects contained in this view */
    std::vector<JDrawable*> m_graphic_objects;
};

} // namespace graphics

#endif // JVIEW_HPP
