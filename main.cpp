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
        }
        if (event.type == sf::Event::Resized)
        {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
            std::cout << "new width: " << event.size.width << std::endl;
            std::cout << "new height: " << event.size.height << std::endl;
        }

        // Main menu for selecting game mode
        /*
        if (gui.showMainMenu()) {
            multiplayerMode = gui.isMultiplayerSelected();
            botEasy = gui.isBotEasySelected();
            botHard = gui.isBotHardSelected();
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
        */
        //window.clear();
        gui.draw(window, &textStandartGrose); // Ensure the GUI is drawn every frame
        //window.display();
    }

    return 0;
}
