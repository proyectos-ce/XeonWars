#ifndef MOTION_H
#define MOTION_H

#include <SFML/Graphics.hpp>
#include "math.h"
#include "iostream"
class Motion
{
public:
    Motion();
    virtual sf::Vector2f getNext(int speed)=0;
    int getX() const;
    void setX(int value);

    void setReverseDirection(bool value);



protected:
    int x= 0;
    int direction=1;
    bool reverseDirection() const;
};


class SimpleMotion : public Motion{

   public:
    SimpleMotion();
    sf::Vector2f getNext(int speed);
};

class LinearMotion : public Motion{

   public:
    LinearMotion(double angle);
    sf::Vector2f getNext(int speed);
   protected:
    double angle;
};

class SinMotion : public Motion{
   public:
    SinMotion(int scale);
    sf::Vector2f getNext(int speed);
protected:
    int scale;
};

class FollowerMotion : public Motion{
   public:
    FollowerMotion(sf::Sprite *owner,sf::Sprite *target);
    sf::Vector2f getNext(int speed);
    sf::Sprite *getTarget() const;
    void setTarget(sf::Sprite *value);

    sf::Sprite *getOwner() const;
    void setOwner(sf::Sprite *value);

protected:
    sf::Sprite *owner;
    sf::Sprite *target;
};

namespace MotionFactory{

     Motion *createSimpleMotion();
     Motion *createLinearMotion(double angle);
     Motion *createSinMotion(int scale);
     Motion *createFollowerMotion(sf::Sprite *owner,sf::Sprite *target);
}



#endif // MOTION_H
