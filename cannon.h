#ifndef CANNON_H
#define CANNON_H
#include "entity.h"
#include "bullet.h"
#include "motion.h"
#include <SFML/Graphics.hpp>

#include "iostream"

class Cannon
{
public:
    Cannon();
    ~Cannon();
    virtual void shout();
    MotionFactory motionFactory;
    Entity *getOwner() const;
    void setOwner(Entity *value);
    std::string getBulletTextureFilename() const;
    void setBulletTextureFilename(const std::string &value);
    std::vector<Entity *> *getEnemyList() const;
    void setEnemyList(std::vector<Entity *> *value);
    int getBulletDamage() const;
    void setBulletDamage(int value);

    int getBulletSpeed() const;
    void setBulletSpeed(int value);

protected:
    int bulletDamage;
    int bulletSpeed;
    void shoutBullet(int speed, Motion *bulletMotion);
    std::string bulletTextureFilename;
    Entity *owner;
    std::vector<Entity *> *enemyList;

};

class SimpleCannon : public Cannon
{
public:
    SimpleCannon();
    void shout();
};

class SprayCannon : public Cannon
{
public:
    SprayCannon(int angle, int bulletsByShout);
    void shout();
    int getAngle() const;
    void setAngle(int value);
    int getBulletsByShout() const;
    void setBulletsByShout(int value);

private:
    int angle;
    int bulletsByShout;
};

class CannonFactory{
public:
    static Cannon *createSimpleCannon();
    static Cannon *createSprayCannon(int angle, int bulletsByShout);

};

#endif // CANNON_H
