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
    newBullet->setTexturesAmount(1);
    newBullet->setPosition(getCenterPosition());
    //BulletList->size();
    newBullet->rotate(angle*getDirection());
    if(bulletList==NULL){
        std::cout<<"ERROR nullptr"<<std::endl;
    }
    else{
        bulletList->push_back(newBullet);
    }
    //std::cout<<bulletList->size()<<std::endl;
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
    setBulletTextureFilename("Resources/laserRed.png");
}

void SimpleCannon::shoot()
{
    Motion *bulletMotion = motionFactory.createSimpleMotion();
    shootBullet(bulletSpeed, bulletMotion);

}

SprayCannon::SprayCannon(int angle, int bulletsByshoot)
{
    setBulletTextureFilename("Resources/laserRed.png");
    setAngle(angle);
    setBulletsByshoot(bulletsByshoot);
}

void SprayCannon::shoot()
{
    for (int i = -(bulletsByshoot/2); i < (bulletsByshoot/2+bulletsByshoot%2) ; ++i) {
        Motion *bulletMotion = motionFactory.createLinearMotion(angle*i);
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

Cannon *CannonFactory::createSimpleCannon()
{
    Cannon *newCannon =  new SimpleCannon();
    return newCannon;
}

Cannon *CannonFactory::createSprayCannon(int angle, int bulletsByshoot)
{
    Cannon *newCannon =  new SprayCannon(angle, bulletsByshoot);
    return newCannon;
}
