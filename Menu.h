
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(){}
    virtual ~Menu() {}

    virtual Menu* draw(sf::Event *pEvent) = 0;


};


#endif
