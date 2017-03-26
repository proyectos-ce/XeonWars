#include "enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(sf::Texture texture)
{
    setEnemyList(NULL);
    setTexture(texture);
    updateTexture(0);

}

Enemy::Enemy(sf::Texture texture, std::vector<Entity *> *enemyList)
{
    setTexture(texture);
    setEnemyList(enemyList);
    enemyList->push_back(this);
}

Enemy::~Enemy()
{
    delete(motion);
}

std::vector<Entity *> *Enemy::getEnemyList() const
{
    return enemyList;
}

void Enemy::setEnemyList(std::vector<Entity *> *value)
{
    enemyList = value;
}

