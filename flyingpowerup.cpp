#include "flyingpowerup.h"

FlyingPowerUp::FlyingPowerUp(sf::Texture *texture, Motion *motion)
{
    setTexture(texture);
    setMotion(motion);

}

powerUp FlyingPowerUp::getPowerup() const
{
    return powerup;
}

void FlyingPowerUp::setPowerup(const powerUp &value)
{
    powerup = value;
}

void FlyingPowerUp::animate(float passedTime)
{
    time+=passedTime;
    if(this->time>500){
        updateTexture(++currentTexture);
        time=0;
    }
}

void FlyingPowerUp::update(sf::RenderWindow &window, float time)
{
    animate(time);
    Entity::update(window, time);
}

namespace PowerUpFactory {

FlyingPowerUp *createMisilePU(sf::Vector2f position, int speed)
{
    Motion *motion = MotionFactory::createSimpleMotion();
    FlyingPowerUp *newPU = new FlyingPowerUp(SpritesManager::getInstance()->getEnemyBulletTexture(),motion);
    newPU->setPowerup(powerUps::MISSILE);
    newPU->setPosition(position);
    newPU->setSpeed(speed);
    newPU->setTexture(SpritesManager::getInstance()->getMissilePowerUpTexture());
    newPU->setScale(0.2);
    newPU->setSpeed(speed);

    return newPU;
}

FlyingPowerUp *createLaserPU(sf::Vector2f position, int speed)
{
    Motion *motion = MotionFactory::createSimpleMotion();
    FlyingPowerUp *newPU = new FlyingPowerUp(SpritesManager::getInstance()->getEnemyBulletTexture(),motion);
    newPU->setPowerup(powerUps::LASER);
    newPU->setPosition(position);
    newPU->setTexture(SpritesManager::getInstance()->getLaserPowerUpTexture());
    newPU->setScale(0.2);
    newPU->setSpeed(speed);

    return newPU;
}

FlyingPowerUp *createShieldPU(sf::Vector2f position, int speed)
{
    Motion *motion = MotionFactory::createSimpleMotion();
    FlyingPowerUp *newPU = new FlyingPowerUp(SpritesManager::getInstance()->getEnemyBulletTexture(),motion);
    newPU->setPowerup(powerUps::SHIELD);
    newPU->setPosition(position);
    newPU->setTexture(SpritesManager::getInstance()->getShieldPowerUpTexture());
    newPU->setScale(0.2);
    newPU->setSpeed(speed);
    return newPU;
}



}





/*
namespace PowerUpFactory {

FlyingPowerUp *PowerUpFactory::createMisilePU()
{
    Motion *motion = MotionFactory::createSinMotion(0);
    FlyingPowerUp *newPU = new FlyingPowerUp(SpritesManager::getEnemyBulletTexture(),motion);
    newPU->setPowerup();
    return newPU;
}

FlyingPowerUp *PowerUpFactory::createLaserPU()
{
    Motion *motion = MotionFactory::createSinMotion(0);
    FlyingPowerUp *newPU = new FlyingPowerUp(SpritesManager::getBossTexture(),motion);
    newPU->setPowerup(Laser);
    return newPU;
}
FlyingPowerUp *PowerUpFactory::createShieldPU()
{
    Motion *motion = MotionFactory::createSinMotion(0);
    FlyingPowerUp *newPU = new FlyingPowerUp(SpritesManager::getEnemyBulletTexture(),motion);
    newPU->setPowerup(SHI);
    return newPU;
}
}*/
