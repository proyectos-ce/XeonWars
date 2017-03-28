#include "cannon.h"

Cannon::Cannon()
{

}

Cannon::Cannon(Enemy *owner, std::__cxx11::string bulletTextureFilename)
{
    setOwner(owner);
    setBulletTextureFilename(bulletTextureFilename);

}

void Cannon::shout()
{
    for (int i = -1; i < 2; ++i) {
         Motion *bulletMotion = motionGenerator.createLinearMotion(15*i);
        shoutBullet(3, bulletMotion);
    }

}

void Cannon::shoutBullet(int speed, Motion *bulletMotion)
{
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile(bulletTextureFilename);
    Enemy *newBullet = new Enemy(bulletTexture, owner->getEnemyList());
    newBullet->setTexturesAmount(1);
    newBullet->setPosition(owner->getCenterPosition());
    newBullet->setMotion(bulletMotion);
    newBullet->setSpeed(speed);
}

std::string Cannon::getBulletTextureFilename() const
{
    return bulletTextureFilename;
}

void Cannon::setBulletTextureFilename(const std::string &value)
{
    bulletTextureFilename = value;
}

Enemy *Cannon::getOwner() const
{
    return owner;
}

void Cannon::setOwner(Enemy *value)
{
    owner = value;
}
