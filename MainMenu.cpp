#include "MainMenu.h"
#include <iostream>
#include "TicTacToeView.h"
#include "HumanPlayer.h"
#include "EasyBotPlayer.h"
#include "NormalBotPlayer.h"
#include "HardBotPlayer.h"
#include "Player.h"

MainMenu::MainMenu(sf::RenderWindow& window, sf::View& designView,sf::Font &font )
        : window(window),designView(designView),font(font) {
}


Menu* MainMenu::draw(sf::Event *pEvent) {
    // Load font


    //create Title mit zentrierung des Textes
    sf::Text title("Tic-Tac-Toe", font, 75);
    sf::FloatRect textBoundsTitle = title.getLocalBounds();
    title.setOrigin(textBoundsTitle.left + textBoundsTitle.width/2.0f,
                    textBoundsTitle.top + textBoundsTitle.height/2.0f);
    title.setPosition( 960, 150);
    title.setFillColor(sf::Color::Black);

    //create multiplayerButton
    sf::Text multiplayerButton("Multiplayer", font, 50);
    multiplayerButton.setPosition(825, 400);
    multiplayerButton.setFillColor(sf::Color::Black);

    //create botEasyButton
    sf::Text botEasyButton("Bot (Easy)", font, 50);
    botEasyButton.setPosition(825,500);
    botEasyButton.setFillColor(sf::Color::Black);

    //create botHardButton
    sf::Text botNormalButton("Bot (Normal)", font, 50);
    botNormalButton.setPosition(825,600);
    botNormalButton.setFillColor(sf::Color::Black);

    //create botHardButton
    sf::Text botHardButton("Bot (Hard)", font, 50);
    botHardButton.setPosition(825,700);
    botHardButton.setFillColor(sf::Color::Black);

    // Handle mouse interactions
        if (pEvent->type == sf::Event::MouseButtonPressed) {
            std::cout << "Mous Button Presset" << std::endl;
            if (isMouseOver(&multiplayerButton)) {
                std::cout << "Multiplayer-Selected!" << std::endl;
                pEvent->type = sf::Event::Count;
                return new TicTacToeView(window, designView, font,
                                                     new HumanPlayer('X', window, designView, pEvent),
                                                     new HumanPlayer('O', window, designView, pEvent));
            }
            if (isMouseOver(&botEasyButton)) {
                pEvent->type = sf::Event::Count;
                std::cout << "Bot (Easy) Selected!" << std::endl;
                return new TicTacToeView(window, designView,font,
                                                                  new HumanPlayer('X', window, designView, pEvent),
                                                                  new EasyBotPlayer('O'));
            }
            if (isMouseOver(&botNormalButton)) {
                pEvent->type = sf::Event::Count;
                std::cout << "Bot (Normal) Selected!" << std::endl;
                return new TicTacToeView(window, designView,font,
                                                                  new HumanPlayer('X', window, designView, pEvent),
                                                                  new NormalBotPlayer('O'));
            }
            if (isMouseOver(&botHardButton)) {
                pEvent->type = sf::Event::Count;
                std::cout << "Bot (Hard) Selected!" << std::endl;
                return new TicTacToeView(window, designView,font,
                                                                  new HumanPlayer('X', window, designView, pEvent),
                                                                  new HardBotPlayer('O'));
            }

        }

    for (sf::Text *button : {&botHardButton, &botEasyButton, &multiplayerButton,&botNormalButton}) {
        //std::cout <<isMouseOver(button)<< static_cast<sf::Vector2f>(mousePos).x << static_cast<sf::Vector2f>(mousePos).y << std::endl;

        if (isMouseOver(button)) {
            button->setFillColor(sf::Color(150, 150, 255));
            continue;
        } else {
            button->setFillColor(sf::Color::Black);
        }
    }

    // Clear, draw, and display
    //window.clear(sf::Color::White);
    window.draw(title);
    window.draw(multiplayerButton);
    window.draw(botEasyButton);
    window.draw(botHardButton);
    window.draw(botNormalButton);
    //window.display();
    return this;
}

bool MainMenu::isMouseOver(sf::Text *textButton) {
    // Mausposition in Weltkoordinaten umwandeln
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos, designView);
    // Umgewandelte positionen uberprufen
    bool mouseOver = textButton->getGlobalBounds().contains(worldPos.x,worldPos.y);


    return mouseOver;
}