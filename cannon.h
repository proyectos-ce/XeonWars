#ifndef CANNON_H
#define CANNON_H
#include "entity.h"
#include "bullet.h"
#include "motion.h"
#include <SFML/Graphics.hpp>

#include "iostream"

class Cannon
{
public:
    Cannon();
    ~Cannon();
    virtual void shoot();
    std::string getBulletTextureFilename() const;
    void setBulletTextureFilename(const std::string &value);
    std::vector<Bullet *> *getBulletList() const;
    void setBulletList(std::vector<Bullet *> *value);
    int getBulletDamage() const;
    void setBulletDamage(int value);

    int getBulletSpeed() const;
    void setBulletSpeed(int value);

    sf::Sprite *getOwnerSprite() const;
    void setOwnerSprite(sf::Sprite *value);

    bool getReverseDirection() const;
    void setReverseDirection(bool value);

protected:
    int bulletDamage;
    int bulletSpeed;
    virtual void shootBullet(int speed, Motion *bulletMotion, float angle=0);
    std::string bulletTextureFilename;
    sf::Sprite *ownerSprite;
    std::vector<Bullet *> *bulletList;
    sf::Vector2f getCenterPosition();
    bool reverseDirection=false;
    int getDirection();

};

class SimpleCannon : public Cannon
{
public:
    SimpleCannon();
    void shoot();
};

class SprayCannon : public Cannon
{
public:
    SprayCannon(int angle, int bulletsByshoot);
    void shoot();
    int getAngle() const;
    void setAngle(int value);
    int getBulletsByshoot() const;
    void setBulletsByshoot(int value);

private:
    int angle;
    int bulletsByshoot;
};

class FollowerCannon : public Cannon
{
public:
    FollowerCannon(sf::Sprite *owner,sf::Sprite *target);
    void shoot();
    sf::Sprite *getOwner() const;
    void setOwner(sf::Sprite *value);
    sf::Sprite *getTarget() const;
    void setTarget(sf::Sprite *value);

private:
    sf::Sprite *owner;
    sf::Sprite *target;
    void shootBullet(int speed);
};





namespace CannonFactory{
     Cannon *createSimpleCannon();
     Cannon *createSprayCannon(int angle, int bulletsByshoot);
     Cannon *createFollowerCannon(sf::Sprite *owner,sf::Sprite *target);

}

#endif // CANNON_H
