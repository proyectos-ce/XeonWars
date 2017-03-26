#ifndef MOTIONGENERATOR_H
#define MOTIONGENERATOR_H

#include "motion.h"
#include <SFML/Graphics.hpp>

class MotionGenerator
{
public:
    static Motion *createLinearMotion(int angle);
    static Motion *createSinMotion(int scale);

    class LinearMotion : public Motion{

       public:
        LinearMotion(int angle);
        sf::Vector2u getNext(int speed);
       protected:
        int angle;
    };

    class SinMotion : public Motion{
       public:
        SinMotion(int scale);
        sf::Vector2u getNext(int speed);
    protected:
        int scale;
    };

};

#endif // MOTIONGENERATOR_H
