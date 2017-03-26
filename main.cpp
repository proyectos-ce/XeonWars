#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Screens.h"


using namespace sf;


int main(){

    std::vector<Screen*> screens;
    int screen = 0;

    

    sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
    RenderWindow window(VideoMode(resX,resY), "XeonWars", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    window.requestFocus();

    int newH = (width*resY)/resX;
    int displace = (newH - height)/(-2);

    v1 = sf::View(sf::FloatRect(0,displace,width,newH));
    v1.setCenter(width/2,height/2);

    window.setView(v1);

    height = resY;
    width = resX;

    //Screens preparations
    Menu menu;
    screens.push_back(&menu);
    Game game;
    screens.push_back(&game);

    Texture pauseTexture;


    //Main loop
    while (screen >= 0)
    {
        if (screen == 0)
            game.pauseGame();
        screen = screens[screen]->run(window, pauseTexture);
    }

    return EXIT_SUCCESS;

}