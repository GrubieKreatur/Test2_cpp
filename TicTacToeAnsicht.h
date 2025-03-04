//
// Created by scsch on 04.03.2025.
//

#ifndef TEST2_CPP_TICTACTOEANSICHT_H
#define TEST2_CPP_TICTACTOEANSICHT_H


#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class TicTacToeAnsicht {




public:
    TicTacToeAnsicht(sf::RenderWindow &window, sf::View &designView);
    bool draw(sf::Event *pEvent);
private:
    char currentPlayer;
    std::vector<std::vector<char>> gameBoard;
    sf::RenderWindow &window;
    sf::View &designView;
};


#endif //TEST2_CPP_TICTACTOEANSICHT_H
