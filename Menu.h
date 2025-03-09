#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

/**
 * @brief A base class representing a general menu in the game.
 *
 * The Menu class is an abstract base class that provides a general interface for creating different types of menus in the game.
 * It defines a pure virtual function `draw()` that must be implemented by any derived class to handle the drawing and interaction logic.
 */
class Menu {
public:
    /**
     * @brief A pure virtual function to handle menu drawing and interaction.
     *
     * This function is responsible for handling user input (such as mouse clicks or keyboard events) and rendering the menu.
     * Derived classes must implement this function to define specific behavior for different menus (e.g., main menu, settings menu).
     *
     * @param pEvent Pointer to the SFML event object that contains information about user input, such as mouse or keyboard events.
     * @return A pointer to the next menu that should be displayed, or nullptr if no change is needed.
     */
    virtual Menu* draw(sf::Event *pEvent) = 0;
};

#endif
