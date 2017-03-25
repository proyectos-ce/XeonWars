#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "entity.h"

class Enemy : public Entity
{
public:
    Enemy();
    ~Enemy();
    void attack(int damage);

protected:
    int life;
    int shoutDelay;
    Bullet* shout();

};

#endif // ENEMY_H
