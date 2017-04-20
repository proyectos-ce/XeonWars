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
#include "Utils.h"
#include "collisionmanager.h"

class Game : public Screen {



public:
    Game();
    int run(RenderWindow &window, Texture &tex);
    void pauseGame();
private:
    Clock clock;
    Clock shootClock;
    Clock scoreClock;
    MainSpaceShip ownSpaceShip;
    Background background;
    Music backgroundMusic;
    ScoreManager score;

    bool running = true;
    Time time;
    std::vector<Enemy *> enemyList;
    std::vector<Bullet *> enemyBulletList;
    std::vector<Bullet *> playerbulletList;
    BossManager Boss;
    void updateAll(RenderWindow &window);
    void eraseAll();

};


#endif //XEONWARS_GAME_H
