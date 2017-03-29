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
    cannon.setBulletTextureFilename("Resources/laserRed.png");
    cannon.setOwner(this);
    cannon.setEnemyList(enemyList);
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

bool Enemy::attack(int damage)
{

    bool result=false;
    if(damage==-1){
        kill();
        result=true;
    }
    else if(damage>0){
        life-=damage;
        if(life<=0){
            kill();
            result=true;
        }
    }
    return result;

}

void Enemy::update(sf::RenderWindow &window, float time)
{

    Entity::update(window, time);
    if(trigger!=0 && moves%trigger==0){
        shout();
        updateTexture(1);
    }
    moves++;
}

int Enemy::getTrigger() const
{
    return trigger;
}

void Enemy::setTrigger(int value)
{
    trigger = value;
}

void Enemy::shout()
{
    cannon.shout();

}

int Enemy::getMoves() const
{
    return moves;
}

void Enemy::setMoves(int value)
{
    moves = value;
}



