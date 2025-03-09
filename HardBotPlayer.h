#ifndef HardBotSpieler_H
#define HardBotSpieler_H

#include "Player.h"
#include <vector>
#include <limits>
#include <algorithm>

/**
 * @brief A class that represents a hard-level bot player for the game.
 * 
 * The HardBotPlayer class uses the Minimax algorithm with alpha-beta pruning to make optimal decisions in the game.
 * It tries to choose the best move by simulating all possible outcomes and evaluating them.
 */
class HardBotPlayer : public Player {
public:
    /**
     * @brief Constructor for HardBotPlayer.
     * 
     * Initializes the bot player with the given symbol ('X' or 'O') and sets the initial depth for Minimax to 0.
     * 
     * @param symbol The symbol of the bot player ('X' or 'O').
     */
    HardBotPlayer(char symbol);

    /**
     * @brief Makes a move for the bot player using the Minimax algorithm with alpha-beta pruning.
     * 
     * The bot evaluates all possible moves using Minimax and selects the best move based on the evaluation.
     * 
     * @param gameBoard The current state of the game board (3x3 matrix) on which the bot will make a move.
     * @return true If the bot successfully makes a move.
     */
    bool makeMove(std::vector<std::vector<char>> &gameBoard) override;

private:
    /**
     * @brief Returns the symbol of the opponent.
     * 
     * If the bot's symbol is 'X', it returns 'O'; otherwise, it returns 'X'.
     * 
     * @return The symbol of the opponent player.
     */
    char getOpponentSymbol() const;

    /**
     * @brief Minimax algorithm with alpha-beta pruning to evaluate all possible moves.
     * 
     * This recursive function evaluates the game board by simulating moves and maximizes the bot's score or minimizes
     * the opponent's score based on whose turn it is. Alpha-beta pruning is used to optimize the evaluation.
     * 
     * @param gameBoard The current state of the game board.
     * @param depth The current depth of the recursion, used to limit the number of moves considered.
     * @param isMaximizing True if it's the bot's turn to maximize its score; false if it's the opponent's turn.
     * @param alpha The best score that the maximizing player can guarantee so far.
     * @param beta The best score that the minimizing player can guarantee so far.
     * @return The score of the board (positive for the bot, negative for the opponent, and 0 for a tie).
     */
    int minimax(std::vector<std::vector<char>> &gameBoard,
                int depth,
                bool isMaximizing,
                int alpha,
                int beta);

    /**
     * @brief Evaluates the current board state.
     * 
     * This method checks if a player has won or lost and assigns a score based on the result:
     * - Positive score for the bot's win.
     * - Negative score for the opponent's win.
     * - Zero for a tie or an ongoing game.
     * 
     * @param gameBoard The current state of the game board.
     * @return A positive score for the bot's win, a negative score for the opponent's win, or 0 for a tie/ongoing game.
     */
    int evaluateBoard(const std::vector<std::vector<char>> &gameBoard);

    /**
     * @brief Checks if the game board is full (no empty spaces left).
     * 
     * This method scans the game board to check if there are any empty spaces (' ') remaining.
     * 
     * @param gameBoard The current state of the game board.
     * @return true If the board is full (no empty spaces), otherwise false.
     */
    bool isBoardFull(const std::vector<std::vector<char>> &gameBoard);

    int depth;  ///< The current depth of the Minimax algorithm (used for scoring purposes).
};

#endif
