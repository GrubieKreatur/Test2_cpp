#include "EasyBotPlayer.h"
#include "NormalBotPlayer.h"
#include "GameUtility.h"

/**
 * @brief NormalBotPlayer class that extends Player.
 *
 * This bot attempts to block the opponent's winning move or will make a random move if no immediate threats are found.
 */
NormalBotPlayer::NormalBotPlayer(char symbol) : Player(symbol) {}

/**
 * @brief Makes a move for the normal bot.
 *
 * The bot tries to block the opponent's winning move or will make a winning move if possible. If neither is found, it makes a random move.
 *
 * @param gameBoard The current game board (3x3 matrix) where the bot will make its move.
 * @return true If a valid move is made, returns true.
 */
bool NormalBotPlayer::makeMove(std::vector<std::vector<char>> &gameBoard) {
    // Simple logic to prevent the opponent from winning
    char opponentSymbol = (symbol == 'X') ? 'O' : 'X'; // Determine the opponent's symbol

    // Loop through all cells on the board
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (gameBoard[row][col] == ' ') {
                // Simulate the bot's move
                gameBoard[row][col] = symbol;
                // Check if the bot wins with this move
                if (GameFunktionen::checkWin(gameBoard) == symbol) {
                    return true;  // Bot made a move and won
                }
                // Simulate the opponent's move to check if the opponent wins
                gameBoard[row][col] = opponentSymbol;
                if (GameFunktionen::checkWin(gameBoard) == opponentSymbol) {
                    gameBoard[row][col] = symbol; // Block the opponent's winning move
                    return true;  // Bot made a move to prevent the opponent from winning
                }
                // Revert the move if no winning or blocking move is found
                gameBoard[row][col] = ' ';
            }
        }
    }

    // If no immediate threat is found, make a random move
    return EasyBotPlayer(symbol).makeMove(gameBoard); // Fallback to random move logic from EasyBotPlayer
}
