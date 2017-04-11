#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "motion.h"
#include "cannon.h"

class Enemy : public Entity
{
public:
    Enemy();
    Enemy(sf::Texture texture);
    Enemy(sf::Texture texture, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *bulletList);
    ~Enemy();
    std::vector<Bullet *> *getBulletList() const;
    void setBulletList(std::vector<Bullet *> *value);
    bool attack(int damage);
    void update(sf::RenderWindow &window, float time);
    int getTrigger() const;
    void setTrigger(int value);

    Cannon *getCannon() const;
    void setCannon(Cannon *value);
    char getType() const;
    int getLife() const;
    void setLife(int value);

protected:
    int life = 20;
    int moves=1;
    int trigger=0;
    void shoot();
    std::vector<Bullet *> *bulletList;
    int getMoves() const;
    void setMoves(int value);
    Cannon *cannon;
};

#endif // ENEMY_H
