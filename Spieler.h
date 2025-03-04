#ifndef Spieler_H
#define Spieler_H

#include <vector>



class Spieler {
public:
    Spieler(char symbol) : symbol(symbol) {}
    virtual ~Spieler() {}

    // Abstrakte Methode, die von abgeleiteten Klassen implementiert werden muss
    virtual bool makeMove(std::vector<std::vector<char>>& gameBoard) = 0;

    char getSymbol() const { return symbol; }

protected:
    char symbol;  // 'X' oder 'O'
};

#endif
