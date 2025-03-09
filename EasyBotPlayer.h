#ifndef EasyBotSpieler_H
#define EasyBotSpieler_H

#include "Player.h"
#include <cstdlib> // For random moves
#include <ctime>   // For random number generator

/**
 * @brief A simple bot player that makes random moves.
 */
class EasyBotPlayer : public Player {
public:
    /**
     * @brief Constructor for EasyBotPlayer.
     *
     * Initializes the bot with the given symbol ('X' or 'O') and seeds the random number generator.
     *
     * @param symbol The symbol for the bot ('X' or 'O').
     */
    EasyBotPlayer(char symbol) : Player(symbol) {
        srand(time(0));  // Initialize the random number generator
    }

    /**
     * @brief Makes a move for the bot.
     *
     * The bot makes a random move by selecting an empty cell from the board.
     * It updates the game board with its symbol.
     *
     * @param gameBoard The game board (3x3 matrix) where the move will be made.
     * @return returns true, indicating a move was made.
     */
    bool makeMove(std::vector<std::vector<char>>& gameBoard) override {
        // Collect all empty cells
        std::vector<std::pair<int, int>> emptyCells;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (gameBoard[row][col] == ' ') {
                    emptyCells.push_back({row, col});
                }
            }
        }

        // Choose a random move from the empty cells
        std::pair<int, int> move = emptyCells[rand() % emptyCells.size()];
        gameBoard[move.first][move.second] = symbol;  // Make the move
        return true;
    }
};

#endif
