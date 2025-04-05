#ifndef TICTACTOEVIEW_H
#define TICTACTOEVIEW_H

#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Player.h"
#include "Menu.h"

/**
 * @brief A class representing the game view for Tic-Tac-Toe, handling the game logic and rendering.
 *
 * This class is responsible for displaying the Tic-Tac-Toe game and handling interactions between the user and the game.
 * It includes methods for drawing the game board, detecting mouse events, determining the winner, and more.
 * It also manages two players (player1 and player2) and alternates between them during the game.
 */
class TicTacToeView : public Menu {
public:
    /**
     * @brief Constructor for TicTacToeView.
     *
     * Initializes the game view, including the window, design view, font, and the two players (player1 and player2).
     *
     * @param window The render window for displaying the game.
     * @param designView The view used to manage the display scaling and transformations.
     * @param font The font used for text rendering in the game.
     * @param player1 The first player in the game.
     * @param player2 The second player in the game.
     */
    TicTacToeView(sf::RenderWindow &window, sf::View &designView, sf::Font &font, Player *player1, Player *player2);

    // Destructor that deletes the player objects to prevent memory leaks.
    ~TicTacToeView() {
        if (player1 != nullptr) {
            delete player1;
            player1 = nullptr;
        }
        if (player2 != nullptr) {
            delete player2;
            player2 = nullptr;
        }
    }

    /**
     * @brief Draws the game view and handles user interactions.
     *
     * This method renders the game board, handles mouse events, and checks if the game has ended.
     * It returns a new Menu object (used for transitioning to different game states or menus).
     *
     * @param pEvent The event object used for handling input events like mouse clicks.
     * @return A pointer to a Menu object, which could represent a new menu state.
     */
    Menu *draw(sf::Event *pEvent) override;

private:
    char currentPlayer;  ///< The symbol of the current player ('X' or 'O').
    char winner;         ///< The symbol of the winner ('X' or 'O') or '-' if no winner.
    std::vector<std::vector<char>> gameBoard;  ///< The 3x3 game board represented as a 2D vector.
    sf::RenderWindow &window;  ///< The render window used for drawing.
    sf::View &designView;      ///< The view used for scaling and positioning.
    sf::Font &font;            ///< The font used for displaying text.
    Player *player1;           ///< Pointer to the first player.
    Player *player2;           ///< Pointer to the second player.

    /**
     * @brief Checks if the mouse is over a given button text.
     *
     * This method checks if the mouse cursor is hovering over a specific text button in the game view.
     *
     * @param textButton The text button to check.
     * @return true if the mouse is over the button, false otherwise.
     */
    bool isMouseOver(sf::Text *textButton);

    /**
     * @brief Checks if the game board is full.
     *
     * This method checks if there are any empty cells left on the game board.
     * It is used to determine if the game has ended in a draw.
     *
     * @return true if the game board is full, false otherwise.
     */
    bool gameBoardFull();

    /**
     * @brief Draws the winner display text on the screen.
     *
     * This method renders a message displaying the winner ('X' or 'O') or a draw message when the game ends.
     */
    void drawWinnerDisplayText();
};

#endif
