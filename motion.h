#ifndef MOTION_H
#define MOTION_H

#include <SFML/Graphics.hpp>
#include "math.h"

class Motion
{
public:
    Motion();
    virtual sf::Vector2f getNext(int speed)=0;
    int getX() const;
    void setX(int value);

protected:
    int x= 0;
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


class MotionFactory
{
public:
    static Motion *createSimpleMotion();
    static Motion *createLinearMotion(double angle);
    static Motion *createSinMotion(int scale);



};



#endif // MOTION_H
