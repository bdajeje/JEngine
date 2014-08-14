#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

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
    void setCurrentView( const View* view ) { m_current_view = view; }

  private:

    /* Update the display at each frame */
    void updateDisplay();

  private:

    const View* m_current_view = nullptr;
};

} // namespace graphics

#endif // WINDOW_HPP
