#include "bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

Bullet::Bullet(sf::Texture *texture, Motion *motion , int damage, int speed)
{
    setTexture(texture);
    setDamage(damage);
    setSpeed(speed);
    setMotion(motion);
    //sprite.setColor(sf::Color(200,255,255,200));;
}

int Bullet::getDamage() const
{
    return damage;
}

void Bullet::setDamage(int value)
{
    damage = value;
}

void Bullet::animate(float passedTime)
{
    time+=passedTime;
    if(this->time>500){
        updateTexture(++currentTexture);
        time=0;
    }

}

void Bullet::update(sf::RenderWindow &window, float time)
{
    Entity::update(window, time);
    animate(time);
}


