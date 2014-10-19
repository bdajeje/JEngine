#ifndef JVIEW_HPP
#define JVIEW_HPP

#include <string>
#include <vector>
#include <memory>

#include "game/managers/event_manager.hpp"
#include "game/utils/defines.hpp"
#include "graphics/utils/jdrawable.hpp"

namespace graphics {

/* Represents a view in the window
 * Holds one or several drawable objects to render on the screen
 */
class View : public utils::JDrawable,
             public game::EventManager
{
  public:

    /* Constructor
     * \param position of the view
     * \param size     of the view
     * \param name     of the view
     */
    View( const sf::Vector2f position, const sf::Vector2f size, const std::string& name = {} );

    /* Destrutor */
    virtual ~View() = default;

    /* Draw the view
     * \param render_target where to draw the view
     */
    virtual void draw(sf::RenderTarget& render_target, sf::RenderStates states = sf::RenderStates::Default) const;

    /* Add a graphical object to the view
     * \param graphic_object to add
     * \return true if the graphical object as been added to the view, false otherwise (example nullptr object)
     */
    bool addGraphicObject(std::shared_ptr<JDrawable> graphic_object);

    void addGraphicObjects(const std::vector<std::shared_ptr<JDrawable>>& items) { m_graphic_objects.insert(m_graphic_objects.end(), items.begin(), items.end()); }

    /* Move all elements of the view */
    virtual void setPosition(float x, float y);

    /* Set the currently selected graphic item */
    void setCurrentSelected( std::shared_ptr<JDrawable> graphic_item );

    /* Get last added Drawable */
    virtual std::shared_ptr<JDrawable> last() const;

    game::ViewEvent viewEvent() const { return m_view_event; }

  protected:

    void setPositionInView( std::shared_ptr<JDrawable> graphical_object ) const;

  protected:

    /* Name of this view */
    std::string m_name;

    /* Graphical objects contained in this view */
    std::vector<std::shared_ptr<JDrawable>> m_graphic_objects;

    /* Currently selected item */
    std::shared_ptr<JDrawable> m_current_selected_object;

    /* Next event of the view (managed by the window) */
    game::ViewEvent m_view_event {game::ViewEvent::NOTHING};
};

} // namespace graphics

#endif // JVIEW_HPP
