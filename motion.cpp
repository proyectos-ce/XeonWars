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



void Motion::setReverseDirection(bool value)
{
    if(value){
        direction=-1;
    }
    else{
        direction=1;
    }
}

bool Motion::reverseDirection() const
{
    bool reverseDirection = false;
    if(direction==-1){
        reverseDirection=true;
    }
    return reverseDirection;
}




LinearMotion::LinearMotion(double angle)
{
    this->angle=(angle*PI/180.0);
}

sf::Vector2f LinearMotion::getNext(int speed)
{
    sf::Vector2f newPos;
    newPos.x= speed*sin(angle);
    newPos.y= speed*cos(angle)*direction;
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
    newPos.y = speed*direction;
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
    newPos.y= speed*direction;
    return newPos;
}


FollowerMotion::FollowerMotion(sf::Sprite *owner,sf::Sprite *target)
{
    setOwner(owner);
    setTarget(target);
}

sf::Vector2f FollowerMotion::getNext(int speed)
{
    sf::Vector2f next(0,speed*direction);
    if(owner->getLocalBounds().height/2+owner->getPosition().y < target->getLocalBounds().height/2+target->getPosition().y != reverseDirection()
            && 5 <  fabs(  (owner->getPosition().x+owner->getLocalBounds().width/2) - (target->getPosition().x+target->getLocalBounds().width/2)) ){
        if(owner->getLocalBounds().width/2+owner->getPosition().x < target->getLocalBounds().width/2+target->getPosition().x){
            next.x=speed;
        }
        else {
            next.x=-speed;
        }
    }

    return next;
}

sf::Sprite *FollowerMotion::getTarget() const
{
    return target;
}

void FollowerMotion::setTarget(sf::Sprite *value)
{
    target = value;
}

sf::Sprite *FollowerMotion::getOwner() const
{
    return owner;
}

void FollowerMotion::setOwner(sf::Sprite *value)
{
    owner = value;
}




namespace MotionFactory {


Motion *createSimpleMotion()
{
    return new SimpleMotion();
}

Motion *createLinearMotion(double angle)
{
    return new LinearMotion(angle);

}

Motion *createSinMotion(int scale)
{
    return new SinMotion(scale);
}

Motion *createFollowerMotion(sf::Sprite *owner, sf::Sprite *target)
{
    return new FollowerMotion(owner, target);
}
}
