//
// Created by scsch on 27.02.2025.
//

// GUI.cpp
#include "GUI.h"
#include "./SFML-3.0.0/include/SFML/Graphics.hpp"

GUI::GUI() {
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
}

void GUI::drawBoard(sf::RenderWindow& window, const Game& game) {
    window.clear(sf::Color::White);
    const auto& board = game.getBoard();
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
            square.setPosition(col * 100.f, row * 100.f);
            square.setOutlineColor(sf::Color::Black);
            square.setOutlineThickness(2.f);
            if (board[row][col] == 'X') {
                square.setFillColor(sf::Color::Red);
            } else if (board[row][col] == 'O') {
                square.setFillColor(sf::Color::Blue);
            } else {
                square.setFillColor(sf::Color::White);
            }
            window.draw(square);

            if (board[row][col] != ' ') {
                text.setString(std::string(1, board[row][col]));
                text.setPosition(col * 100.f + 30.f, row * 100.f + 30.f);
                window.draw(text);
            }
        }
    }
    window.display();
}

void GUI::handleMouseClick(const sf::Event& event, Game& game) {
    if (event.type == sf::Event::MouseButtonPressed) {
        int col = event.mouseButton.x / 100;
        int row = event.mouseButton.y / 100;
        game.makeMove(row, col, 'X'); // Beispiel für Spieler X
    }
}

void GUI::displayWinner(sf::RenderWindow& window, char winner) {
    text.setString(std::string(1, winner) + " wins!");
    text.setPosition(100.f, 320.f);
    window.draw(text);
    window.display();
}

