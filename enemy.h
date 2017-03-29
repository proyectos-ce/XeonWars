#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "motion.h"
//#include "motiongenerator.h"
#include "cannon.h"

class Enemy : public Entity
{
public:
    Enemy();
    Enemy(sf::Texture texture);
    Enemy(sf::Texture texture, std::vector<Entity *> *enemyList);
    ~Enemy();
    std::vector<Entity *> *getEnemyList() const;
    void setEnemyList(std::vector<Entity *> *value);
    bool attack(int damage);
    void update(sf::RenderWindow &window, float time);
    int getTrigger() const;
    void setTrigger(int value);

protected:
    int life = 100;
    int moves=1;
    int trigger=0;
    void shout();
    std::vector<Entity *> *enemyList;
    int getMoves() const;
    void setMoves(int value);
    Cannon cannon;
};

#endif // ENEMY_H
