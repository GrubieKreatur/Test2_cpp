//
// Created by scsch on 27.02.2025.
//

// GUI.cpp
#include "GUI.h"
#include "./SFML-3.0.0/include/SFML/Graphics.hpp"

GUI::GUI(sf::RenderWindow& window) : window(window) {}

bool GUI::showMainMenu() {
    // Simple logic for handling user input on the main menu
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    sf::Text title("Tic-Tac-Toe", font, 50);
    title.setPosition(200, 50);
    title.setFillColor(sf::Color::Black);

    sf::Text multiplayerButton("Multiplayer", font, 30);
    multiplayerButton.setPosition(250, 150);
    multiplayerButton.setFillColor(sf::Color::Black);

    sf::Text botEasyButton("Bot (Easy)", font, 30);
    botEasyButton.setPosition(250, 200);
    botEasyButton.setFillColor(sf::Color::Black);

    sf::Text botHardButton("Bot (Hard)", font, 30);
    botHardButton.setPosition(250, 250);
    botHardButton.setFillColor(sf::Color::Black);

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Event event;
    if (botHardButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        botHardButton.setFillColor(sf::Color(150, 150, 255)); // Hover-Effekt

        // Prüfen, ob die linke Maustaste gedrückt wurde
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::cout << "Button wurde geklickt!" << std::endl;
        }
    } else {
        botHardButton.setFillColor(sf::Color(100, 100, 250)); // Zurück zur Standardfarbe
    }


        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Mausposition im Fenster

            if (multiplayerButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                std::cout << "Multiplayer-Modus ausgewählt!" << std::endl;
            }
            if (botEasyButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                std::cout << "Bot (Easy) Modus ausgewählt!" << std::endl;
            }
            if (botHardButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                std::cout << "Bot (Hard) Modus ausgewählt!" << std::endl;
            }
        }



    window.clear(sf::Color::White);
    window.draw(title);
    window.draw(multiplayerButton);
    window.draw(botEasyButton);
    window.draw(botHardButton);
    window.display();

    return true;
}

bool GUI::isMultiplayerSelected() {
    return false; // Always multiplayer for testing, modify to check input
}

bool GUI::isBotEasySelected() {
    return false; // Always easy bot for testing, modify to check input
}

bool GUI::isBotHardSelected() {
    return false; // Always hard bot for testing, modify to check input
}

void GUI::draw(sf::RenderWindow& window) {
    // Empty for now, just used to draw buttons or background
    showMainMenu();

}
