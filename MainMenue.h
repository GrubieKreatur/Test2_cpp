#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

class MainMenue {
public:
    MainMenue(sf::RenderWindow& window, sf::View& designView );
    bool draw(sf::Event *pEvent);

private:
    sf::RenderWindow& window;
    sf::View &designView;

    bool isMouseOver(sf::Text *button);
};

#endif