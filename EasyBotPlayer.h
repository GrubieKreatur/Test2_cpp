#ifndef EasyBotSpieler_H
#define EasyBotSpieler_H

#include "Player.h"
#include <cstdlib> // Für zufällige Züge
#include <ctime>   // Für Zufallsgenerator

class EasyBotPlayer : public Player {
public:
    EasyBotPlayer(char symbol) : Player(symbol) {
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

        // Einen zufälligen Zug wählen
        std::pair<int, int> move = emptyCells[rand() % emptyCells.size()];
        gameBoard[move.first][move.second] = symbol;
        return true;
    }
};

#endif
