// main.cpp
#include "./SFML-3.0.0/include/SFML/Graphics.hpp"
#include "Game.h"
#include "Bot.h"
#include "GUI.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 400), "Tic Tac Toe");
    Game game;
    GUI gui;
    Bot bot('O');
    bool isHard = true; // Schwieriger Schwierigkeitsgrad
    bool isPlayerTurn = true; // Wahr für den Spieler, falsch für den Bot

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            gui.handleMouseClick(event, game);
        }

        if (!game.isFull() && !game.checkWinner('X') && !game.checkWinner('O')) {
            if (isPlayerTurn) {
                gui.drawBoard(window, game);
            } else {
                auto move = bot.getMove(game, isHard);
                game.makeMove(move.first, move.second, 'O');
                isPlayerTurn = !isPlayerTurn;
                gui.drawBoard(window, game);
            }
        } else {
            char winner = game.checkWinner('X') ? 'X' : (game.checkWinner('O') ? 'O' : ' ');
            gui.displayWinner(window, winner);
        }
    }

    return 0;
}
