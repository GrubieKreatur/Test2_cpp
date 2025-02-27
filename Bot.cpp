#include "Bot.h"
#include <cstdlib>

Bot::Bot() {}

void Bot::makeMove(int board[3][3], bool easy) {
    if (easy) {
        // Easy bot makes random moves
        int row, col;
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (board[row][col] != 0);
        board[row][col] = 2;
    } else {
        // Hard bot uses a strategy (e.g., minimax algorithm) to choose the best move
        int move = getBestMove(board);
        int row = move / 3;
        int col = move % 3;
        board[row][col] = 2;
    }
}

int Bot::getBestMove(int board[3][3]) {
    // Here you could implement minimax or any other strategy for the bot
    return rand() % 9; // Random placeholder for best move calculation
}

