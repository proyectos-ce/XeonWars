#ifndef MOTIONGENERATOR_H
#define MOTIONGENERATOR_H

#include "motion.h"
#include <SFML/Graphics.hpp>
#include "iostream"
//#include "math.h"
class MotionGenerator
{
public:
    static Motion *createSimpleMotion();
    static Motion *createLinearMotion(double angle);
    static Motion *createSinMotion(int scale);

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

};

#endif // MOTIONGENERATOR_H
