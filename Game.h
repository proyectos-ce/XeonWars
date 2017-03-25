//
// Created by jimena on 3/25/17.
//

#ifndef XEONWARS_GAME_H
#define XEONWARS_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include "Background.h"
#include "MainSpaceShip.h"
#include "List.h"

class Game{

    Clock clock;
    MainSpaceShip ownSpaceShip;
    Background background;
    Music backgroundMusic;

public:
    Game();
    void run(RenderWindow &window);

};


#endif //XEONWARS_GAME_H
