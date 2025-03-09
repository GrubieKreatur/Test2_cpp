#ifndef MenschSpieler_H
#define MenschSpieler_H

#include "Player.h"
#include <SFML/Graphics.hpp>


class HumanPlayer : public Player {
private:
    sf::RenderWindow &window;
    sf::Event* pEvent;
    sf::View &designView;

public:
    HumanPlayer(char symbol, sf::RenderWindow &window, sf::View &designView, sf::Event *pEvent) : Player(symbol), designView(designView), window(window), pEvent(pEvent) {


    }

    // Der Menschliche Spieler macht einen Zug basierend auf der Mausinteraktion
    bool makeMove(std::vector<std::vector<char>>& gameBoard) override {
        if (pEvent->type == sf::Event::MouseButtonPressed) {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos, designView);
            int row = (worldPos.y - 350) / 200; // Calculate the row
            int col = (worldPos.x - 660) / 200; // Calculate the column

            // If clicked within the grid bounds
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && gameBoard[row][col] == ' ') {
                gameBoard[row][col] = symbol;
                return true;
            }
        }
        return false;

    }


};

#endif