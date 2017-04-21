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
    Enemy(sf::Texture *texture);
    Enemy(sf::Texture *texture, std::vector<Bullet *> *bulletList);
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
Enemy *createEnemy(int level, std::string textureFilename, Motion *enemyMotion,std::vector<Enemy *> *enemyList, Cannon *enemyCannon, std::vector<Bullet *> *bulletList);
Enemy *createJet(int level, std::vector<Bullet *> *bulletList);
Enemy *createBomber(int level, std::vector<Bullet *> *bulletList);
Enemy *createTower(int level, std::vector<Bullet *> *bulletList, int backgroundSpeed=2);
Enemy *createMissileTower(int level, std::vector<Bullet *> *bulletList, sf::Sprite *target, int backgroundSpeed=2);
Enemy *createKamikaze(int level, std::vector<Bullet *> *bulletList, sf::Sprite *target);
//Enemy *createMeteor(int level);
}



#endif // ENEMY_H
