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
#include "Screen.h"
#include "powerUp.h"
#include "entity.h"
#include "enemy.h"
#include "motion.h"
#include "cannon.h"

class Game : public Screen {

    Clock clock;
    MainSpaceShip ownSpaceShip;
    Background background;
    Music backgroundMusic;
    bool running = true;

public:
    Game();
    int run(RenderWindow &window, Texture &tex);

    void pauseGame();
};


#endif //XEONWARS_GAME_H
