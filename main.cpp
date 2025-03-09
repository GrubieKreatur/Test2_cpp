#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenu.h"
#include "Menu.h"
#include "TicTacToeView.h"

// Konstante Designauflösung
const float DESIGN_WIDTH = 1920.0f;
const float DESIGN_HEIGHT = 1080.0f;

sf::RenderWindow m_window(sf::VideoMode(800, 600), "TicTacToe App");
sf::View m_designView = sf::View(sf::FloatRect(0, 0, DESIGN_WIDTH, DESIGN_HEIGHT));
sf::Color m_backgroundColor(sf::Color(240, 240, 240));


sf::Font font;
Menu *oldMenu = nullptr;
Menu *newMenu = nullptr;

void setupView() {

    // Aktualisiere View für proportionale Skalierung
    float windowWidth = m_window.getSize().x;
    float windowHeight = m_window.getSize().y;

    // Skalierungsfaktor berechnen
    float scaleX = windowWidth / DESIGN_WIDTH;
    float scaleY = windowHeight / DESIGN_HEIGHT;

    // Kleineren Skalierungsfaktor verwenden für proportionale Skalierung
    float scale = std::min(scaleX, scaleY);

    // Neue View-Größe berechnen
    float viewWidth = windowWidth / scale;
    float viewHeight = windowHeight / scale;

    // View zentrieren
    m_designView.setSize(viewWidth, viewHeight);
    m_designView.setCenter(DESIGN_WIDTH / 2, DESIGN_HEIGHT / 2);

    if (!font.loadFromFile("Arial.ttf")) {
        exit(-1);
    }

    MainMenu *mainMenu = new MainMenu(m_window, m_designView, font);
    oldMenu = mainMenu;
}

void run() {
    while (m_window.isOpen()) {
        sf::Event event;
        if (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();

            // Bei Größenänderung View neu skalieren
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                m_window.setView(sf::View(visibleArea));
                setupView();
            }

        }

        m_window.clear(m_backgroundColor);
        m_window.setView(m_designView);

        newMenu = oldMenu->draw(&event);
        if (oldMenu != newMenu) {
            delete oldMenu;
            oldMenu = newMenu;
        }
        m_window.display();
    }
}

int main() {
    setupView();
    run();
}