#include "Player.h"
#include "HardBotPlayer.h"
#include <vector>
#include <limits>

// Inspired by: https://www.neverstopbuilding.com/blog/minimax

/**
 * @brief Constructor for HardBotPlayer
 * 
 * Initializes the HardBotPlayer with the given symbol ('X' or 'O') and sets the initial depth to 0.
 */
HardBotPlayer::HardBotPlayer(char symbol) : Player(symbol), depth(0) {}

/**
 * @brief Makes a move for the hard bot using the Minimax algorithm.
 *
 * The bot evaluates all possible moves using Minimax with alpha-beta pruning to choose the optimal move.
 *
 * @param gameBoard The current game board (3x3 matrix) where the bot will make its move.
 * @return true If the bot successfully made a move.
 */
bool HardBotPlayer::makeMove(std::vector<std::vector<char>>& gameBoard)  {
    int bestScore = std::numeric_limits<int>::min();  // Initialize the best score to the lowest possible
    std::pair<int, int> bestMove = {-1, -1};  // Store the best move coordinates

    // Try every empty cell and evaluate the score using the minimax algorithm
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (gameBoard[i][j] == ' ') {
                gameBoard[i][j] = symbol;  // Make the move
                int score = minimax(gameBoard, 0, false,
                                    std::numeric_limits<int>::min(),
                                    std::numeric_limits<int>::max());  // Evaluate the move
                gameBoard[i][j] = ' ';  // Undo the move

                if (score > bestScore) {
                    bestScore = score;  // Update the best score
                    bestMove = {i, j};  // Store the best move
                }
            }
        }
    }

    // Make the best move
    if (bestMove.first != -1 && bestMove.second != -1) {
        gameBoard[bestMove.first][bestMove.second] = symbol;  // Apply the best move
        return true;
    }
    return false;  // Return false if no move was made
}

/**
 * @brief Gets the opponent's symbol ('X' if the bot's symbol is 'O', 'O' if the bot's symbol is 'X')
 * 
 * @return The opponent's symbol
 */
char HardBotPlayer::getOpponentSymbol() const {
    return (symbol == 'X') ? 'O' : 'X';  // Returns 'O' if the bot's symbol is 'X' and vice versa
}

/**
 * @brief Minimax algorithm with alpha-beta pruning.
 * 
 * This method recursively evaluates the game board by simulating moves. It maximizes the bot's score and minimizes the opponent's score.
 * Alpha-beta pruning is used to optimize the decision-making process.
 * 
 * @param gameBoard The current game board.
 * @param depth The current depth of the recursion (used to limit the number of moves considered).
 * @param isMaximizing If true, the bot is maximizing its score, otherwise, the opponent is minimizing it.
 * @param alpha The best score the maximizing player can guarantee so far.
 * @param beta The best score the minimizing player can guarantee so far.
 * @return The score of the board (positive for the bot, negative for the opponent, 0 for a tie).
 */
int HardBotPlayer::minimax(std::vector<std::vector<char>>& gameBoard,
                           int depth,
                           bool isMaximizing,
                           int alpha,
                           int beta) {
    int result = evaluateBoard(gameBoard);  // Evaluate the current board state

    // If the game is over or max depth reached, return the score
    if (result != 0 || depth == 9 || isBoardFull(gameBoard)) {
        return result;  // Return the result if game is over or no more moves are possible
    }

    if (isMaximizing) {
        int bestScore = std::numeric_limits<int>::min();  // Maximizing player's best score
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (gameBoard[i][j] == ' ') {
                    gameBoard[i][j] = symbol;  // Simulate the bot's move
                    int score = minimax(gameBoard, depth + 1, false, alpha, beta);  // Recur for the opponent
                    gameBoard[i][j] = ' ';  // Undo the move

                    bestScore = std::max(score, bestScore);  // Choose the best score
                    alpha = std::max(alpha, bestScore);  // Update alpha

                    // Alpha-beta pruning
                    if (beta <= alpha) {
                        break;  // Stop exploring further if pruning condition met
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = std::numeric_limits<int>::max();  // Minimizing player's best score
        char opponentSymbol = getOpponentSymbol();  // Get the opponent's symbol
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (gameBoard[i][j] == ' ') {
                    gameBoard[i][j] = opponentSymbol;  // Simulate the opponent's move
                    int score = minimax(gameBoard, depth + 1, true, alpha, beta);  // Recur for the bot
                    gameBoard[i][j] = ' ';  // Undo the move

                    bestScore = std::min(score, bestScore);  // Choose the best score
                    beta = std::min(beta, bestScore);  // Update beta

                    // Alpha-beta pruning
                    if (beta <= alpha) {
                        break;  // Stop exploring further if pruning condition met
                    }
                }
            }
        }
        return bestScore;
    }
}

/**
 * @brief Evaluates the current state of the board.
 * 
 * This method checks if a player has won or lost and assigns scores based on the result.
 * 
 * @param gameBoard The current game board.
 * @return A positive score for the bot's win, a negative score for the opponent's win, and 0 for a tie or ongoing game.
 */
int HardBotPlayer::evaluateBoard(const std::vector<std::vector<char>>& gameBoard) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
            if (gameBoard[i][0] == symbol) return 10 - depth;  // Bot wins
            if (gameBoard[i][0] == getOpponentSymbol()) return depth - 10;  // Opponent wins
        }

        // Check columns
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) {
            if (gameBoard[0][i] == symbol) return 10 - depth;  // Bot wins
            if (gameBoard[0][i] == getOpponentSymbol()) return depth - 10;  // Opponent wins
        }
    }

    // Check diagonals
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
        if (gameBoard[0][0] == symbol) return 10 - depth;  // Bot wins
        if (gameBoard[0][0] == getOpponentSymbol()) return depth - 10;  // Opponent wins
    }

    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
        if (gameBoard[0][2] == symbol) return 10 - depth;  // Bot wins
        if (gameBoard[0][2] == getOpponentSymbol()) return depth - 10;  // Opponent wins
    }

    return 0;  // Tie, no winner
}

/**
 * @brief Checks if the board is full (no empty spaces).
 * 
 * @param gameBoard The current game board.
 * @return true If the board is full, false otherwise.
 */
bool HardBotPlayer::isBoardFull(const std::vector<std::vector<char>>& gameBoard) {
    for (const auto& row : gameBoard) {
        for (char cell : row) {
            if (cell == ' ') return false;  // If there's an empty space, return false
        }
    }
    return true;  // The board is full
}
