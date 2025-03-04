#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenue.h"

#include "TicTacToeAnsicht.h"

    // Konstante Designauflösung
    const float DESIGN_WIDTH = 1920.0f;
    const float DESIGN_HEIGHT = 1080.0f;

    sf::RenderWindow m_window(sf::VideoMode(800, 600), "TicTacToe App");
    sf::View m_designView = sf::View(sf::FloatRect(0, 0, DESIGN_WIDTH, DESIGN_HEIGHT));
    sf::Color m_backgroundColor(sf::Color(240, 240, 240));



    MainMenue mainMenue = MainMenue(m_window, m_designView );
    TicTacToeAnsicht ticTacToeAnsicht = TicTacToeAnsicht(m_window,m_designView);


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
    }

    void run() {
        // Schriftart und Objekte laden
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Fehler: Schriftart nicht gefunden!" << std::endl;
            return;
        }
        /* Beispiel für ein Button
        sf::RectangleShape button(sf::Vector2f(400, 100));
        button.setFillColor(sf::Color::Blue);
        button.setPosition(760, 540); // Position in Designauflösung

        sf::Text buttonText("Klick mich!", font, 50);
        buttonText.setFillColor(sf::Color::White);

        // Text zentrieren
        sf::FloatRect textBounds = buttonText.getLocalBounds();
        buttonText.setOrigin(textBounds.left + textBounds.width/2.0f,
                             textBounds.top + textBounds.height/2.0f);
        buttonText.setPosition(
                button.getPosition().x + button.getSize().x / 2.0f,
                button.getPosition().y + button.getSize().y / 2.0f
        );
         */

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

            // Setze Design-View
            m_window.setView(m_designView);
            ticTacToeAnsicht.draw(&event);
            //mainMenue.draw(&event);

            m_window.display();
        }
    }

int main() {
    try {
        setupView();
        run();
    }
    catch (const std::exception& e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}