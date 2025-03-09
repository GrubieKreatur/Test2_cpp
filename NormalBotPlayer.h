#ifndef NormalBotSpieler_H
#define NormalBotSpieler_H

#include "Player.h"
#include <vector>

class NormalBotPlayer : public Player {
public:
    NormalBotPlayer(char symbol);
    bool makeMove(std::vector<std::vector<char>>& gameBoard) override;

private:

};

#endif
