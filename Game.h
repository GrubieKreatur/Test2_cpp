//
// Created by scsch on 27.02.2025.
//

// Game.h
#ifndef GAME_H
#define GAME_H

#include <array>

class Game {
public:
    Game();
    void reset(); // Spiel zurücksetzen
    bool makeMove(int row, int col, char player); // Zug machen
    bool checkWinner(char player); // Überprüfen ob der Spieler gewonnen hat
    bool isFull(); // Überprüfen ob das Spielfeld voll ist
    const std::array<std::array<char, 3>, 3>& getBoard() const;  // Konstante Methode, gibt konstante Referenz zurück

private:
    std::array<std::array<char, 3>, 3> board;
};

#endif
 //TEST2_CPP_GAME_H
