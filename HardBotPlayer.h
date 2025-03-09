
#ifndef HardBotSpieler_H
#define HardBotSpieler_H

#include "Player.h"
#include <vector>
#include <limits>
#include <algorithm>

class HardBotPlayer : public Player {
public:
    HardBotPlayer(char symbol);

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