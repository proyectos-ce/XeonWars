#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include"motion.h"
#include "iostream"
//#include <stddef.h>  // defines NULL
class Entity
{
public:
    Entity();
    ~Entity();

    virtual void update(sf::RenderWindow &window, float time);
    virtual void animate(float time);
    void render(sf::RenderWindow &window);
    void kill();

    Motion *getMotion() const;
    void setMotion(Motion *value);

    sf::Sprite getSprite() const;
    void setSprite(const sf::Sprite &value);
    int getTexturesAmount() const;
    void setTexturesAmount(int value);
    float getSpeed() const;
    void setSpeed(float value);
    void setPosition(sf::Vector2f position);
    void setCenterPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    sf::Vector2f getCenterPosition();
    void setScale(float scale);
    void updateTexture(int value);
    void rotate(float angle);
    sf::Sprite *getSpriteReference();

    sf::Texture *getTexture() const;
    void setTexture(sf::Texture *value);


protected:
    //bool *lifeFlag = NULL;
    float speed=10;
    int texturesAmount=2;
    Motion *motion;
    sf::Sprite sprite;
    sf::Texture *texture;
    int currentTexture=0;


};


class SpritesManager
{

public:
    static SpritesManager *getInstance();//{


    sf::Texture *getJetTexture();
    sf::Texture *getBomberTexture();
    sf::Texture *getTowerTexture();
    sf::Texture *getMissileTowerTexture();
    sf::Texture *getKamikazeTexture();
    sf::Texture *getBossTexture();

    sf::Texture *getPlayerBulletTexture();
    sf::Texture *getFollowerBulletTexture();
    sf::Texture *getMissileTexture();
    sf::Texture *getEnemyBulletTexture();

    sf::Texture *getExplosionTexture();

    sf::Texture *getMissilePowerUpTexture();
    sf::Texture *getLaserPowerUpTexture();
    sf::Texture *getShieldPowerUpTexture();

private:
SpritesManager();
    static SpritesManager *instance;
    sf::Texture jetTexture;
    sf::Texture bomberTexture;
    sf::Texture towerTexture;
    sf::Texture missileTowerTexture;
    sf::Texture kamikazeTexture;
    sf::Texture bossTexture;

    sf::Texture playerBulletTexture;
    sf::Texture followerBulletTexture;
    sf::Texture missileTexture;
    sf::Texture enemyBulletTexture;
    sf::Texture explosionTexture;
    sf::Texture missilePowerUpTexture;
    sf::Texture laserPowerUpTexture;
    sf::Texture shieldPowerUpTexture;

/*
    SpritesManager() {

    }
    //EnemySpritesManager(EnemySpritesManager const&);              // Don't Implement
    //void operator=(EnemySpritesManager const&); // Don't implement
*/
};

#endif // ENTITY_H
