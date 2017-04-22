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
    statsLabel.setPosition({ 280.f, 150.f });


    statsStatus.setFont(classicFont);
    statsStatus.setCharacterSize(40);
    statsStatus.setPosition({ 500.f, 150.f });

    nameLabel.setFont(classicFont);
    nameLabel.setCharacterSize(40);
    nameLabel.setString("Set name");
    nameLabel.setPosition({ 280.f, 250.f });


    nameStatus.setFont(classicFont);
    nameStatus.setCharacterSize(40);
    nameStatus.setPosition({ 480.f, 250.f });

    difficultyLabel.setFont(classicFont);
    difficultyLabel.setCharacterSize(40);
    difficultyLabel.setString("Difficulty");
    difficultyLabel.setPosition({280.f, 350.f});

    easyLabel.setFont(classicFont);
    easyLabel.setCharacterSize(40);
    easyLabel.setString("Easy");
    easyLabel.setPosition({500.f, 350.f});

    mediumLabel.setFont(classicFont);
    mediumLabel.setCharacterSize(40);
    mediumLabel.setString("Medium");
    mediumLabel.setPosition({630.f, 350.f});

    hardLabel.setFont(classicFont);
    hardLabel.setCharacterSize(40);
    hardLabel.setString("Hard");
    hardLabel.setPosition({800.f, 350.f});


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
                    case sf::Keyboard::Escape:
                        return 0;
                    case sf::Keyboard::Up:
                        menu--;
                        if (menu < 0)
                            menu = 0;
                        break;
                    case sf::Keyboard::Down:
                        menu++;
                        if (menu > 3)
                            menu = 3;
                        break;
                    case sf::Keyboard::Right:
                        gameOptions->difficulty++;
                        if (gameOptions->difficulty > 3) {
                            gameOptions->difficulty = 3;
                        }
                        break;
                    case sf::Keyboard::Left:
                        gameOptions->difficulty--;
                        if (gameOptions->difficulty < 1) {
                            gameOptions->difficulty = 1;
                        }
                        break;
                    case sf::Keyboard::Return:
                        if (menu == 0) {
                            gameOptions->showStats = !gameOptions->showStats;
                        } else if (menu == 3) {
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
            difficultyLabel.setColor(sf::Color(255, 255, 255, 255));
            backLabel.setColor(sf::Color(255, 255, 255, 255));
        }
        else if (menu == 1)
        {
            statsLabel.setColor(sf::Color(255, 255, 255, 255));
            nameLabel.setColor(sf::Color(255, 0, 0, 255));
            difficultyLabel.setColor(sf::Color(255, 255, 255, 255));
            backLabel.setColor(sf::Color(255, 255, 255, 255));
        } else if (menu == 2) {
            statsLabel.setColor(sf::Color(255, 255, 255, 255));
            nameLabel.setColor(sf::Color(255, 255, 255, 255));
            difficultyLabel.setColor(sf::Color(255, 0, 0, 255));
            backLabel.setColor(sf::Color(255, 255, 255, 255));
        } else if (menu == 3) {
            statsLabel.setColor(sf::Color(255, 255, 255, 255));
            nameLabel.setColor(sf::Color(255, 255, 255, 255));
            difficultyLabel.setColor(sf::Color(255, 255, 255, 255));
            backLabel.setColor(sf::Color(255, 0, 0, 255));
        }


        if (gameOptions->difficulty == 1) {
            easyLabel.setColor(sf::Color(255, 0, 0, 255));
            mediumLabel.setColor(sf::Color(255, 255, 255, 255));
            hardLabel.setColor(sf::Color(255, 255, 255, 255));
        } else if (gameOptions->difficulty == 2) {
            easyLabel.setColor(sf::Color(255, 255, 255, 255));
            mediumLabel.setColor(sf::Color(255, 0, 0, 255));
            hardLabel.setColor(sf::Color(255, 255, 255, 255));
        } else {
            easyLabel.setColor(sf::Color(255, 255, 255, 255));
            mediumLabel.setColor(sf::Color(255, 255, 255, 255));
            hardLabel.setColor(sf::Color(255, 0, 0, 255));
        }

        if (gameOptions->showStats) {
            statsStatus.setString("On");
            statsStatus.setColor(sf::Color(255, 0, 0, 255));
        } else {
            statsStatus.setString("Off");
            statsStatus.setColor(sf::Color(255, 255, 255, 255));
        }

        nameStatus.setString(gameOptions->name);

        window.clear();

        window.draw(statsLabel);
        window.draw(backLabel);
        window.draw(statsStatus);
        window.draw(nameLabel);
        window.draw(nameStatus);

        window.draw(difficultyLabel);
        window.draw(easyLabel);
        window.draw(mediumLabel);
        window.draw(hardLabel);


        window.display();

    }
}