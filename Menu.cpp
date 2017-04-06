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

int Menu::run(sf::RenderWindow &App, sf::Texture &tex)
{
    sf::Event Event;
    bool Running = true;
    sf::Texture Texture;
    sf::Sprite Sprite;
    int alpha = 0;
    sf::Font Font;
    sf::Text Menu1;
    sf::Text Menu2;
    sf::Text Menu3;
    int menu = 0;

    if (!Texture.loadFromFile("Resources/menu/presentation.jpg"))
    {
        std::cerr << "Error loading presentation.gif" << std::endl;
        return (-1);
    }
    Sprite.setTexture(Texture);
    Sprite.setColor(sf::Color(255, 255, 255, alpha));
    if (!Font.loadFromFile("Resources/menu/verdana.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return (-1);
    }
    Menu1.setFont(Font);
    Menu1.setCharacterSize(20);
    Menu1.setString("Play");
    Menu1.setPosition({ 280.f, 160.f });

    Menu2.setFont(Font);
    Menu2.setCharacterSize(20);
    Menu2.setString("Exit");
    Menu2.setPosition({ 280.f, 220.f });

    Menu3.setFont(Font);
    Menu3.setCharacterSize(20);
    Menu3.setString("Continue");
    Menu3.setPosition({ 280.f, 160.f });



    if (playing)
    {
        alpha = alpha_max;
    }

    while (Running)
    {
        //Verifying events
        while (App.pollEvent(Event))
        {

            if (Event.type == sf::Event::Resized)
                App.setView(Utils::calcView(sf::Vector2u(Event.size.width, Event.size.height), Utils::designedsize));
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                    case sf::Keyboard::Up:
                        menu = 0;
                        break;
                    case sf::Keyboard::Down:
                        menu = 1;
                        break;
                    case sf::Keyboard::Return:
                        if (menu == 0)
                        {
                            //Let's get play !
                            playing = true;
                            return (1);
                        }
                        else
                        {
                            //Let's get work...
                            return (-1);
                        }
                        break;
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
        Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
        if (menu == 0)
        {
            Menu1.setColor(sf::Color(255, 0, 0, 255));
            Menu2.setColor(sf::Color(255, 255, 255, 255));
            Menu3.setColor(sf::Color(255, 0, 0, 255));
        }
        else
        {
            Menu1.setColor(sf::Color(255, 255, 255, 255));
            Menu2.setColor(sf::Color(255, 0, 0, 255));
            Menu3.setColor(sf::Color(255, 255, 255, 255));
        }

        //Clearing screen
        App.clear();
        //Drawing
        App.draw(Sprite);
        if (alpha >= alpha_max)
            alpha = alpha_max;
        {
            if (playing)
            {
                Sprite.setTexture(tex);
                App.draw(Menu3);
            }
            else
            {
                App.draw(Menu1);
            }
            App.draw(Menu2);
        }
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}