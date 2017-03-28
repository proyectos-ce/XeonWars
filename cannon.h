#ifndef CANNON_H
#define CANNON_H
#include "enemy.h"
#include "motion.h"
#include "motiongenerator.h"
#include <SFML/Graphics.hpp>




class Cannon
{
public:
    Cannon();
    Cannon(Enemy *owner, std::string bulletTextureFilename);
    void shout();
    MotionGenerator motionGenerator;
    Enemy *getOwner() const;
    void setOwner(Enemy *value);
    std::string getBulletTextureFilename() const;
    void setBulletTextureFilename(const std::string &value);


private:
    void shoutBullet(int speed, Motion *bulletMotion);
    std::string bulletTextureFilename;
    Enemy *owner;


};

#endif // CANNON_H
