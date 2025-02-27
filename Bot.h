//
// Created by scsch on 27.02.2025.
//

#ifndef BOT_H
#define BOT_H

#include "Game.h"

class Bot {
public:
    Bot(char player);
    std::pair<int, int> getMove(const Game& game, bool isHard);
private:
    char player;
    std::pair<int, int> getRandomMove(const Game& game);
    std::pair<int, int> getBestMove(const Game& game);
};

#endif //TEST2_CPP_BOT_H
