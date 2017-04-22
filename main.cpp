#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include "Screens.h"
#include "ConnectionManager.h"
#include <time.h>
#include "enemyReader.h"
#include "options.h"

using namespace sf;


int main(){
    //EnemyReader e;
    //e.getCurrentLevel();
    //e.getNextEnemySet();



    std::vector<Screen*> screens;
    int screen = 0;


    RenderWindow window(VideoMode(1366,768), "XeonWars", sf::Style::Close | sf::Style::Titlebar);
    window.setView(Utils::calcView(window.getSize(), Utils::designedsize));
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    sf::Image icon;
    //icon.loadFromFile("Resources/menu/icon.png");
    //window.setIcon(256,256,icon.getPixelsPtr());
    //window.requestFocus();


    Options* gameOptions = new Options();


    //Screens preparations
    Menu menu;
    screens.push_back(&menu);

    Game* gameMemory = (Game*) malloc(sizeof(Game));
    Game* game = new (gameMemory) Game();
  
    ConnectionManager* myConnectionManager = new ConnectionManager(game);


    screens.push_back(std::move(gameMemory));


    GameOverScreen gameOverScreen;
    screens.push_back(&gameOverScreen);
    PauseScreen pauseScreen;
    screens.push_back(&pauseScreen);
    OptionsScreen optionsScreen;
    screens.push_back(&optionsScreen);
    CreditsScreen creditsScreen;
    screens.push_back(&creditsScreen);

    Texture pauseTexture;


    //Main loop
    while (screen >= 0)
    {
        if (screen == 3)
            game->pauseGame();
        if (screen == 0) {
            Game* game = new (gameMemory) Game();
        }
        screen = screens[screen]->run(window, pauseTexture, gameOptions);
    }

    return EXIT_SUCCESS;

}

