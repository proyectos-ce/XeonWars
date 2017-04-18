#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include "Screens.h"
#include <time.h>



using namespace sf;


int main(){

    std::vector<Screen*> screens;
    int screen = 0;


    RenderWindow window(VideoMode(1366,768), "XeonWars");
    window.setView(Utils::calcView(window.getSize(), Utils::designedsize));
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);


    sf::Image icon;
    //icon.loadFromFile("Resources/menu/icon.png");
    //window.setIcon(256,256,icon.getPixelsPtr());
    //window.requestFocus();


    //Screens preparations
    Menu menu;
    screens.push_back(&menu);
    Game* game = new Game();
    std::cout << &game << std::endl;
    screens.push_back(std::move(game));
    std::cout << &game << std::endl;
    GameOverScreen gameOverScreen;
    screens.push_back(&gameOverScreen);
    PauseScreen pauseScreen;
    screens.push_back(&pauseScreen);

    Texture pauseTexture;


    //Main loop
    while (screen >= 0)
    {
        if (screen == 3)
            game->pauseGame();
        if (screen == 0) {
            delete(screens.at(1));
            screens.at(1) = new Game();
        }
        screen = screens[screen]->run(window, pauseTexture);
    }

    delete(screens.at(1));

    return EXIT_SUCCESS;

}

