
#ifndef HardBotSpieler_H
#define HardBotSpieler_H

#include "Spieler.h"
#include <vector>
#include <limits>
#include <algorithm>

class HardBotSpieler : public Spieler {
public:
    HardBotSpieler(char symbol);

    bool makeMove(std::vector<std::vector<char>>& gameBoard) override;

private:
    char getOpponentSymbol() const;

    int minimax(std::vector<std::vector<char>>& gameBoard,
                int depth,
                bool isMaximizing,
                int alpha,
                int beta);

    int evaluateBoard(const std::vector<std::vector<char>>& gameBoard);
    bool isBoardFull(const std::vector<std::vector<char>>& gameBoard) ;

    int depth;
};

#endif