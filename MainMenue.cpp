#include "MainMenue.h"
//Kann eigentlich weggelassen werden da es in der h schon ist
//#include <SFML/Graphics.hpp>
#include <iostream>

MainMenue::MainMenue(sf::RenderWindow& window, sf::View& designView )
        : window(window),designView(designView) {}


bool MainMenue::draw(sf::Event *pEvent) {
    // Load font
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return false;
    }

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
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (pEvent->type == sf::Event::MouseButtonPressed) {
            std::cout << "Button Press!" << std::endl;


            if (multiplayerButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                std::cout << "Multiplayer-Modus ausgewählt!" << std::endl;
            }
            if (botEasyButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                std::cout << "Bot (Easy) Modus ausgewählt!" << std::endl;
            }
            if (botHardButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                std::cout << "Bot (Hard) Modus ausgewählt!" << std::endl;
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
    return true;
}

bool MainMenue::isMouseOver(sf::Text *textButton) {
    // Mausposition in Weltkoordinaten umwandeln
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos, designView);
    // Umgewandelte positionen uberprufen
    bool mouseOver = textButton->getGlobalBounds().contains(worldPos.x,worldPos.y);
    //std::cout  << "x:" << worldPos.x<< "y:"<< worldPos.y << "Ergebnis:"<< mouseOver<< std::endl;


    return mouseOver;
}