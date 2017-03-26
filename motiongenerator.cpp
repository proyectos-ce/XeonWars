#include "motiongenerator.h"

Motion *MotionGenerator::createLinearMotion(int angle)
{
    Motion *newLinear =  new MotionGenerator::LinearMotion(angle);
    return newLinear;

}

Motion *MotionGenerator::createSinMotion(int scale)
{
    Motion *newSin =  new MotionGenerator::SinMotion(scale);
    return newSin;
}


MotionGenerator::LinearMotion::LinearMotion(int angle)
{
    this->angle=angle;
}

sf::Vector2u MotionGenerator::MotionGenerator::LinearMotion::getNext(int speed)
{
    sf::Vector2u newPos;
    newPos.x= speed*cos(angle);
    newPos.y= speed*sin(angle);
    return newPos;
}






MotionGenerator::SinMotion::SinMotion(int scale)
{
    scale=9;
}

sf::Vector2u MotionGenerator::MotionGenerator::SinMotion::getNext(int speed)
{
    sf::Vector2u newPos;
    newPos.x= sin(x+speed)-sin(x);
    newPos.y= speed;
    return newPos;

}
