#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "Menu.h"

/**
 * @brief A class representing the main menu of the game.
 *
 * The MainMenu class is a specific type of Menu that handles the display and interaction of the main menu.
 * It inherits from the Menu class and provides functionality for handling mouse events and drawing the main menu interface.
 */
class MainMenu : public Menu {
public:
    /**
     * @brief Constructor for MainMenu.
     *
     * Initializes the main menu with references to the SFML window, view, and font.
     *
     * @param window The SFML window used for rendering.
     * @param designView The SFML view used to define the game world coordinates.
     * @param font The font used to display text (such as menu options) in the menu.
     */
    MainMenu(sf::RenderWindow &window, sf::View &designView, sf::Font &font);

    /**
     * @brief Draws the main menu and handles user interaction.
     *
     * This function listens for mouse events, determines if the user clicks on a button, and returns the next menu to display
     * based on the user's choice (e.g., start game, quit game, etc.). It overrides the draw function from the Menu class.
     *
     * @param pEvent Pointer to the SFML event that contains information about the mouse interaction.
     * @return A pointer to the next menu to display, which could be another Menu object.
     */
    Menu* draw(sf::Event *pEvent) override;

private:
    sf::RenderWindow& window;     ///< Reference to the SFML window used for rendering.
    sf::View &designView;         ///< Reference to the SFML view used to define how the game world is displayed.
    sf::Font &font;               ///< Reference to the SFML font used to render text on the menu.

    /**
     * @brief Checks if the mouse is hovering over a specific button.
     *
     * This helper function checks if the mouse cursor is currently over the given button. It is used to change the
     * appearance of the button (e.g., highlight it) when the mouse is over it.
     *
     * @param button A pointer to the SFML Text object representing the button.
     * @return true If the mouse is over the button, false otherwise.
     */
    bool isMouseOver(sf::Text *button);
};

#endif
