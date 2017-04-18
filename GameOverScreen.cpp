//
// Created by joseph on 4/17/17.
//

#include <iostream>
#include "GameOverScreen.h"
#include "Screens.h"

GameOverScreen::GameOverScreen() {

}

bool GameOverScreen::elapsedFrames(int frames) {
    frameCounter++;
    if (frameCounter >= frames) {
        frameCounter = 0;
        return true;
    }
    return false;
}

int GameOverScreen::run(sf::RenderWindow &window, sf::Texture &Texture) {

    if (!classicFont.loadFromFile("Resources/menu/8bit.ttf")) {
        std::cerr << "Error loading 8bit.ttf" << std::endl;
        return (-1);
    }


    sf::Text gameOverLabel;
    gameOverLabel.setFont(classicFont);
    gameOverLabel.setCharacterSize(200);
    gameOverLabel.setString("GAME OVER");
    sf::FloatRect textRect = gameOverLabel.getLocalBounds();
    gameOverLabel.setOrigin(textRect.left + textRect.width/2.0f,
                            textRect.top  + textRect.height/2.0f);
    gameOverLabel.setPosition({window.getSize().x/2.f, window.getSize().y/2.f});

    sf::Text continueLabel;
    continueLabel.setFont(classicFont);
    continueLabel.setCharacterSize(40);
    continueLabel.setString("Presiona cualquier tecla para continuar");
    sf::FloatRect continueLabelRect = continueLabel.getLocalBounds();
    continueLabel.setOrigin(continueLabelRect.left + continueLabelRect.width/2.0f,
                            continueLabelRect.top  + continueLabelRect.height/2.0f);
    continueLabel.setPosition(window.getSize().x/2.f, window.getSize().y - 40.f);


    while (running) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Resized)
                window.setView(Utils::calcView(sf::Vector2u(event.size.width, event.size.height), Utils::designedsize));
            // Window closed
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
            if (event.type == sf::Event::KeyPressed) {
                return 0;
            }
        }


        window.clear(bg);

        if (elapsedFrames(55)) {
            if (isWhite) {
                continueLabel.setColor(bg);
                isWhite = false;
            } else {
                continueLabel.setColor(sf::Color(255,255,255));
                isWhite = true;
            }
        }


        window.draw(gameOverLabel);
        window.draw(continueLabel);
        window.display();

    }


    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
