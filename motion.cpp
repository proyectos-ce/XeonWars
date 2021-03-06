#include "motion.h"
#define PI 3.14159265


Motion::Motion()
{
    x=0;
}

float Motion::getX() const
{
    return x;
}

void Motion::setX(float value)
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




LinearMotion::LinearMotion(float angle)
{
    this->angle=(angle*PI/180.0);
}

sf::Vector2f LinearMotion::getNext(float speed)
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

sf::Vector2f SinMotion::getNext(float speed)
{
    sf::Vector2f newPos;
    double sin1 =sin((x+1)/15.0), sin2 = sin(x/15.0);
    newPos.x = (sin1- sin2)*scale;
    newPos.y = 2*direction;
    x+=1;
    return newPos;
}

SimpleMotion::SimpleMotion()
{
}

sf::Vector2f SimpleMotion::getNext(float speed)
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

sf::Vector2f FollowerMotion::getNext(float speed)
{
    sf::Vector2f next(0,speed*direction);
    //std::cout<< target->getGlobalBounds().width <<std::endl;
    if(owner->getGlobalBounds().height/2+owner->getPosition().y < target->getGlobalBounds().height/2+target->getPosition().y != reverseDirection()
            && speed <  fabs(  (owner->getPosition().x+owner->getGlobalBounds().width/2) - (target->getPosition().x+target->getGlobalBounds().width/2)) ){
        if(owner->getGlobalBounds().width/2+owner->getPosition().x < target->getGlobalBounds().width/2+target->getPosition().x){
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

Motion *createLinearMotion(float angle)
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

Motion *createBossMotion(int scale, int yMovement)
{
    return new BossMotion(scale, yMovement);
}

}



BossMotion::BossMotion(int scale, int yMovement)
{
    this->scale=scale;
    this->yMovement=yMovement;
}

sf::Vector2f BossMotion::getNext(float speed)
{
    sf::Vector2f newPos(0,0);
    float sin1 =sin((x+1)/15.0), sin2 = sin(x/15.0);
    newPos.x = (sin1- sin2)*scale;
    if(x<yMovement){
    newPos.y = speed*direction;
    }
    x+=1;
    return newPos;
}


