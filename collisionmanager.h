#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "entity.h"
#include "MainSpaceShip.h"
#include "Collision.h"
#include "iostream"
#include "bullet.h"

class CollisionManager
{
public:
    CollisionManager();
    CollisionManager(MainSpaceShip *PlayerShip,std::vector<Entity *> *playerBulletList, std::vector<Entity *> *enemyList);
    void checkCollisions();

    std::vector<Entity *> *getEnemyList() const;
    void setEnemyList(std::vector<Entity *> *value);

    std::vector<Entity *> *getPlayerBulletList() const;
    void setPlayerBulletList(std::vector<Entity *> *value);

    MainSpaceShip *getPlayerShip() const;
    void setPlayerShip(MainSpaceShip *value);

private:
    std::vector<Entity *> *enemyList;
    std::vector<Entity *> *playerBulletList;
    MainSpaceShip *playerShip;

};

#endif // COLLISIONMANAGER_H
