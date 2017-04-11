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

    std::vector<Bullet *> *getbulletList() const;
    void setbulletList(std::vector<Bullet *> *value);


    const Sprite &getSprite();
    bool attack(int damage);
    int getLifeLevel() const;
    void setLifeLevel(int value);

private:
    Sprite SOwnSpaceShip;
    Texture TOwnSpaceShip;
    int lifes;
    int lifeLevel=100;
    int globalScore;
    int scoreForLifes;
    bool shieldActivated;
    Queue<powerUp> powerUpsQueue;
    Cannon *shipCannon;
    CannonFactory cannonFactory;
    std::vector<Bullet *> *bulletList;


    const float speed = 6;
    const float maxSpeed = speed*10;
    sf::Vector2f velocity;

};

#endif //AIRWAR_MAINSPACESHIP_H
