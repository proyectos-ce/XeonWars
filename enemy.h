#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "entity.h"

class Enemy : public Entity
{
public:
    Enemy();
    Enemy(sf::Texture* texture);
    Enemy(sf::Texture* texture, std::vector<Entity>* enemyList);
    ~Enemy();
    void attack(int damage);

protected:
    int life;
    int shoutDelay;
    Bullet* shout();

};

#endif // ENEMY_H
