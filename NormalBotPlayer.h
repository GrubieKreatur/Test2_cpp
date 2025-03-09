#ifndef NORMALBOTPLAYER_H
#define NORMALBOTPLAYER_H

#include "Player.h"
#include <vector>

/**
 * @brief A class representing a normal (non-random) bot player in the game.
 *
 * The NormalBotPlayer class inherits from the Player class and represents a bot that makes strategic moves,
 * potentially blocking or preventing the opponent from winning. It is a more advanced bot than a random move bot but not as
 * advanced as the hard bot (minimax-based). It makes decisions based on simple logic and not complex algorithms.
 */
class NormalBotPlayer : public Player {
public:
    /**
     * @brief Constructor for NormalBotPlayer.
     *
     * This constructor initializes the bot with a specific symbol (either 'X' or 'O') which represents the bot's moves on the board.
     *
     * @param symbol The symbol assigned to the bot (either 'X' or 'O').
     */
    NormalBotPlayer(char symbol);

    /**
     * @brief Makes a move for the bot on the game board.
     *
     * The bot decides on its move based on simple logic. It first checks if there is any opportunity to win,
     * then it checks if it needs to block the opponent from winning. If neither of these conditions are met,
     * it might choose a random move (or another basic strategy).
     *
     * @param gameBoard The current state of the game board (a 2D vector).
     * @return true if the move was successfully made, false otherwise.
     */
    bool makeMove(std::vector<std::vector<char>> &gameBoard) override;

private:
    // No additional members are required for the normal bot player in this class.
};

#endif
