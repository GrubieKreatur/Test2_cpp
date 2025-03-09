#include "EasyBotPlayer.h"
#include "NormalBotPlayer.h"
#include "GameUtility.h"

NormalBotPlayer::NormalBotPlayer(char symbol) : Player(symbol) {}

bool NormalBotPlayer::makeMove(std::vector<std::vector<char>>& gameBoard) {
    // Einfache Logik, um zu verhindern, dass der Gegner gewinnt
    char gegnerSymbol =  (symbol == 'X') ? 'O' : 'X';
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (gameBoard[row][col] == ' ') {
                // Simulieren des Zugs
                gameBoard[row][col] = symbol;
                if (GameFunktionen::checkWin(gameBoard)==symbol) {
                    return true;  // Bot hat zuggemacht (gewonnen)
                }
                gameBoard[row][col] = gegnerSymbol;
                if (GameFunktionen::checkWin(gameBoard)==gegnerSymbol) {
                    return true;  // Bot hat zuggemacht (verhindert gegener gewinnt)
                }
                gameBoard[row][col] = ' '; // Rückgängig machen
            }
        }
    }

    // Falls keine Gefahr erkannt wird einen zufälligen Zug gemacht
    return EasyBotPlayer(symbol).makeMove(gameBoard);
}
