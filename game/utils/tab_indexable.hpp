#ifndef TAB_INDEXABLE_HPP
#define TAB_INDEXABLE_HPP

#include <map>
#include <memory>

namespace game {
namespace utils {

/* A TabIndexable object is an object linked to others TabIndexable objects
 * in a way that when this object is selected and an action like key down/up/left/right
 * is triggered, the focus changed from this object to a next one.
 * This object holds the knowledge to know which next object will be selected depending
 * on action type.
 */
class TabIndexable
{
  public:

    /* Direction events */
    enum Direction { Top, Bottom, Left, Right };

    /* Constructor */
    TabIndexable() = default;

    /* Set next target
     * \param direction action
     * \param next      target to select for the given direction
     */
    void setNext( Direction direction, std::shared_ptr<const TabIndexable> next );

    /* Get next element to target for a given direction
     * \param direction to check
     */
    std::shared_ptr<const TabIndexable> next( Direction direction ) const;

  private:

    std::map<Direction, std::shared_ptr<const TabIndexable>> m_targets;
};

} // utils
} // game

#endif // TAB_INDEXABLE_HPP
