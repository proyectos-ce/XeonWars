#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "entity.h"
#include "MainSpaceShip.h"
#include "iostream"
#include "bullet.h"
#include "enemy.h"
#include"Collision.h"
class CollisionManager
{
public:
    CollisionManager();
    CollisionManager(MainSpaceShip *playerShip, std::vector<Bullet *> *playerBulletList, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *enemyBulletList);
    void checkCollisions();


    MainSpaceShip *getPlayerShip() const;
    void setPlayerShip(MainSpaceShip *value);

    std::vector<Enemy *> *getEnemyList() const;
    void setEnemyList(std::vector<Enemy *> *value);

    std::vector<Bullet *> *getPlayerBulletList() const;
    void setPlayerBulletList(std::vector<Bullet *> *value);

    std::vector<Bullet *> *getEnemyBulletList() const;
    void setEnemyBulletList(std::vector<Bullet *> *value);

private:
    std::vector<Enemy *> *enemyList;
    std::vector<Bullet *> *playerBulletList;
    std::vector<Bullet *> *enemyBulletList;
    MainSpaceShip *playerShip;
    void deleteEnemy(std::vector<Enemy *> *enemyList, int index);
    void deleteBullet(std::vector<Bullet *> *bulletList, int index);
};

#endif // COLLISIONMANAGER_H
