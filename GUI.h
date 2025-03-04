//
// Created by scsch on 27.02.2025.
//

// GUI.h
#ifndef GUI_H
#define GUI_H

#include "./SFML-3.0.0/include/SFML/Graphics.hpp"
#include "Game.h"

class GUI {
public:

    GUI(sf::RenderWindow& window);
    bool showMainMenu();
    bool isMultiplayerSelected();
    bool isBotEasySelected();
    bool isBotHardSelected();
    void draw(sf::RenderWindow& window, int* textStandartGrose);
private:
    sf::Font font;
    sf::Text text;
};

#endif
 //TEST2_CPP_GUI_H
