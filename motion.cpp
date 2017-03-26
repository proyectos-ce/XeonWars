#include "motion.h"

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
