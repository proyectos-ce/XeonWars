#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include"motion.h"
#include "iostream"
class Entity
{
public:
    Entity();

    virtual void update(sf::RenderWindow &window, float time);
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
    int getSpeed() const;
    void setSpeed(int value);
    void setPosition(sf::Vector2f postion);
    sf::Vector2f getPosition();
    sf::Vector2f getCenterPosition();

protected:
    int speed=10;
    int texturesAmount=2;
    Motion *motion;
    sf::Sprite sprite;
    sf::Texture texture;
    void updateTexture(int value);



};

#endif // ENTITY_H
