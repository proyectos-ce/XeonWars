//
// Created by joseph on 3/25/17.
//

#include <iostream>
#include "Menu.h"
#include "Utils.h"

Menu::Menu()
{
    alpha_max = 3 * 255;
    alpha_div = 3;
    playing = false;
}

int Menu::run(sf::RenderWindow &window, sf::Texture &pauseTexture, Options* gameOptions)
{
    sf::Event event;
    bool running = true;
    sf::Texture bgTexture;
    sf::Sprite bg;
    int alpha = 0;
    sf::Font verdana;
    sf::Font classicFont;
    sf::Text logo;
    sf::Text playLabel;
    sf::Text exitLabel;
    sf::Text optionsLabel;
    sf::Text creditsLabel;
    sf::Text continueLabel;
    sf::Text copyLabel;
    int menu = 0;

    if (!bgTexture.loadFromFile("Resources/menu/presentation.jpg"))
    {
        std::cerr << "Error loading presentation.jpg" << std::endl;
        return (-1);
    }

    if (!classicFont.loadFromFile("Resources/menu/8bit.ttf"))
    {
        std::cerr << "Error loading 8bit.ttf" << std::endl;
        return (-1);
    }



    bg.setTexture(bgTexture);
    bg.setColor(sf::Color(255, 255, 255, alpha));


    playLabel.setFont(classicFont);
    playLabel.setCharacterSize(40);
    playLabel.setString("Play");
    playLabel.setPosition({ 300.f, 350.f });


    optionsLabel.setFont(classicFont);
    optionsLabel.setCharacterSize(40);
    optionsLabel.setString("Options");
    optionsLabel.setPosition({ 300.f, 400.f });

    creditsLabel.setFont(classicFont);
    creditsLabel.setCharacterSize(40);
    creditsLabel.setString("Credits");
    creditsLabel.setPosition({ 300.f, 450.f });


    exitLabel.setFont(classicFont);
    exitLabel.setCharacterSize(40);
    exitLabel.setString("Exit");
    exitLabel.setPosition({ 300.f, 500.f });

    logo.setFont(classicFont);
    logo.setCharacterSize(200);
    logo.setString("XeonWars");
    sf::FloatRect textRect = logo.getLocalBounds();
    logo.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    logo.setPosition({ window.getSize().x/2.f, 200.f });


    copyLabel.setFont(classicFont);
    copyLabel.setCharacterSize(40);
    copyLabel.setString("(C) 2017 Ximenathl and co");
    textRect = copyLabel.getLocalBounds();
    copyLabel.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    copyLabel.setPosition({ 1366/2.0f, 700.f });



    while (running)
    {
        //Verifying events
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Resized)
                window.setView(Utils::calcView(sf::Vector2u(event.size.width, event.size.height), Utils::designedsize));
            // Window closed
            if (event.type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        return -1;
                    case sf::Keyboard::Up:
                        menu--;
                        if (menu<0)
                            menu = 0;
                        break;
                    case sf::Keyboard::Down:
                        menu++;
                        if (menu>3)
                            menu = 3;
                        break;
                    case sf::Keyboard::Return:
                        if (menu == 0) {
                            return (1);
                        } else if (menu == 1) {
                            return (4);
                        } else if (menu == 2) {
                                return(5);
                        } else  {
                            return (-1);
                        }
                    default:
                        break;
                }
            }
        }
        //When getting at alpha_max, we stop modifying the sprite
        if (alpha<alpha_max)
        {
            alpha+=3;
        }
        bg.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
        if (menu == 0)
        {
            playLabel.setColor(sf::Color(255, 0, 0, 255));
            optionsLabel.setColor(sf::Color(255, 255, 255, 255));
            creditsLabel.setColor(sf::Color(255, 255, 255, 255));
            exitLabel.setColor(sf::Color(255, 255, 255, 255));
        }
        else if (menu == 1)
        {
            playLabel.setColor(sf::Color(255, 255, 255, 255));
            optionsLabel.setColor(sf::Color(255, 0, 0, 255));
            creditsLabel.setColor(sf::Color(255, 255, 255, 255));
            exitLabel.setColor(sf::Color(255, 255, 255, 255));
        }
        else if (menu == 2)
        {
            playLabel.setColor(sf::Color(255, 255, 255, 255));
            optionsLabel.setColor(sf::Color(255, 255, 255, 255));
            creditsLabel.setColor(sf::Color(255, 0, 0, 255));
            exitLabel.setColor(sf::Color(255, 255, 255, 255));
        }
        else
        {
            playLabel.setColor(sf::Color(255, 255, 255, 255));
            optionsLabel.setColor(sf::Color(255, 255, 255, 255));
            creditsLabel.setColor(sf::Color(255, 255, 255, 255));
            exitLabel.setColor(sf::Color(255, 0, 0, 255));
        }

        //Clearing screen
        window.clear();
        //Drawing
        window.draw(bg);
        if (alpha >= alpha_max)
            alpha = alpha_max;
        {
            window.draw(playLabel);
            window.draw(copyLabel);
            window.draw(logo);
            window.draw(optionsLabel);
            window.draw(creditsLabel);
            window.draw(exitLabel);
        }
        window.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}