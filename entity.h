#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include"motion.h"
#include "iostream"
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
    sf::Texture getTexture() const;
    void setTexture(sf::Texture value);
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

protected:
    //bool *lifeFlag = NULL;
    float speed=10;
    int texturesAmount=2;
    Motion *motion;
    sf::Sprite sprite;
    sf::Texture texture;
    int currentTexture=0;



};

#endif // ENTITY_H
