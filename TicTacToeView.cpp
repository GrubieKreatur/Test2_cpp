#include "TicTacToeView.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "GameUtility.h"
#include "MainMenu.h"

TicTacToeView::TicTacToeView(sf::RenderWindow &window, sf::View &designView,sf::Font &font , Player *player1, Player *player2)
        : window(window), designView(designView), player1(player1), player2(player2), font(font) {
    currentPlayer = 'X';
    gameBoard = std::vector<std::vector<char>>(3, std::vector<char>(3, ' ')); // Empty Tic-Tac-Toe Board
    winner = '-';

}

Menu *TicTacToeView::draw(sf::Event *pEvent) {
    // Create Title
    sf::Text title("Tic-Tac-Toe", font, 75);
    sf::FloatRect textBoundsTitle = title.getLocalBounds();
    title.setOrigin(textBoundsTitle.left + textBoundsTitle.width / 2.0f,
                    textBoundsTitle.top + textBoundsTitle.height / 2.0f);
    title.setPosition(960, 150);
    title.setFillColor(sf::Color::Black);

    // Create Text for current player
    sf::Text currentPlayerText("Current Player: " + std::string(1, currentPlayer), font, 40);
    currentPlayerText.setPosition(660, 250);
    currentPlayerText.setFillColor(sf::Color::Black);

    //
    sf::Text backToMainMenuButton("Back to Menu", font, 40);
    backToMainMenuButton.setPosition(1020, 1000);
    backToMainMenuButton.setFillColor(sf::Color::Black);

    if (pEvent->type == sf::Event::MouseButtonPressed) {
        if (isMouseOver(&backToMainMenuButton)) {
            pEvent->type = sf::Event::Count;
            return new MainMenu(window, designView,font);
        }

    }

    if (winner == '-') {
        if (currentPlayer == 'X') {
            if (player1->makeMove(gameBoard)) {
                currentPlayer = 'O';
            }
        } else if (currentPlayer == 'O') {
            if (player2->makeMove(gameBoard)) {
                currentPlayer = 'X';
            }
        } else {
            std::cerr << "Error currentPlayer is: " << currentPlayer << std::endl;
        }
        if (gameBoardFull()) {
            winner = 'u';
        }
        winner = GameFunktionen::checkWin(gameBoard);
    }

    // Draw the Tic-Tac-Toe grid
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // Create a rectangle for each cell in the grid
            sf::RectangleShape cell(sf::Vector2f(200, 200));
            cell.setPosition(660 + j * 200, 350 + i * 200);
            cell.setOutlineColor(sf::Color::Black);
            cell.setOutlineThickness(4);
            cell.setFillColor(sf::Color::White);

            // Draw 'X' or 'O' if the cell is not empty
            sf::Text cellText(std::string(1, gameBoard[i][j]), font, 60);
            cellText.setPosition(660 + j * 200 + 70, 350 + i * 200 + 60);
            cellText.setFillColor(sf::Color::Black);

            window.draw(cell);
            window.draw(cellText);
        }
    }
    if (winner == 'X' || winner == 'O' || winner == 'u') {
        drawWinnerDisplayText();
    }

    window.draw(currentPlayerText);
    window.draw(title);
    window.draw(backToMainMenuButton);

    return this;
}

bool TicTacToeView::isMouseOver(sf::Text *textButton) {
    // Mausposition in Weltkoordinaten umwandeln
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos, designView);
    // Umgewandelte positionen uberprufen
    bool mouseOver = textButton->getGlobalBounds().contains(worldPos.x, worldPos.y);


    return mouseOver;
}

bool TicTacToeView::gameBoardFull() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (gameBoard[row][col] == ' ') {
                std::cout << row << col << std::endl;
                return false;
            }
        }
    }
    return true;
}

void TicTacToeView::drawWinnerDisplayText() {
    sf::Text winnerDisplayText;
    if (winner == 'X' || winner == 'O') {
        winnerDisplayText = sf::Text("Player : " + std::string(1, winner) + " Wins!", font, 80);
    } else {
        winnerDisplayText = sf::Text("Draw no one wins!", font, 80);
    }
    sf::FloatRect winnerDisplayTextBound = winnerDisplayText.getLocalBounds();
    winnerDisplayText.setOrigin(winnerDisplayTextBound.left + winnerDisplayTextBound.width / 2.0f,
                                winnerDisplayTextBound.top + winnerDisplayTextBound.height / 2.0f);
    winnerDisplayText.setPosition(960, 540);
    winnerDisplayText.setFillColor(sf::Color::Black);

    sf::RectangleShape background;
    background.setSize(sf::Vector2f(winnerDisplayText.getLocalBounds().width + 10,
                                    winnerDisplayText.getLocalBounds().height + 10));
    sf::FloatRect backgroundBound = background.getLocalBounds();
    background.setOrigin(backgroundBound.left + backgroundBound.width / 2.0f,
                         backgroundBound.top + backgroundBound.height / 2.0f);
    winnerDisplayText.setPosition(960, 540);
    background.setPosition(winnerDisplayText.getPosition().x - 5, winnerDisplayText.getPosition().y - 5);
    background.setFillColor(sf::Color::White);
    window.draw(background);
    window.draw(winnerDisplayText);
    if (winner == 'X' || winner == 'O') {
        sf::Text("Player : " + std::string(1, winner) + " Wins!", font, 80);
    } else {
        sf::Text("Draw no one wins!", font, 80);
    }
}