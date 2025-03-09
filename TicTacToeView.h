//
// Created by scsch on 04.03.2025.
//

#ifndef TEST2_CPP_TICTACTOEVIEW_H
#define TEST2_CPP_TICTACTOEVIEW_H


#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Player.h"
#include "Menu.h"

class TicTacToeView : public Menu{




public:
    TicTacToeView(sf::RenderWindow &window, sf::View &designView, sf::Font &font, Player *player1, Player *player2);

    ~TicTacToeView() {
        delete player1;
        delete player2;
    }

    Menu * draw(sf::Event *pEvent) override;
private:
    char currentPlayer;
    char winner;
    std::vector<std::vector<char>> gameBoard;
    sf::RenderWindow &window;
    sf::View &designView;
    sf::Font &font;
    Player* player1;
    Player* player2;


    bool isMouseOver(sf::Text *textButton);

    bool gameBoardFull();


    void drawWinnerDisplayText();
};


#endif //TEST2_CPP_TICTACTOEVIEW_H
