#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Bot.h"

class Game {
public:
    Game();
    void reset();
    void playMultiplayer(sf::RenderWindow& window);
    void playAgainstBot(sf::RenderWindow& window, bool easy, bool hard);
private:
    // Tic-Tac-Toe grid
    int board[3][3];
    bool isPlayerX;
    bool gameOver;

    // Methods for drawing the grid and checking for a winner
    void drawBoard(sf::RenderWindow& window);
    bool checkWinner();
    void handleInput(sf::RenderWindow& window);
};

#endif // GAME_H
