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
    void checkShieldTimer();
    void lifeManager(int);


    std::vector<Bullet *> *getbulletList() const;
    void setbulletList(std::vector<Bullet *> *value);


    //const Sprite &getSprite();
    bool attack(int damage);
    int getLifeLevel() const;
    int getLifes() const;
    void setLifes(int numLifes);
    void setLifeLevel(int value);
    sf::Sprite *getSpriteReference();
    Sprite getSprite() const;
    //void setSOwnSpaceShip(const Sprite &value);

    void doDamageAnimation();


    int getTexturesAmount() const;
    void setTexturesAmount(int value);

    Sprite getEffectSprite() const;
    void setEffectSprite(const Sprite &value);

private:
    bool missiles_On;
    bool laser_On;
    bool isWhite = false;
    Sprite SOwnSpaceShip;
    Sprite effectSprite;
    Texture TOwnSpaceShip;
    SoundBuffer normalShootBuffer;
    SoundBuffer missileShootBuffer;
    Sound shootSound;
    SoundBuffer shieldOnSound;
    SoundBuffer shieldOffSound;

    Sound sound;

    int missileShootCounter;
    int lifes;
    int lifeLevel=100;
    int blinkAnimationCounter = 0;
    int frameCounter = 0;
    int globalScore;
    int scoreForLifes;
    bool shieldActivated;
    Queue<powerUp> powerUpsQueue;
    Cannon *shipCannon;
    Cannon *missileCannon;
    Cannon *laserCannon;
    Clock shieldClock;
    std::vector<Bullet *> *bulletList;

    int texturesAmount=7;
    int defaultTexture=1;
    void updateTexture(int value);
    void updateEffect(int value);


    const float speed = 6;
    const float maxSpeed = speed*10;
    sf::Vector2f velocity;

};

#endif //AIRWAR_MAINSPACESHIP_H
