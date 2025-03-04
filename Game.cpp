//
// Created by scsch on 27.02.2025.
//
// Game.cpp
#include "Game.h"

Game::Game() {
    reset();
}

void Game::reset() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = 0;
        }
    }
    isPlayerX = true;
    gameOver = false;
}

void Game::drawBoard(sf::RenderWindow& window) {
    // Draw the grid (main board lines)
    sf::RectangleShape line;
    line.setFillColor(sf::Color::Black);

    // Vertical lines
    for (int i = 1; i < 3; ++i) {
        line.setSize(sf::Vector2f(5.f, 600.f));  // Adjusted size for vertical lines
        line.setPosition(i * 200.f, 0);
        window.draw(line);
    }

    // Horizontal lines
    line.setSize(sf::Vector2f(600.f, 5.f));  // Adjusted size for horizontal lines
    for (int i = 1; i < 3; ++i) {
        line.setPosition(0, i * 200.f);
        window.draw(line);
    }

    // Draw X and O
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {  // Ensure the font is loaded
        std::cerr << "Failed to load font!" << std::endl;
    }
    sf::Text text("", font, 100);
    text.setFillColor(sf::Color::Black);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 1) {
                text.setString("X");
                text.setPosition(j * 200 + 50, i * 200 + 50);
                window.draw(text);
            }
            else if (board[i][j] == 2) {
                text.setString("O");
                text.setPosition(j * 200 + 50, i * 200 + 50);
                window.draw(text);
            }
        }
    }
}

bool Game::makeMove(int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool Game::checkWinner(char player) {
    // Zeilen, Spalten und Diagonalen prüfen
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool Game::isFull() {
    for (auto& row : board) {
        for (auto& cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void Game::playAgainstBot(sf::RenderWindow& window, bool easy, bool hard) {
    while (window.isOpen() && !gameOver) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleInput(window);
        drawBoard(window);
        window.display();
    }
}
