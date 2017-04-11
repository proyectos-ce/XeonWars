#include "enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(sf::Texture texture)
{
    setBulletList(NULL);
    setTexture(texture);
    updateTexture(0);


}

Enemy::Enemy(sf::Texture texture, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *bulletList)
{
    setTexture(texture);
    setBulletList(bulletList);
    enemyList->push_back(this);
}
Enemy::~Enemy()
{
    delete cannon;
}

std::vector<Bullet *> *Enemy::getBulletList() const
{
    return bulletList;
}

void Enemy::setBulletList(std::vector<Bullet *> *value)
{
    bulletList = value;
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
        shoot();
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

void Enemy::shoot()
{
    cannon->shoot();

}

int Enemy::getMoves() const
{
    return moves;
}

void Enemy::setMoves(int value)
{
    moves = value;
}

Cannon *Enemy::getCannon() const
{
    return cannon;
}

void Enemy::setCannon(Cannon *value)
{
    cannon = value;
    cannon->setOwnerSprite(&(this->sprite));
    cannon->setBulletList(bulletList);
}

char Enemy::getType() const
{
    return 'E';
}

int Enemy::getLife() const
{
    return life;
}

void Enemy::setLife(int value)
{
    life = value;
}






