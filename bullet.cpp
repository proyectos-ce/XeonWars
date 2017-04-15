#include "bullet.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{
    std::cout<<"eliminado bala\n";
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


