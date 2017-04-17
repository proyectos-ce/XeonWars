#include "cannon.h"
Cannon::Cannon()
{

}

Cannon::~Cannon()
{

}

void Cannon::shoot()
{
    std::cout << "shoot \n";
}


void Cannon::shootBullet(int speed, Motion *bulletMotion, float angle)
{
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile(bulletTextureFilename);
    bulletMotion->setReverseDirection(reverseDirection);
    Bullet *newBullet = new Bullet(bulletTexture, bulletMotion, bulletDamage, speed);
    newBullet->setTexturesAmount(texturesAmount);
    newBullet->setPosition(getCenterPosition());
    //BulletList->size();
    newBullet->rotate(angle*getDirection()+(180*reverseDirection));
    if(bulletList==NULL){
        std::cout<<"ERROR nullptr"<<std::endl;
    }
    else{
        bulletList->push_back(newBullet);
    }
    //std::cout<<bulletList->size()<<std::endl;
}

int Cannon::getTexturesAmount() const
{
    return texturesAmount;
}

void Cannon::setTexturesAmount(int value)
{
    texturesAmount = value;
}

sf::Vector2f Cannon::getCenterPosition()
{
    sf::FloatRect rect =   ownerSprite->getGlobalBounds();
    sf::Vector2f centerPosition;
    centerPosition.x = rect.left+rect.width/2;
    centerPosition.y = rect.top+rect.height/2;
    return centerPosition;
}

int Cannon::getDirection()
{
    int direction= 1;
    if(reverseDirection){
        direction=-1;
    }
    return direction;
}

bool Cannon::getReverseDirection() const
{
    return reverseDirection;
}

void Cannon::setReverseDirection(bool value)
{
    reverseDirection = value;
}

sf::Sprite *Cannon::getOwnerSprite() const
{
    return ownerSprite;
}

void Cannon::setOwnerSprite(sf::Sprite *value)
{
    ownerSprite = value;
}

std::vector<Bullet *> *Cannon::getBulletList() const
{
    return bulletList;
}

void Cannon::setBulletList(std::vector<Bullet *> *value)
{
    bulletList = value;
}

int Cannon::getBulletDamage() const
{
    return bulletDamage;
}

void Cannon::setBulletDamage(int value)
{
    bulletDamage = value;
}

int Cannon::getBulletSpeed() const
{
    return bulletSpeed;
}

void Cannon::setBulletSpeed(int value)
{
    bulletSpeed = value;
}

std::string Cannon::getBulletTextureFilename() const
{
    return bulletTextureFilename;
}

void Cannon::setBulletTextureFilename(const std::string &value)
{
    bulletTextureFilename = value;
}

SimpleCannon::SimpleCannon()
{
    //setBulletTextureFilename("Resources/Bullets.png");
}

void SimpleCannon::shoot()
{
    Motion *bulletMotion = MotionFactory::createSimpleMotion();
    shootBullet(bulletSpeed, bulletMotion);

}

SprayCannon::SprayCannon(int angle, int bulletsByshoot)
{
    //setBulletTextureFilename(bulletTextureFilename);
    setAngle(angle);
    setBulletsByshoot(bulletsByshoot);
}

void SprayCannon::shoot()
{
    for (int i = -(bulletsByshoot/2); i < (bulletsByshoot/2+bulletsByshoot%2) ; ++i) {
        Motion *bulletMotion = MotionFactory::createLinearMotion(angle*i);
        shootBullet(bulletSpeed, bulletMotion,-angle*i);
    }

}

int SprayCannon::getAngle() const
{
    return angle;
}

void SprayCannon::setAngle(int value)
{
    angle = value;
}

int SprayCannon::getBulletsByshoot() const
{
    return bulletsByshoot;
}

void SprayCannon::setBulletsByshoot(int value)
{
    bulletsByshoot = value;
}

namespace CannonFactory
{
Cannon *createSimpleCannon()
{
    Cannon *newCannon =  new SimpleCannon();
    return newCannon;
}

Cannon *createSprayCannon(int angle, int bulletsByshoot)
{
    Cannon *newCannon =  new SprayCannon(angle, bulletsByshoot);
    return newCannon;
}

Cannon *createFollowerCannon(sf::Sprite *owner, sf::Sprite *target)
{
    return new FollowerCannon(owner, target);
}

}

FollowerCannon::FollowerCannon(sf::Sprite *owner, sf::Sprite *target)
{
    //setBulletTextureFilename("Resources/Explosion.png");
    setOwner(owner);
    setTarget(target);
}

void FollowerCannon::shoot()
{
        shootBullet(bulletSpeed);
}

sf::Sprite *FollowerCannon::getOwner() const
{
    return owner;
}

void FollowerCannon::setOwner(sf::Sprite *value)
{
    owner = value;
}

sf::Sprite *FollowerCannon::getTarget() const
{
    return target;
}

void FollowerCannon::setTarget(sf::Sprite *value)
{
    target = value;
}

void FollowerCannon::shootBullet(int speed)
{
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile(bulletTextureFilename);
    Bullet *newBullet = new Bullet(bulletTexture, NULL, bulletDamage, speed);
    //newBullet->updateTexture(1);
    Motion *bulletMotion = MotionFactory::createFollowerMotion(newBullet->getSpriteReference(),target);
    bulletMotion->setReverseDirection(reverseDirection);
    newBullet->setMotion(bulletMotion);

    newBullet->setTexturesAmount(texturesAmount);
    newBullet->setPosition(getCenterPosition());
    if(bulletList==NULL){
        std::cout<<"ERROR nullptr"<<std::endl;
    }
    else{
        bulletList->push_back(newBullet);
    }
}
