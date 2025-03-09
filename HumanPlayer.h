#ifndef MenschSpieler_H
#define MenschSpieler_H

#include "Player.h"
#include <SFML/Graphics.hpp>

/**
 * @brief A class representing a human player in the game.
 *
 * The HumanPlayer class allows a human to interact with the game via mouse input.
 * It maps the mouse clicks to the game board and makes a move if the clicked cell is valid.
 */
class HumanPlayer : public Player {
private:
    sf::RenderWindow &window;     ///< Reference to the SFML window for handling events and mouse input.
    sf::Event *pEvent;            ///< Pointer to the SFML event for handling the mouse click events.
    sf::View &designView;         ///< Reference to the SFML view used to map pixel positions to game world coordinates.

public:
    /**
     * @brief Constructor for HumanPlayer.
     *
     * Initializes the human player with a symbol and SFML components like window, design view, and event pointer.
     *
     * @param symbol The symbol ('X' or 'O') of the human player.
     * @param window The SFML window where the game is rendered.
     * @param designView The SFML view that defines the game world and its coordinates.
     * @param pEvent Pointer to the SFML event to process mouse input.
     */
    HumanPlayer(char symbol, sf::RenderWindow &window, sf::View &designView, sf::Event *pEvent)
            : Player(symbol), designView(designView), window(window), pEvent(pEvent) {}

    /**
     * @brief Makes a move for the human player based on mouse input.
     *
     * This function checks if the mouse button was pressed, and then it calculates the corresponding row and column
     * on the game board based on the mouse's position relative to the window. If the cell is empty, the human player
     * places their symbol in the selected cell.
     *
     * @param gameBoard The current state of the game board (3x3 matrix).
     * @return true If a valid move was made, false otherwise.
     */
    bool makeMove(std::vector<std::vector<char>> &gameBoard) override {
        // Check if the mouse button was pressed
        if (pEvent->type == sf::Event::MouseButtonPressed) {
            // Get the position of the mouse in pixel coordinates
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            // Convert pixel coordinates to world coordinates
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos, designView);

            // Calculate the row and column based on the world position
            int row = (worldPos.y - 350) / 200;  // Calculate the row position (adjust for game layout)
            int col = (worldPos.x - 660) / 200;  // Calculate the column position (adjust for game layout)

            // Check if the clicked position is within bounds and the cell is empty
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && gameBoard[row][col] == ' ') {
                gameBoard[row][col] = symbol;  // Place the human player's symbol on the board
                return true;  // Successfully made a move
            }
        }
        return false;  // Return false if no valid move was made
    }
};

#endif
