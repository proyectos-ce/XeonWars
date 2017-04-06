#ifndef BULLET_H
#define BULLET_H
#include "entity.h"
#include "motion.h"

class Bullet : public Entity
{
public:
    Bullet();
    ~Bullet();
    Bullet(sf::Texture texture, Motion *motion, int damage, int speed);
    int getDamage() const;
    void setDamage(int value);
    char getType() const;


private:
    int damage;

};

#endif // BULLET_H
