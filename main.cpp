#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include "Screens.h"
#include "ConnectionManager.h"
#include <time.h>
#include "enemyReader.h"


using namespace sf;


int main(){

    enemyReader e;
    e.readEnemyFile();


    std::vector<Screen*> screens;
    int screen = 0;

    //ConnectionManager* myConnectionManager = new ConnectionManager();
    RenderWindow window(VideoMode(1366,768), "XeonWars", sf::Style::Close | sf::Style::Titlebar);
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
    Game game;
    screens.push_back(&game);
    GameOverScreen gameOverScreen;
    screens.push_back(&gameOverScreen);


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

