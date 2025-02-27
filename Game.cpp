#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game() : isPlayerX(true), gameOver(false) {
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
    // Draw the grid
    sf::RectangleShape line;
    line.setSize(sf::Vector2f(600.f, 5.f));
    line.setFillColor(sf::Color::Black);

    // Vertical lines
    for (int i = 1; i < 3; ++i) {
        line.setPosition(i * 200.f, 0);
        window.draw(line);
    }

    // Horizontal lines
    line.setSize(sf::Vector2f(5.f, 600.f));
    for (int i = 1; i < 3; ++i) {
        line.setPosition(0, i * 200.f);
        window.draw(line);
    }

    // Draw X and O
    sf::Font font;
    font.loadFromFile("arial.ttf");
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

bool Game::checkWinner() {
    // Check for a winner
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0)
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0)
            return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)
        return true;

    return false;
}

void Game::handleInput(sf::RenderWindow& window) {
    // Handle mouse input
    if (gameOver)
        return;

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    int row = mousePos.y / 200;
    int col = mousePos.x / 200;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && board[row][col] == 0) {
        board[row][col] = isPlayerX ? 1 : 2;
        isPlayerX = !isPlayerX;
        gameOver = checkWinner();
    }
}

void Game::playMultiplayer(sf::RenderWindow& window) {
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

void Game::playAgainstBot(sf::RenderWindow& window, bool easy, bool hard) {
    // Bot logic (easy/hard) will be handled here
    while (window.isOpen() && !gameOver) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleInput(window);
        // Add bot logic for making a move based on difficulty level
        drawBoard(window);
        window.display();
    }
}


