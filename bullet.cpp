#include "bullet.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

Bullet::Bullet(sf::Texture texture, Motion *motion , int damage, int speed)
{
    setTexture(texture);
    setDamage(damage);
    setSpeed(speed);
    setMotion(motion);
}

int Bullet::getDamage() const
{
    return damage;
}

void Bullet::setDamage(int value)
{
    damage = value;
}

char Bullet::getType() const
{
    return 'B';
}
