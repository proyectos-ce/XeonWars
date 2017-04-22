#ifndef BULLET_H
#define BULLET_H
#include "entity.h"
#include "motion.h"
#include "iostream"

class Bullet : public Entity
{
public:
    Bullet();
    ~Bullet();
    Bullet(sf::Texture *texture, Motion *motion, int damage, int speed);
    int getDamage() const;
    void setDamage(int value);
    void animate(float passedTime);
    void update(sf::RenderWindow &window, float time);


private:
    int damage;
    float time=0;
};

#endif // BULLET_H
