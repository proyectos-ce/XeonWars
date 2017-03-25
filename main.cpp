#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include "Background.h"
#include "MainSpaceShip.h"
#include "List.h"
#include "Game.h"
#include "powerUp.h"


#define RES nullptr

using namespace sf;


int main(){
   RenderWindow window(VideoMode(1200, 800), "XeonWars");
    window.setFramerateLimit(60);

    Game application;
    application.run(window);



    return 0;
}