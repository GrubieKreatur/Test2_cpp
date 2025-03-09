#include "MainMenu.h"
#include "TicTacToeView.h"
#include "HumanPlayer.h"
#include "EasyBotPlayer.h"
#include "NormalBotPlayer.h"
#include "HardBotPlayer.h"
#include "Player.h"

/**
 * Constructor for the MainMenu class.
 * Initializes the window, design view, and font.
 */
MainMenu::MainMenu(sf::RenderWindow &window, sf::View &designView, sf::Font &font)
        : window(window), designView(designView), font(font) {
}

/**
 * Draws the main menu and handles user interactions.
 * @param pEvent Pointer to an SFML event to handle user input.
 * @return A pointer to the new menu if a selection is made, otherwise returns the current menu.
 */
Menu *MainMenu::draw(sf::Event *pEvent) {
    // Create title with centered text alignment
    sf::Text title("Tic-Tac-Toe", font, 75);
    sf::FloatRect textBoundsTitle = title.getLocalBounds();
    title.setOrigin(textBoundsTitle.left + textBoundsTitle.width / 2.0f,
                    textBoundsTitle.top + textBoundsTitle.height / 2.0f);
    title.setPosition(960, 150);
    title.setFillColor(sf::Color::Black);

    // Create multiplayer button
    sf::Text multiplayerButton("Multiplayer", font, 50);
    multiplayerButton.setPosition(825, 400);
    multiplayerButton.setFillColor(sf::Color::Black);

    // Create bot (Easy) button
    sf::Text botEasyButton("Bot (Easy)", font, 50);
    botEasyButton.setPosition(825, 500);
    botEasyButton.setFillColor(sf::Color::Black);

    // Create bot (Normal) button
    sf::Text botNormalButton("Bot (Normal)", font, 50);
    botNormalButton.setPosition(825, 600);
    botNormalButton.setFillColor(sf::Color::Black);

    // Create bot (Hard) button
    sf::Text botHardButton("Bot (Hard)", font, 50);
    botHardButton.setPosition(825, 700);
    botHardButton.setFillColor(sf::Color::Black);

    // Handle mouse interactions
    if (pEvent->type == sf::Event::MouseButtonPressed) {

        // Check if the multiplayer button was clicked
        if (isMouseOver(&multiplayerButton)) {
            pEvent->type = sf::Event::Count; // Reset event type
            return new TicTacToeView(window, designView, font,
                                     new HumanPlayer('X', window, designView, pEvent),
                                     new HumanPlayer('O', window, designView, pEvent));
        }

        // Check if the easy bot button was clicked
        if (isMouseOver(&botEasyButton)) {
            pEvent->type = sf::Event::Count;
            return new TicTacToeView(window, designView, font,
                                     new HumanPlayer('X', window, designView, pEvent),
                                     new EasyBotPlayer('O'));
        }

        // Check if the normal bot button was clicked
        if (isMouseOver(&botNormalButton)) {
            pEvent->type = sf::Event::Count;
            return new TicTacToeView(window, designView, font,
                                     new HumanPlayer('X', window, designView, pEvent),
                                     new NormalBotPlayer('O'));
        }

        // Check if the hard bot button was clicked
        if (isMouseOver(&botHardButton)) {
            pEvent->type = sf::Event::Count;
            return new TicTacToeView(window, designView, font,
                                     new HumanPlayer('X', window, designView, pEvent),
                                     new HardBotPlayer('O'));
        }
    }

    // Change button color when hovered over
    for (sf::Text *button: {&botHardButton, &botEasyButton, &multiplayerButton, &botNormalButton}) {
        if (isMouseOver(button)) {
            button->setFillColor(sf::Color(150, 150, 255)); // Highlight when hovered
        } else {
            button->setFillColor(sf::Color::Black); // Default color
        }
    }

    // Draw all elements on the window
    window.draw(title);
    window.draw(multiplayerButton);
    window.draw(botEasyButton);
    window.draw(botHardButton);
    window.draw(botNormalButton);

    return this; // Return the current menu if no selection was made
}

/**
 * Checks if the mouse cursor is over a given text button.
 * @param textButton Pointer to the text button.
 * @return True if the mouse is over the button, otherwise false.
 */
bool MainMenu::isMouseOver(sf::Text *textButton) {
    // Convert mouse position to world coordinates
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos, designView);

    // Check if the transformed mouse position is inside the button bounds
    return textButton->getGlobalBounds().contains(worldPos.x, worldPos.y);
}
