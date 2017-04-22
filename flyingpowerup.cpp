#include "flyingpowerup.h"

FlyingPowerUp::FlyingPowerUp(sf::Texture *texture, Motion *motion)
{
    setTexture(texture);
    setMotion(motion);

}

powerUps FlyingPowerUp::getPowerup() const
{
    return powerup;
}

void FlyingPowerUp::setPowerup(const powerUps &value)
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

FlyingPowerUp *PowerUpFactory::createMisilePU()
{
    Motion *motion = MotionFactory::createSinMotion(0);
   FlyingPowerUp *newPU = new FlyingPowerUp(SpritesManager::getEnemyBulletTexture(),motion);
    newPU->setPowerup(Missile);
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
    newPU->setPowerup(Shield);
    return newPU;
}
}
