#include "motion.h"
#define PI 3.14159265


Motion::Motion()
{
    x=0;
}

int Motion::getX() const
{
    return x;
}

void Motion::setX(int value)
{
    x = value;
}




Motion *MotionFactory::createSimpleMotion()
{
    Motion *newSimple =  new SimpleMotion();
    return newSimple;
}

Motion *MotionFactory::createLinearMotion(double angle)
{
    Motion *newLinear =  new LinearMotion(angle);
    return newLinear;

}

Motion *MotionFactory::createSinMotion(int scale)
{
    Motion *newSin =  new SinMotion(scale);
    return newSin;
}


LinearMotion::LinearMotion(double angle)
{
    this->angle=(angle*PI/180.0);
}

sf::Vector2f LinearMotion::getNext(int speed)
{
    sf::Vector2f newPos;
    newPos.x= speed*sin(angle);
    newPos.y= speed*cos(angle);
    x+=speed;
    return newPos;
}


SinMotion::SinMotion(int scale)
{
    this->scale=scale;
    x=0.01;
}

sf::Vector2f SinMotion::getNext(int speed)
{
    sf::Vector2f newPos;
    double sin1 =sin((x+1)/15.0), sin2 = sin(x/15.0);
    newPos.x = (sin1- sin2)*scale;
    newPos.y = speed;
    x+=1;
    return newPos;

}

SimpleMotion::SimpleMotion()
{
}

sf::Vector2f SimpleMotion::getNext(int speed)
{
    x+=speed;
    sf::Vector2f newPos;
    newPos.x= 0;
    newPos.y= speed;
    return newPos;
}

