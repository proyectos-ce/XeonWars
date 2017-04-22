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
    bool getIsLaser() const;
    void setIsLaser(bool value);

private:
    int damage;
    float time=0;
    bool isLaser=false;
};

#endif // BULLET_H
