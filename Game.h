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
#include "enemyReader.h"


enum Direction {LEFT, RIGHT, UP, DOWN, CENTER};

class Game : public Screen {


public:
    Game();
    int run(RenderWindow &window, Texture &tex, Options* gameOptions);
    void pauseGame();
    void setPhoneDirection(string direction);

    void restartGame();

private:
    int minEnemyQuantity = 3;
    Clock clock;
    Clock shootClock;
    Clock scoreClock;
    Clock gameClock;

    MainSpaceShip ownSpaceShip;
    Background background = Background(1,0.1);
    Background backstars = Background(0,0.05);
    Background backasteroids = Background(2,0.04);
    Music backgroundMusic;
    Music bossMusic;
    ScoreManager score;
    Direction phoneDirection = CENTER;

    bool running = true;
    Time time;
    CollisionManager collisionManager;
    std::vector<Enemy *> enemyList;
    std::vector<Bullet *> enemyBulletList;
    std::vector<Bullet *> playerbulletList;
    BossManager Boss;
    void eraseAll();
    EnemyReader enemyReader;

    sf::Sprite shipIcon;
    sf::Texture shipIconTexture;
    sf::Text livesLeft;
    sf::Font classicFont;

    string statsTxt;
    size_t currentRss;
    sf::Text stats;


    void updateAll(RenderWindow &window, Options *gameOptions);
    void loadEnemies();

};


#endif //XEONWARS_GAME_H
