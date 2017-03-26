#ifndef MOTION_H
#define MOTION_H

#include <SFML/Graphics.hpp>
#include "math.h"

class Motion
{
public:
    Motion();
    virtual sf::Vector2u getNext(int speed)=0;
    int getX() const;
    void setX(int value);

protected:
    int x;
};
#endif // MOTION_H
