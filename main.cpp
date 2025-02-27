#include <SFML/Graphics.hpp>
#include "GUI.h"
#include "Game.h"
#include "Bot.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Tic-Tac-Toe");

    GUI gui(window);
    Game game;
    Bot bot;

    bool multiplayerMode = false;
    bool botEasy = false;
    bool botHard = false;

    while (window.isOpen()) {
        // Main menu for selecting game mode
        if (gui.showMainMenu()) {
            multiplayerMode = gui.isMultiplayerSelected();
            botEasy = gui.isBotEasySelected();
            botHard = gui.isBotHardSelected();
        }

        game.reset(); // Reset the game for each round

        if (multiplayerMode) {
            game.playMultiplayer(window);
        } else {
            game.playAgainstBot(window, botEasy, botHard);
        }

        window.clear();
        gui.draw(window);
        window.display();
    }

    return 0;
}
