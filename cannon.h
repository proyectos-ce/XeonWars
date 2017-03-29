#ifndef CANNON_H
#define CANNON_H
#include "entity.h"
#include "bullet.h"
#include "motion.h"
#include <SFML/Graphics.hpp>

class Cannon
{
public:
    Cannon();
    ~Cannon();
    Cannon(Entity *owner, std::string bulletTextureFilename);
    void shout();
    MotionFactory motionFactory;
    Entity *getOwner() const;
    void setOwner(Entity *value);
    std::string getBulletTextureFilename() const;
    void setBulletTextureFilename(const std::string &value);

    std::vector<Entity *> *getEnemyList() const;
    void setEnemyList(std::vector<Entity *> *value);

private:
    void shoutBullet(int speed, Motion *bulletMotion);
    std::string bulletTextureFilename;
    Entity *owner;
    std::vector<Entity *> *enemyList;

};
class CannonFactory{

};

#endif // CANNON_H
