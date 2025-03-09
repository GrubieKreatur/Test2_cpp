#ifndef GameFunktionen_H
#define GameFunktionen_H

#include <vector>

namespace GameFunktionen {

/**
 * @brief Checks for a winner in the Tic-Tac-Toe game.
 *
 * This function returns:
 * - 'X' if player X wins
 * - 'O' if player O wins
 * - '-' if there is no winner yet
 *
 * @param gameBoard A 3x3 vector representing the Tic-Tac-Toe board.
 * @return A character representing the winner ('X' or 'O') or '-' if no winner is found.
 */
    static inline char checkWin(const std::vector<std::vector<char>> &gameBoard) {
        // Check all rows and columns for a win
        for (int i = 0; i < 3; ++i) {
            // Check rows
            if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') {
                return gameBoard[i][0]; // Return the winner ('X' or 'O')
            }
            // Check columns
            if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ') {
                return gameBoard[0][i]; // Return the winner ('X' or 'O')
            }
        }

        // Check diagonals for a win
        if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != ' ') {
            return gameBoard[0][0]; // Return the winner ('X' or 'O')
        }
        if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != ' ') {
            return gameBoard[0][2]; // Return the winner ('X' or 'O')
        }

        // No winner found
        return '-';
    }

} // namespace GameFunktionen

#endif
