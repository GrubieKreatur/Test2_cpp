#include "GUI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GUI::GUI(sf::RenderWindow& window) : window(window) {}

bool GUI::showMainMenu() {
    // Show the main menu and return if the user selected multiplayer or bot mode
    return true;
}

bool GUI::isMultiplayerSelected() {
    return true;
}

bool GUI::isBotEasySelected() {
    return true;
}

bool GUI::isBotHardSelected() {
    return true;
}

void GUI::draw(sf::RenderWindow& window) {
    // Draw all UI elements
}

