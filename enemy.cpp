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

Enemy::Enemy(sf::Texture texture, std::vector<Enemy *> *enemyList)
{
    setTexture(texture);
    setEnemyList(enemyList);
    enemyList->push_back(this);

}

Enemy::~Enemy()
{
    delete(motion);
}

std::vector<Enemy *> *Enemy::getEnemyList() const
{
    return enemyList;
}

void Enemy::setEnemyList(std::vector<Enemy *> *value)
{
    enemyList = value;
}

bool Enemy::attack(int damage)
{
    Entity::attack(damage);
}

void Enemy::update(sf::RenderWindow &window, float time)
{

    Entity::update(window, time);
    if(trigger!=0 && moves%trigger==0){
        shout();
        std::cout<<moves<<"shout\n";
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
    std::cout<<(enemyList!=NULL)<<std::endl;
    if(enemyList!=NULL){
        sf::Texture bulletTexture;
        bulletTexture.loadFromFile("Resources/laserRed.png");
        Enemy *newBullet = new Enemy(bulletTexture, enemyList);
        newBullet->setTexturesAmount(1);
        MotionGenerator motionGenerator;
        newBullet->setPosition(getCenterPosition());
        Motion *enemyShipMotion = motionGenerator.createSimpleMotion();
        newBullet->setMotion(enemyShipMotion);
        newBullet->setSpeed(6);


}
}

int Enemy::getMoves() const
{
    return moves;
}

void Enemy::setMoves(int value)
{
    moves = value;
}



