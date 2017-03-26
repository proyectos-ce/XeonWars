#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "entity.h"


class Enemy : public Entity
{
public:
    Enemy();
    Enemy(sf::Texture texture);
    Enemy(sf::Texture texture, std::vector<Entity *> *enemyList);
    ~Enemy();
    std::vector<Entity *> *getEnemyList() const;
    void setEnemyList(std::vector<Entity *> *value);

protected:
    int shoutDelay;
    Bullet* shout();
    std::vector<Entity *> *enemyList;

};

#endif // ENEMY_H
