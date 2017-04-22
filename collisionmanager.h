#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "entity.h"
#include "MainSpaceShip.h"
#include "iostream"
#include "bullet.h"
#include "enemy.h"
#include "flyingpowerup.h"
#include "explosion.h"
#include"Collision.h"
class CollisionManager
{
public:
    CollisionManager();
    CollisionManager(MainSpaceShip *playerShip, std::vector<Bullet *> *playerBulletList, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *enemyBulletList);
    bool checkCollisions();


    MainSpaceShip *getPlayerShip() const;
    void setPlayerShip(MainSpaceShip *value);

    std::vector<Enemy *> *getEnemyList() const;
    void setEnemyList(std::vector<Enemy *> *value);

    std::vector<Bullet *> *getPlayerBulletList() const;
    void setPlayerBulletList(std::vector<Bullet *> *value);

    std::vector<Bullet *> *getEnemyBulletList() const;
    void setEnemyBulletList(std::vector<Bullet *> *value);

    int getLastScore();
    void addLastScore(int score);

    void setLastScore(int value);

    std::vector<FlyingPowerUp *> *getPowerUpList() const;
    void setPowerUpList(std::vector<FlyingPowerUp *> *value);

    std::vector<Explosion *> *getExplosionList() const;
    void setExplosionList(std::vector<Explosion *> *value);

    Queue<powerUp> *getPlayerPowerUpsQueue() const;
    void setPlayerPowerUpsQueue(Queue<powerUp> *value);

private:
    int lastScore=0;
    std::vector<Enemy *> *enemyList;
    std::vector<Bullet *> *playerBulletList;
    std::vector<Bullet *> *enemyBulletList;
    std::vector<FlyingPowerUp *> *powerUpList;
    Queue<powerUp> *playerPowerUpsQueue;
    std::vector<Explosion *> *explosionList;
    MainSpaceShip *playerShip;
    SoundBuffer collisionSpaceEnemySoundBuffer;
    SoundBuffer collisionBulletEnemySoundBuffer;
    Sound collisionSound;
    void deleteEnemy(std::vector<Enemy *> *list, int index);
    void deleteBullet(std::vector<Bullet *> *list, int index);
    void deletePowerUp(std::vector<FlyingPowerUp *> *list, int index);
};

#endif // COLLISIONMANAGER_H
