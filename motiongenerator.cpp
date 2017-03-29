#include "motiongenerator.h"
#define PI 3.14159265

Motion *MotionGenerator::createSimpleMotion()
{
    Motion *newSimple =  new MotionGenerator::SimpleMotion();
    return newSimple;
}

Motion *MotionGenerator::createLinearMotion(double angle)
{
    Motion *newLinear =  new MotionGenerator::LinearMotion(angle);
    return newLinear;

}

Motion *MotionGenerator::createSinMotion(int scale)
{
    Motion *newSin =  new MotionGenerator::SinMotion(scale);
    return newSin;
}


MotionGenerator::LinearMotion::LinearMotion(double angle)
{
    this->angle=(angle*PI/180.0);
}

sf::Vector2f MotionGenerator::MotionGenerator::LinearMotion::getNext(int speed)
{
    sf::Vector2f newPos;
    newPos.x= speed*sin(angle);
    newPos.y= speed*cos(angle);
    x+=speed;
    return newPos;
}






MotionGenerator::SinMotion::SinMotion(int scale)
{
    this->scale=scale;
    x=0.01;
}

sf::Vector2f MotionGenerator::MotionGenerator::SinMotion::getNext(int speed)
{
    sf::Vector2f newPos;
    double sin1 =sin((x+1)/15.0), sin2 = sin(x/15.0);
    newPos.x = (sin1- sin2)*scale;
    newPos.y = speed;
    x+=1;
    return newPos;


}

MotionGenerator::SimpleMotion::SimpleMotion()
{
}

sf::Vector2f MotionGenerator::SimpleMotion::getNext(int speed)
{
    x+=speed;
    sf::Vector2f newPos;
    newPos.x= 0;
    newPos.y= speed;
    return newPos;
}


/* zigzag
    if(x>10){
        newPos.x= (-20);
        if(x>20){
            x=0;
        }
    }
    else{
        newPos.x= (20);
    }
    std::cout<< "x"<< newPos.x<<std::endl;
    std::cout<< "sin1 "<< sin1<< "   sin2 "<< sin2 <<"sin1-sin2   "<< (sin1-sin2)*20.0<<std::endl;
    //std::cout<< "sen x"<<sin(x/10.0)<<std::endl;
    //newPos.x= speed;
    newPos.y= speed;
    x+=1;
    return newPos;
*/
