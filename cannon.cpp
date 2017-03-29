#include "cannon.h"
Cannon::Cannon()
{

}

Cannon::~Cannon()
{

}

Cannon::Cannon(Entity *owner, std::__cxx11::string bulletTextureFilename)
{
    setOwner(owner);
    setBulletTextureFilename(bulletTextureFilename);

}

void Cannon::shout()
{

    for (int i = -1; i < 2; ++i) {
    Motion *bulletMotion = motionFactory.createLinearMotion(5*i);
    //Motion *bulletMotion = MotionFactory.createLinearMotion(15);
        shoutBullet(8, bulletMotion);
    }

}

void Cannon::shoutBullet(int speed, Motion *bulletMotion)
{
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile(bulletTextureFilename);
    Bullet *newBullet = new Bullet(bulletTexture, bulletMotion, 5, speed);
    newBullet->setTexturesAmount(1);
    newBullet->setPosition(owner->getCenterPosition());
    enemyList->push_back(newBullet);
}

std::vector<Entity *> *Cannon::getEnemyList() const
{
    return enemyList;
}

void Cannon::setEnemyList(std::vector<Entity *> *value)
{
    enemyList = value;
}

std::string Cannon::getBulletTextureFilename() const
{
    return bulletTextureFilename;
}

void Cannon::setBulletTextureFilename(const std::string &value)
{
    bulletTextureFilename = value;
}

Entity *Cannon::getOwner() const
{
    return owner;
}

void Cannon::setOwner(Entity *value)
{
    owner = value;
}
