#include "TicTacToeAnsicht.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

TicTacToeAnsicht::TicTacToeAnsicht(sf::RenderWindow& window, sf::View& designView)
        : window(window), designView(designView) {
    // Initialize the player and the game board
    currentPlayer = 'X'; // Spieler 'X' starts
    gameBoard = std::vector<std::vector<char>>(3, std::vector<char>(3, ' ')); // Empty Tic-Tac-Toe Board
}

bool TicTacToeAnsicht::draw(sf::Event *pEvent) {
    // Load font
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return false;
    }

    // Create Title
    sf::Text title("Tic-Tac-Toe", font, 75);
    sf::FloatRect textBoundsTitle = title.getLocalBounds();
    title.setOrigin(textBoundsTitle.left + textBoundsTitle.width / 2.0f,
                    textBoundsTitle.top + textBoundsTitle.height / 2.0f);
    title.setPosition(960, 150);
    title.setFillColor(sf::Color::Black);

    // Create Text for current player
    sf::Text currentPlayerText("Aktueller Spieler: " + std::string(1, currentPlayer), font, 40);
    currentPlayerText.setPosition(700, 250);
    currentPlayerText.setFillColor(sf::Color::Black);

    // Handle mouse interactions
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (pEvent->type == sf::Event::MouseButtonPressed) {
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos, designView);
        int row = (worldPos.y - 350) / 200; // Calculate the row
        int col = (worldPos.x - 700) / 200; // Calculate the column

        // If clicked within the grid bounds
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && gameBoard[row][col] == ' ') {
            gameBoard[row][col] = currentPlayer; // Mark the spot with the current player symbol
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
            currentPlayerText.setString("Current Spieler: " + std::string(1, currentPlayer));
        }
    }

    // Draw the Tic-Tac-Toe grid
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // Create a rectangle for each cell in the grid
            sf::RectangleShape cell(sf::Vector2f(200, 200));
            cell.setPosition(700 + j * 200, 350 + i * 200);
            cell.setOutlineColor(sf::Color::Black);
            cell.setOutlineThickness(4);
            cell.setFillColor(sf::Color::White);

            // Draw 'X' or 'O' if the cell is not empty
            sf::Text cellText(std::string(1, gameBoard[i][j]), font, 60);
            cellText.setPosition(700 + j * 200 +70, 350 + i * 200+60);
            cellText.setFillColor(sf::Color::Black);

            window.draw(cell);
            window.draw(cellText);
        }
    }

    // Clear, draw, and display
    ///window.clear(sf::Color::White);
    window.draw(currentPlayerText);
    window.draw(title);
    //window.draw(currentPlayerText);

    return true;
}
