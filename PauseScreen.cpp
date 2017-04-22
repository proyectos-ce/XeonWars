//
// Created by joseph on 4/17/17.
//

#include <iostream>
#include "PauseScreen.h"
#include "Utils.h"
#include <unistd.h>

PauseScreen::PauseScreen() {

    if (!classicFont.loadFromFile("Resources/menu/8bit.ttf"))
    {
        std::cerr << "Error loading 8bit.ttf" << std::endl;
    }

    continueLabel.setFont(classicFont);
    continueLabel.setCharacterSize(40);
    continueLabel.setString("Continue");
    continueLabel.setPosition({ 280.f, 300.f });


    exitLabel.setFont(classicFont);
    exitLabel.setCharacterSize(40);
    exitLabel.setString("Exit");
    exitLabel.setPosition({ 280.f, 400.f });


}

int PauseScreen::run(sf::RenderWindow &window, sf::Texture &pauseScreen, Options* gameOptions) {



    background.setColor(sf::Color(255,255,255,120));
    background.setTexture(pauseScreen);


    sf::Event event;

    menu = 0;

    while (running) {
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Resized)
                window.setView(Utils::calcView(sf::Vector2u(event.size.width, event.size.height), Utils::designedsize));
            // Window closed
            if (event.type == sf::Event::Closed)
            {
                return (0);
            }
            //Key pressed
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        return 1;
                    case sf::Keyboard::Up:
                        menu--;
                        if (menu < 0)
                            menu = 0;
                        break;
                    case sf::Keyboard::Down:
                        menu++;
                        if (menu > 1)
                            menu = 1;
                        break;
                    case sf::Keyboard::Return:
                        if (menu == 0) {
                            //Let's get play !
                            return 1;
                        } else {
                            return 0;
                        }
                    default:
                        break;
                }
            }
        }


        if (menu == 0)
        {
            continueLabel.setColor(sf::Color(255, 0, 0, 255));
            exitLabel.setColor(sf::Color(255, 255, 255, 255));
        }
        else if (menu == 1)
        {
            continueLabel.setColor(sf::Color(255, 255, 255, 255));
            exitLabel.setColor(sf::Color(255, 0, 0, 255));
        }


        window.clear();


        window.draw(background);
        window.draw(continueLabel);
        window.draw(exitLabel);

        window.display();

    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
