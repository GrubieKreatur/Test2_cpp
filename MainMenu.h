#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "Menu.h"
class MainMenu : public  Menu {
public:

    MainMenu(sf::RenderWindow &window, sf::View &designView, sf::Font &font);

    Menu* draw(sf::Event *pEvent) override;

private:
    sf::RenderWindow& window;
    sf::View &designView;
    sf::Font &font;

    bool isMouseOver(sf::Text *button);
};

#endif