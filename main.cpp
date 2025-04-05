#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Menu.h"
#include "TicTacToeView.h"

// Constant design resolution
const float DESIGN_WIDTH = 1920.0f;
const float DESIGN_HEIGHT = 1080.0f;

// Create the main application window
sf::RenderWindow m_window(sf::VideoMode(800, 600), "TicTacToe App");

// Define a view to maintain aspect ratio scaling
sf::View m_designView = sf::View(sf::FloatRect(0, 0, DESIGN_WIDTH, DESIGN_HEIGHT));

// Define background color
sf::Color m_backgroundColor(sf::Color(240, 240, 240));

// Font for text rendering
sf::Font font;

// Pointers to track the current and new menus
Menu *oldMenu = nullptr;
Menu *newMenu = nullptr;

/**
 * Sets up the initial view and loads the font.
 * Initializes the main menu.
 */
void setupView() {
    // Get the current window dimensions
    float windowWidth = m_window.getSize().x;
    float windowHeight = m_window.getSize().y;

    // Calculate scaling factors
    float scaleX = windowWidth / DESIGN_WIDTH;
    float scaleY = windowHeight / DESIGN_HEIGHT;

    // Use the smaller scale factor for proportional scaling
    float scale = std::min(scaleX, scaleY);

    // Calculate the new view size
    float viewWidth = windowWidth / scale;
    float viewHeight = windowHeight / scale;

    // Center the view
    m_designView.setSize(viewWidth, viewHeight);
    m_designView.setCenter(DESIGN_WIDTH / 2, DESIGN_HEIGHT / 2);

    // Load font from file
    if (!font.loadFromFile("./assets/Arial.ttf")) {
        exit(-1); // Exit if font loading fails
    }

    // Create the main menu and set it as the current menu
    MainMenu *mainMenu = new MainMenu(m_window, m_designView, font);
    oldMenu = mainMenu;
}

/**
 * Runs the main application loop.
 * Handles events, updates the menu, and renders the window.
 */
void run() {
    while (m_window.isOpen()) {
        sf::Event event{};

        // Check for events
        if (m_window.pollEvent(event)) {
            // Close window if the close event is triggered
            if (event.type == sf::Event::Closed)
                m_window.close();

            // Resize the view proportionally when the window is resized
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                m_window.setView(sf::View(visibleArea));
                setupView(); // Recalculate the view
            }
        }

        // Clear the window with the background color
        m_window.clear(m_backgroundColor);
        m_window.setView(m_designView);

        // Update the menu and check if it has changed
        newMenu = oldMenu->draw(&event);
        if (oldMenu != newMenu) {
            delete oldMenu; // Free memory of the old menu
            oldMenu = newMenu;
        }

        // Display the updated window
        m_window.display();
    }
}

/**
 * The main entry point of the application.
 * Initializes the view and starts the main loop.
 */
int main() {
    setupView();
    run();
}
