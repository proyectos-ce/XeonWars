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
#include "options.h"

using namespace sf;

class MainSpaceShip{
public:
    MainSpaceShip();
    void update(RenderWindow &window, float time);
    void render(RenderWindow &window);
    void usePowerUp();
    bool gameOver();
    void shield();
    void laser();
    void playerShoot();
    void checkShieldTimer();
    void checkLaserTimer();
    void lifeManager(int);
    bool attack(int damage);


    std::vector<Bullet *> *getbulletList() const;
    void setbulletList(std::vector<Bullet *> *value);


    //const Sprite &getSprite();
    int getLifeLevel() const;
    int getLifes() const;
    void setLifes(int numLifes);
    void setLifeLevel(int value);
    void addlife();
    sf::Sprite *getSpriteReference();
    Sprite getSprite() const;
    //void setSOwnSpaceShip(const Sprite &value);

    void doDamageAnimation();


    int getTexturesAmount() const;
    void setTexturesAmount(int value);

    Sprite getEffectSprite() const;
    void setEffectSprite(const Sprite &value);

    bool getMissiles_On() const;
    void setMissiles_On(bool value);

    bool getShieldActivated() const;
    void setShieldActivated(bool value);

    void setDirectionUp();
    void setDirectionDown();
    void setDirectionLeft();
    void setDirectionRight();

    void reset();

    void loseLife();
    Queue<powerUp> *getPowerUpsQueueReference();


private:
    bool missiles_On =false;
    bool laser_On= false;
    bool isWhite = false;
    bool shieldActivated = false;
    bool powerUpOn = false;

    Sprite SOwnSpaceShip;
    Sprite effectSprite;
    Texture TOwnSpaceShip;
    SoundBuffer normalShootBuffer;
    SoundBuffer missileShootBuffer;
    Sound shootSound;
    SoundBuffer shieldOnSound;
    SoundBuffer shieldOffSound;
    Sound sound;
    int missileShootCounter=0;
    int lifes;
    int lifeLevel=100;
    int blinkAnimationCounter = 0;
public:
    int getBlinkAnimationCounter() const;
    Queue<powerUp> powerUpsQueue;
    //Queue<powerUp> getPowerUpsQueue();

private:
    int frameCounter = 0;
    int globalScore;
    int scoreForLifes;

    Cannon *shipCannon;
    Texture shipCannonTexture;
    Cannon *missileCannon;
    Texture missileCannonTexture;
    Cannon *laserCannon;
    Clock shieldClock;
    Clock laserClock;
    std::vector<Bullet *> *bulletList;
    int texturesAmount=8;
    int defaultTexture=1;
    void updateTexture(int value);
    void updateEffect(int value);

    Options* gameOptions;

    bool exploding = false;

    int currentExplosionTexture = 0;
    int explosionAmount = 19;
    sf::Texture* explosionTexture;

    int rectX, rectY;
public:
    Options* getGameOptions() const;
    void setGameOptions(Options *gameOptions);

    bool getLaser_On() const;
    void setLaser_On(bool value);

private:
    const float speed = 6;
    const float maxSpeed = speed*10;
    sf::Vector2f velocity;


};

#endif //AIRWAR_MAINSPACESHIP_H
