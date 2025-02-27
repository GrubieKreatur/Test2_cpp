#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

class GUI {
public:
    GUI(sf::RenderWindow& window);
    bool showMainMenu();
    bool isMultiplayerSelected();
    bool isBotEasySelected();
    bool isBotHardSelected();
    void draw(sf::RenderWindow& window);
private:
    sf::RenderWindow& window;
    // Add GUI components like buttons, text, etc.
};

#endif // GUI_H
