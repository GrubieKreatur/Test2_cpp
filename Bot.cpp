//
// Created by scsch on 27.02.2025.
//

// Bot.cpp
#include "Bot.h"
#include <cstdlib> // für rand()

Bot::Bot(char player) : player(player) {}

std::pair<int, int> Bot::getMove(const Game& game, bool isHard) {
    if (isHard) {
        return getBestMove(game); // Schwieriger Modus
    } else {
        return getRandomMove(game); // Einfacher Modus
    }
}

std::pair<int, int> Bot::getRandomMove(const Game& game) {
    // Zufällige freie Position finden
    while (true) {
        int row = rand() % 3;
        int col = rand() % 3;
        if (game.getBoard()[row][col] == ' ') {
            return {row, col};
        }
    }
}

std::pair<int, int> Bot::getBestMove(const Game& game) {
    // Hier könnte der MiniMax-Algorithmus implementiert werden, um den besten Zug zu finden
    // Für die Einfachheit nehmen wir einen Dummy-Wert
    return getRandomMove(game); // Dummy
}

