#ifndef EasyBotSpieler_H
#define EasyBotSpieler_H

#include "Spieler.h"
#include <cstdlib> // Für zufällige Züge
#include <ctime>   // Für Zufallsgenerator

class EasyBot : public Spieler {
public:
    EasyBot(char symbol) : Spieler(symbol) {
        srand(time(0));  // Initialisieren des Zufallsgenerators
    }

    // Ein einfacher Bot macht einen zufälligen Zug
    bool makeMove(std::vector<std::vector<char>>& gameBoard) override {
        // Alle freien Felder sammeln
        std::vector<std::pair<int, int>> emptyCells;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (gameBoard[row][col] == ' ') {
                    emptyCells.push_back({row, col});
                }
            }
        }

        // Überprüfen, ob noch Züge gemacht werden können
        if (emptyCells.empty()) {
            return false;  // Kein Zug möglich
        }

        // Einen zufälligen Zug wählen
        std::pair<int, int> move = emptyCells[rand() % emptyCells.size()];
        gameBoard[move.first][move.second] = symbol;
        return true;
    }
};

#endif
