#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

/**
 * @brief A class representing a player in the game (either human or bot).
 *
 * The Player class serves as a base class for different types of players, including human players and bot players.
 * It holds common functionality for all players, such as their symbol ('X' or 'O'), and provides an abstract method
 * `makeMove` that must be implemented by derived classes. Derived classes can implement different strategies for making moves.
 */
class Player {
public:
    /**
     * @brief Constructor for Player.
     *
     * Initializes the player with a specific symbol (either 'X' or 'O') which represents the player's moves on the board.
     *
     * @param symbol The symbol assigned to the player (either 'X' or 'O').
     */
    Player(char symbol) : symbol(symbol) {}

    // Virtual destructor to ensure proper cleanup of derived classes.
    virtual ~Player() {}

    /**
     * @brief An abstract method for making a move.
     *
     * This method must be implemented by derived classes to define how the player makes a move on the game board.
     *
     * @param gameBoard The current state of the game board (a 2D vector).
     * @return true if the move was successfully made, false otherwise.
     */
    virtual bool makeMove(std::vector<std::vector<char>> &gameBoard) = 0;

    /**
     * @brief Get the symbol of the player.
     *
     * Returns the symbol ('X' or 'O') of the player.
     *
     * @return The symbol of the player.
     */
    char getSymbol() const { return symbol; }

protected:
    char symbol;  // The player's symbol ('X' or 'O').
};

#endif
