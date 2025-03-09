#ifndef Spieler_H
#define Spieler_H

#include <vector>



class Player {
public:
    Player(char symbol) : symbol(symbol) {}
    virtual ~Player() {}

    // Abstrakte Methode, die von abgeleiteten Klassen implementiert werden muss
    virtual bool makeMove(std::vector<std::vector<char>>& gameBoard) = 0;

    char getSymbol() const { return symbol; }

protected:
    char symbol;  // 'X' oder 'O'
};

#endif
