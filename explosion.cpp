#include "explosion.h"

Explosion::Explosion(sf::Vector2f position)
{
    setPosition(position);
}

void Explosion::animate(float passedTime)
{
    time+=passedTime;
    if(this->time>50){
        updateCont++;
        updateTexture(updateCont);
        time=0;
    }
}

void Explosion::update(sf::RenderWindow &window, float time)
{
    animate(time);
    Entity::update(window, time);
}

int Explosion::getUpdateCont() const
{
    return updateCont;
}

void Explosion::setUpdateCont(int value)
{
    updateCont = value;
}

bool Explosion::finished()
{
    return texturesAmount<updateCont+2;
}


namespace ExplosionFactory {

Explosion *createSimpleExplosion(sf::Vector2f position, int speed)
{
   Explosion *newExp = new Explosion(position);
   newExp->setTexture(SpritesManager::getInstance()->getExplosionTexture());
   newExp->setTexturesAmount(19);
   newExp->setSpeed(speed);
   newExp->setMotion(MotionFactory::createSimpleMotion());
   return newExp;
}

}
