#ifndef NormalBotSpieler_H
#define NormalBotSpieler_H

#include "Spieler.h"
#include <vector>

class NormalBotSpieler : public Spieler {
public:
    NormalBotSpieler(char symbol);
    bool makeMove(std::vector<std::vector<char>>& gameBoard) override;

private:
    bool checkWin(const std::vector<std::vector<char>>& gameBoard);
};

#endif
