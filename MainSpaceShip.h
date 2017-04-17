//
// Created by jimena on 3/24/17.
//

#ifndef AIRWAR_MAINSPACESHIP_H
#define AIRWAR_MAINSPACESHIP_H
#include <SFML/Graphics.hpp>
#include "Queue.h"
#include "powerUp.h"
#include "math.h"
#include "cannon.h"
#include "motion.h"
#include "ScoreManager.h"

using namespace sf;

class MainSpaceShip{
public:
    MainSpaceShip();
    void update(RenderWindow &window, float time);
    void render(RenderWindow &window);
    void usePowerUp();
    bool gameOver();
    void shield();
    void playerShoot();
    void lifeManager(int);
    ScoreManager score;

    std::vector<Bullet *> *getbulletList() const;
    void setbulletList(std::vector<Bullet *> *value);


    //const Sprite &getSprite();
    bool attack(int damage);
    int getLifeLevel() const;
    void setLifeLevel(int value);
    sf::Sprite *getSpriteReference();
    Sprite getSprite() const;
    //void setSOwnSpaceShip(const Sprite &value);

private:
    bool missiles_On;
    bool laser_On;
    Sprite SOwnSpaceShip;
    Texture TOwnSpaceShip;
    SoundBuffer normalShootBuffer;
    SoundBuffer missileShootBuffer;
    SoundBuffer shieldOnSound;
    SoundBuffer shieldOffSound;
    

    Sound sound;

    int missileShootCounter;
    int lifes;
    int lifeLevel=100;
    int globalScore;
    int scoreForLifes;
    bool shieldActivated;
    Queue<powerUp> powerUpsQueue;
    Cannon *shipCannon;
    Cannon *missileCannon;
    Cannon *laserCannon;
    std::vector<Bullet *> *bulletList;



    const float speed = 6;
    const float maxSpeed = speed*10;
    sf::Vector2f velocity;

};

#endif //AIRWAR_MAINSPACESHIP_H
