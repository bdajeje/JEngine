#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#include "game/utils/defines.hpp"

namespace graphics {

class View;

/* Represents a graphical window.
 * Holds other graphical objects.
 * This is the main graphical object and parent of all other graphical objects.
 */
class Window final : public sf::RenderWindow
{
  public:

    /* Constructor
     * \param width  of the window to create
     * \param hight  of the window to create
     * \param title  of the window to create
     */
    Window(uint width, uint height, const std::string& title);

    /* Main events loops
     * \note This function is blocking
     * \return false on error, true otherwise
     */
    bool run();

    /* Set a view to show as the current one */
    void setCurrentView( std::shared_ptr<const View> view ) { m_current_view = view; }

    void setViewSwitching(std::shared_ptr<const View> view, game::ViewEvent, game::Callback);

  private:

    /* Update the display at each frame */
    void updateDisplay();

    /* Take care of view events */
    void viewEvent();

  private:

    std::shared_ptr<const View> m_current_view;

    std::map<std::shared_ptr<const View>, game::ViewEvents> m_views_events;
};

} // namespace graphics

#endif // WINDOW_HPP
