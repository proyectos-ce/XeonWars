#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "motion.h"
#include "cannon.h"
#include "iostream"
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
    int getLife() const;
    void setLife(int value);
    int getEnemy_score();
    void setEnemy_score(int score);

protected:
    int life = 20;
    int moves=1;
    int trigger=0;
    void shoot();
    std::vector<Bullet *> *bulletList;
    int getMoves() const;
    void setMoves(int value);
    Cannon *cannon;
    int enemy_score;
};

namespace EnemyFactory {

    Enemy *createJet(int level);
    Enemy *createBomber(int level);
    Enemy *createTower(int level);
    Enemy *createMissileTower(int level);
    Enemy *createKamikazeJet(int level);
    //Enemy *createMeteor(int level);
}

#endif // ENEMY_H
