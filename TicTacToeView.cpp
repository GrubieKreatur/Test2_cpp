#include "TicTacToeView.h"
#include <string>
#include "Player.h"
#include "GameUtility.h"
#include "MainMenu.h"

/**
 * Constructor for the TicTacToeView class.
 * Initializes the game board and window.
 */
TicTacToeView::TicTacToeView(sf::RenderWindow &window, sf::View &designView, sf::Font &font, Player *player1, Player *player2)
        : window(window), designView(designView), player1(player1), player2(player2), font(font) {
    currentPlayer = 'X';  // X starts the game
    gameBoard = std::vector<std::vector<char>>(3, std::vector<char>(3, ' ')); // Initialize empty Tic-Tac-Toe board
    winner = '-'; // No winner at the start
}

/**
 * Draws the Tic-Tac-Toe game interface and handles user interactions.
 * @param pEvent Pointer to an SFML event to handle user input.
 * @return A pointer to the updated menu.
 */
Menu *TicTacToeView::draw(sf::Event *pEvent) {
    // Create title text
    sf::Text title("Tic-Tac-Toe", font, 75);
    sf::FloatRect textBoundsTitle = title.getLocalBounds();
    title.setOrigin(textBoundsTitle.left + textBoundsTitle.width / 2.0f,
                    textBoundsTitle.top + textBoundsTitle.height / 2.0f);
    title.setPosition(960, 150);
    title.setFillColor(sf::Color::Black);

    // Create text to display the current player
    sf::Text currentPlayerText("Current Player: " + std::string(1, currentPlayer), font, 40);
    currentPlayerText.setPosition(660, 250);
    currentPlayerText.setFillColor(sf::Color::Black);

    // Create "Back to Menu" button
    sf::Text backToMainMenuButton("Back to Menu", font, 40);
    backToMainMenuButton.setPosition(1020, 1000);
    backToMainMenuButton.setFillColor(sf::Color::Black);

    // Handle mouse click events
    if (pEvent->type == sf::Event::MouseButtonPressed) {
        if (isMouseOver(&backToMainMenuButton)) {
            pEvent->type = sf::Event::Count; // Reset event type
            return new MainMenu(window, designView, font);
        }
    }

    // Handle player moves and check for a winner
    if (winner == '-') {  // Continue the game if there is no winner
        if (currentPlayer == 'X') {
            if (player1->makeMove(gameBoard)) {
                currentPlayer = 'O'; // Switch to the next player
            }
        } else if (currentPlayer == 'O') {
            if (player2->makeMove(gameBoard)) {
                currentPlayer = 'X'; // Switch back to the first player
            }
        }

        // Check if the game board is full
        if (gameBoardFull()) {
            winner = 'u'; // 'u' indicates a draw
        }

        // Check if there is a winner
        char tempWinner = GameFunktionen::checkWin(gameBoard);
        if(tempWinner=='X'||tempWinner=='O'){
            winner= tempWinner;
        }
    }

    // Draw the Tic-Tac-Toe grid and symbols
    sf::RectangleShape cell(sf::Vector2f(200, 200));
    cell.setOutlineColor(sf::Color::Black);
    cell.setOutlineThickness(4);
    cell.setFillColor(sf::Color::White);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // Create a rectangle for each cell in the grid
            cell.setPosition(660 + j * 200, 350 + i * 200);

            // Display 'X' or 'O' in the cell if it is occupied
            sf::Text cellText(std::string(1, gameBoard[i][j]), font, 60);
            cellText.setPosition(660 + j * 200 + 70, 350 + i * 200 + 60);
            cellText.setFillColor(sf::Color::Black);

            window.draw(cell);
            window.draw(cellText);
        }
    }

    // If the game has a winner or is a draw, display the winner text
    if (winner == 'X' || winner == 'O' || winner == 'u') {
        drawWinnerDisplayText();
    }

    // Draw all UI elements
    window.draw(currentPlayerText);
    window.draw(title);
    window.draw(backToMainMenuButton);

    return this;
}

/**
 * Checks if the mouse cursor is over a given text button.
 * @param textButton Pointer to the text button.
 * @return True if the mouse is over the button, otherwise false.
 */
bool TicTacToeView::isMouseOver(sf::Text *textButton) {
    // Convert mouse position to world coordinates
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos, designView);

    // Check if the transformed mouse position is inside the button bounds
    return textButton->getGlobalBounds().contains(worldPos.x, worldPos.y);
}

/**
 * Checks if the Tic-Tac-Toe game board is full.
 * @return True if the board is full, otherwise false.
 */
bool TicTacToeView::gameBoardFull() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (gameBoard[row][col] == ' ') { // If an empty space is found, the board is not full
                return false;
            }
        }
    }
    return true;
}

/**
 * Displays the winner message on the screen.
 */
void TicTacToeView::drawWinnerDisplayText() {
    sf::Text winnerDisplayText;

    // Set winner text depending on game result
    if (winner == 'X' || winner == 'O') {
        winnerDisplayText = sf::Text("Player: " + std::string(1, winner) + " Wins!", font, 80);
    } else {
        winnerDisplayText = sf::Text("Draw! No one wins!", font, 80);
    }

    // Center the text on the screen
    sf::FloatRect winnerDisplayTextBound = winnerDisplayText.getLocalBounds();
    winnerDisplayText.setOrigin(winnerDisplayTextBound.left + winnerDisplayTextBound.width / 2.0f,
                                winnerDisplayTextBound.top + winnerDisplayTextBound.height / 2.0f);
    winnerDisplayText.setPosition(960, 540);
    winnerDisplayText.setFillColor(sf::Color::Black);

    // Create background rectangle behind the winner text
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(winnerDisplayText.getLocalBounds().width + 10,
                                    winnerDisplayText.getLocalBounds().height + 10));
    sf::FloatRect backgroundBound = background.getLocalBounds();
    background.setOrigin(backgroundBound.left + backgroundBound.width / 2.0f,
                         backgroundBound.top + backgroundBound.height / 2.0f);
    background.setPosition(winnerDisplayText.getPosition().x - 5, winnerDisplayText.getPosition().y - 5);
    background.setFillColor(sf::Color::White);

    // Draw the background and winner text
    window.draw(background);
    window.draw(winnerDisplayText);
}
