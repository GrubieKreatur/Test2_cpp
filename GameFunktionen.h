#ifndef GameFunktionen_H
#define GameFunktionen_H

#include <vector>
namespace GameFunktionen{
//gibt '-' zurück wenn kein gewinner und sonnst 'x' oder'o' je nachdem wer gewonnen hat
char checkWin(const std::vector<std::vector<char>>& gameBoard){
        // Überprüfe alle Zeilen Spalten und Diagonalen auf einen Gewinn
        for (int i = 0; i < 3; ++i) {
            // Zeilen
            if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') {
                return gameBoard[i][0];
            }
            // Spalten
            if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ') {
                return gameBoard[0][i];
            }
        }
        // Diagonalen
        if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != ' ') {
            return gameBoard[0][0];
        }
        if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != ' ') {
            return gameBoard[0][2];
        }

        return '-';

}
}

#endif
