
#include "Spieler.h"
#include "HardBotSpieler.h"
#include <vector>
#include <limits>

//Implementation von einen Algorithmus anforderung
//Inspiriert von: https://www.neverstopbuilding.com/blog/minimax



HardBotSpieler::HardBotSpieler(char symbol) : Spieler(symbol),depth(0) {

}

bool HardBotSpieler::makeMove(std::vector<std::vector<char>>& gameBoard)  {
        int bestScore = std::numeric_limits<int>::min();
        std::pair<int, int> bestMove = {-1, -1};

        // Try every empty cell
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (gameBoard[i][j] == ' ') {
                    gameBoard[i][j] = symbol;
                    int score = minimax(gameBoard, 0, false,
                                        std::numeric_limits<int>::min(),
                                        std::numeric_limits<int>::max());
                    gameBoard[i][j] = ' '; // Undo move

                    if (score > bestScore) {
                        bestScore = score;
                        bestMove = {i, j};
                    }
                }
            }
        }

        // Make the best move
        if (bestMove.first != -1 && bestMove.second != -1) {
            gameBoard[bestMove.first][bestMove.second] = symbol;
            return true;
        }
        return false;
    }

    char HardBotSpieler::getOpponentSymbol() const {
        return (symbol == 'X') ? 'O' : 'X';
    }

    int HardBotSpieler::minimax(std::vector<std::vector<char>>& gameBoard,
                int depth,
                bool isMaximizing,
                int alpha,
                int beta) {
        int result = evaluateBoard(gameBoard);

        // If game is over or max depth reached, return score
        if (result != 0 || depth == 9 || isBoardFull(gameBoard)) {
            return result;
        }

        if (isMaximizing) {
            int bestScore = std::numeric_limits<int>::min();
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (gameBoard[i][j] == ' ') {
                        gameBoard[i][j] = symbol;
                        int score = minimax(gameBoard, depth + 1, false, alpha, beta);
                        gameBoard[i][j] = ' '; // Undo move

                        bestScore = std::max(score, bestScore);
                        alpha = std::max(alpha, bestScore);

                        // Alpha-beta pruning
                        if (beta <= alpha) {
                            break;
                        }
                    }
                }
            }
            return bestScore;
        } else {
            int bestScore = std::numeric_limits<int>::max();
            char opponentSymbol = getOpponentSymbol();
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (gameBoard[i][j] == ' ') {
                        gameBoard[i][j] = opponentSymbol;
                        int score = minimax(gameBoard, depth + 1, true, alpha, beta);
                        gameBoard[i][j] = ' '; // Undo move

                        bestScore = std::min(score, bestScore);
                        beta = std::min(beta, bestScore);

                        // Alpha-beta pruning
                        if (beta <= alpha) {
                            break;
                        }
                    }
                }
            }
            return bestScore;
        }
    }

    int HardBotSpieler::evaluateBoard(const std::vector<std::vector<char>>& gameBoard) {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i) {
            // Check rows
            if (gameBoard[i][0] == gameBoard[i][1] &&
                gameBoard[i][1] == gameBoard[i][2]) {
                if (gameBoard[i][0] == symbol) return 10 - depth;
                if (gameBoard[i][0] == getOpponentSymbol()) return depth - 10;
            }

            // Check columns
            if (gameBoard[0][i] == gameBoard[1][i] &&
                gameBoard[1][i] == gameBoard[2][i]) {
                if (gameBoard[0][i] == symbol) return 10 - depth;
                if (gameBoard[0][i] == getOpponentSymbol()) return depth - 10;
            }
        }

        // Check diagonals
        if (gameBoard[0][0] == gameBoard[1][1] &&
            gameBoard[1][1] == gameBoard[2][2]) {
            if (gameBoard[0][0] == symbol) return 10 - depth;
            if (gameBoard[0][0] == getOpponentSymbol()) return depth - 10;
        }

        if (gameBoard[0][2] == gameBoard[1][1] &&
            gameBoard[1][1] == gameBoard[2][0]) {
            if (gameBoard[0][2] == symbol) return 10 - depth;
            if (gameBoard[0][2] == getOpponentSymbol()) return depth - 10;
        }

        return 0;
    }

    bool HardBotSpieler::isBoardFull(const std::vector<std::vector<char>>& gameBoard) {
        for (const auto& row : gameBoard) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }