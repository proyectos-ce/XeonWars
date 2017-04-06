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


void Cannon::shootBullet(int speed, Motion *bulletMotion)
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

       shootBullet(bulletSpeed, bulletMotion);

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
