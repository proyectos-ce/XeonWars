#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include "Screens.h"
#include "Utils.h"



using namespace sf;


int main(){

    std::vector<Screen*> screens;
    int screen = 0;


    RenderWindow window(VideoMode(1366,768), "XeonWars", sf::Style::Fullscreen);
    window.setView(Utils::calcView(window.getSize(), Utils::designedsize));
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    window.requestFocus();

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

