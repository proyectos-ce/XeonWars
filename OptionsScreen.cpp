//
// Created by joseph on 4/21/17.
//

#include "OptionsScreen.h"

OptionsScreen::OptionsScreen() {
    if (!classicFont.loadFromFile("Resources/menu/8bit.ttf"))
    {
        std::cerr << "Error loading 8bit.ttf" << std::endl;
    }

    statsLabel.setFont(classicFont);
    statsLabel.setCharacterSize(40);
    statsLabel.setString("Show stats");
    statsLabel.setPosition({ 280.f, 250.f });


    statsStatus.setFont(classicFont);
    statsStatus.setCharacterSize(40);
    statsStatus.setPosition({ 480.f, 250.f });

    nameLabel.setFont(classicFont);
    nameLabel.setCharacterSize(40);
    nameLabel.setString("Set name");
    nameLabel.setPosition({ 280.f, 350.f });


    nameStatus.setFont(classicFont);
    nameStatus.setCharacterSize(40);
    nameStatus.setPosition({ 480.f, 350.f });


    backLabel.setFont(classicFont);
    backLabel.setCharacterSize(40);
    backLabel.setString("Back");
    backLabel.setPosition({ 280.f, 450.f });
}

int OptionsScreen::run(sf::RenderWindow &window, sf::Texture &pauseScreen, Options *gameOptions) {

    menu = 0;

    while (running) {

        while (window.pollEvent(event))
        {
            // Window closed
            if (event.type == sf::Event::Closed)
            {
                return (0);
            }
            if (event.type == sf::Event::TextEntered && menu == 1){
                if (event.text.unicode < 128) {
                    gameOptions->name.push_back((char)event.text.unicode);
                }
            }
            //Key pressed
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        menu--;
                        if (menu < 0)
                            menu = 0;
                        break;
                    case sf::Keyboard::Down:
                        menu++;
                        if (menu > 2)
                            menu = 2;
                        break;
                    case sf::Keyboard::Return:
                        if (menu == 0) {
                            gameOptions->showStats = !gameOptions->showStats;
                        } else {
                            return 0;
                        }
                    default:
                        break;
                }
            }

            if(event.key.code == sf::Keyboard::BackSpace && gameOptions->name.size()!=0 && menu == 1){
                gameOptions->name.pop_back();
            }
        }

        if (menu == 0)
        {
            statsLabel.setColor(sf::Color(255, 0, 0, 255));
            nameLabel.setColor(sf::Color(255, 255, 255, 255));
            backLabel.setColor(sf::Color(255, 255, 255, 255));
        }
        else if (menu == 1)
        {
            statsLabel.setColor(sf::Color(255, 255, 255, 255));
            nameLabel.setColor(sf::Color(255, 0, 0, 255));
            backLabel.setColor(sf::Color(255, 255, 255, 255));
        } else if (menu == 2) {
            statsLabel.setColor(sf::Color(255, 255, 255, 255));
            nameLabel.setColor(sf::Color(255, 255, 255, 255));
            backLabel.setColor(sf::Color(255, 0, 0, 255));
        }

        if (gameOptions->showStats) {
            statsStatus.setString("On");
        } else {
            statsStatus.setString("Off");
        }

        nameStatus.setString(gameOptions->name);

        window.clear();

        window.draw(statsLabel);
        window.draw(backLabel);
        window.draw(statsStatus);
        window.draw(nameLabel);
        window.draw(nameStatus);


        window.display();

    }
}
