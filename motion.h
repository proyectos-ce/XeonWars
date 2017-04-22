#ifndef MOTION_H
#define MOTION_H

#include <SFML/Graphics.hpp>
#include "math.h"
#include "iostream"
class Motion
{
public:
    Motion();
    virtual sf::Vector2f getNext(float speed)=0;
    float getX() const;
    void setX(float value);

    void setReverseDirection(bool value);



protected:
    float x= 0;
    int direction=1;
    bool reverseDirection() const;
};


class SimpleMotion : public Motion{

public:
    SimpleMotion();
    sf::Vector2f getNext(float speed);
};

class LinearMotion : public Motion{

public:
    LinearMotion(float angle);
    sf::Vector2f getNext(float speed);
protected:
    float angle;
};

class SinMotion : public Motion{
public:
    SinMotion(int scale);
    sf::Vector2f getNext(float speed);
protected:
    int scale;
};

class FollowerMotion : public Motion{
public:
    FollowerMotion(sf::Sprite *owner,sf::Sprite *target);
    sf::Vector2f getNext(float speed);
    sf::Sprite *getTarget() const;
    void setTarget(sf::Sprite *value);

    sf::Sprite *getOwner() const;
    void setOwner(sf::Sprite *value);

protected:
    sf::Sprite *owner;
    sf::Sprite *target;
};

class BossMotion : public Motion{
public:
    BossMotion(int scale, int yMovement);
    sf::Vector2f getNext(float speed);

protected:
    int scale;
    int yMovement;

};

namespace MotionFactory{

Motion *createSimpleMotion();
Motion *createLinearMotion(float angle);
Motion *createSinMotion(int scale);
Motion *createFollowerMotion(sf::Sprite *owner,sf::Sprite *target);
Motion *createBossMotion(int scale, int yMovement);
}



#endif // MOTION_H
