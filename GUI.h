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
    GUI();
    void drawBoard(sf::RenderWindow& window, const Game& game);
    void handleMouseClick(const sf::Event& event, Game& game);
    void displayWinner(sf::RenderWindow& window, char winner);

private:
    sf::Font font;
    sf::Text text;
};

#endif
 //TEST2_CPP_GUI_H
