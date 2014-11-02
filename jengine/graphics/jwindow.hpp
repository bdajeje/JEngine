#ifndef JENGINE_WINDOW_HPP
#define JENGINE_WINDOW_HPP

#include <memory>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#include "jengine/game/managers/signal_manager.hpp"

namespace graphics {

class View;

/* Represents a graphical window.
 * Holds other graphical objects.
 * This is the main graphical object and parent of all other graphical objects.
 */
class Window : public sf::RenderWindow,
               public game::SignalManager
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

  private:

    /* Update the display at each frame */
    void updateDisplay();

  private:

    std::shared_ptr<const View> m_current_view;
};

} // namespace graphics

#endif // JENGINE_WINDOW_HPP
