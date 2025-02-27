//
// Created by scsch on 27.02.2025.
//
// Game.cpp
#include "Game.h"

Game::Game() {
    reset();
}

void Game::reset() {
    for (auto& row : board) {
        row.fill(' ');
    }
}

bool Game::makeMove(int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool Game::checkWinner(char player) {
    // Zeilen, Spalten und Diagonalen prüfen
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool Game::isFull() {
    for (auto& row : board) {
        for (auto& cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

const std::array<std::array<char, 3>, 3>& Game::getBoard() const {
    return board;
}


