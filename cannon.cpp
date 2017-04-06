#include "cannon.h"
Cannon::Cannon()
{

}

Cannon::~Cannon()
{

}

void Cannon::shout()
{
 std::cout << "shout \n";
}


void Cannon::shoutBullet(int speed, Motion *bulletMotion)
{
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile(bulletTextureFilename);
    Bullet *newBullet = new Bullet(bulletTexture, bulletMotion, bulletDamage, speed);
    newBullet->setTexturesAmount(1);
    newBullet->setPosition(getCenterPosition());
    //enemyList->size();
    if(enemyList==NULL){
        std::cout<<"ERROR nullptr"<<std::endl;
    }
    //std::cout<<enemyList->size()<<std::endl;
    enemyList->push_back(newBullet);
}

sf::Vector2f Cannon::getCenterPosition()
{
    sf::FloatRect rect =   ownerSprite->getGlobalBounds();
    sf::Vector2f centerPosition;
    centerPosition.x = rect.left+rect.width/2;
    centerPosition.y = rect.top+rect.height/2;
    return centerPosition;
}

sf::Sprite *Cannon::getOwnerSprite() const
{
    return ownerSprite;
}

void Cannon::setOwnerSprite(sf::Sprite *value)
{
    ownerSprite = value;
}

std::vector<Entity *> *Cannon::getEnemyList() const
{
    return enemyList;
}

void Cannon::setEnemyList(std::vector<Entity *> *value)
{
    enemyList = value;
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

void SimpleCannon::shout()
{
    Motion *bulletMotion = motionFactory.createSimpleMotion();
    shoutBullet(bulletSpeed, bulletMotion);

}

SprayCannon::SprayCannon(int angle, int bulletsByShout)
{
    setBulletTextureFilename("Resources/laserRed.png");
    setAngle(angle);
    setBulletsByShout(bulletsByShout);
}

void SprayCannon::shout()
{
    for (int i = -(bulletsByShout/2); i < (bulletsByShout/2+bulletsByShout%2) ; ++i) {
    Motion *bulletMotion = motionFactory.createLinearMotion(angle*i);
       shoutBullet(bulletSpeed, bulletMotion);
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

int SprayCannon::getBulletsByShout() const
{
    return bulletsByShout;
}

void SprayCannon::setBulletsByShout(int value)
{
    bulletsByShout = value;
}

Cannon *CannonFactory::createSimpleCannon()
{
    Cannon *newCannon =  new SimpleCannon();
    return newCannon;
}

Cannon *CannonFactory::createSprayCannon(int angle, int bulletsByShout)
{
    Cannon *newCannon =  new SprayCannon(angle, bulletsByShout);
    return newCannon;
}
