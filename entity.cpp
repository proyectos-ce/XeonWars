#include "entity.h"
Entity::Entity()
{

}

Entity::~Entity()
{
    delete motion;

}



void Entity::update(sf::RenderWindow &window, float time)
{
    sf::Vector2f newMove = motion->getNext(speed);
    sprite.move(newMove.x, newMove.y);
}

void Entity::render(sf::RenderWindow &window)
{
    window.draw(sprite);

}

void Entity::kill()
{
    //setLife(0);
}

Motion *Entity::getMotion() const
{
    return motion;
}

void Entity::setMotion(Motion *value)
{
    motion = value;
}


sf::Texture Entity::getTexture() const
{
    return texture;
}

void Entity::setTexture(sf::Texture value)
{
    texture = value;
    sprite.setTexture(texture);
    updateTexture(0);
}

sf::Sprite Entity::getSprite() const
{
    return sprite;
}

void Entity::setSprite(const sf::Sprite &value)
{
    sprite = value;
}

int Entity::getTexturesAmount() const
{
    return texturesAmount;
}

void Entity::setTexturesAmount(int value)
{
    texturesAmount = value;
    updateTexture(0);
}

void Entity::updateTexture(int value)
{
    if(value<texturesAmount){
    int rectX = (texture.getSize().x/texturesAmount), rectY = texture.getSize().y;
    sprite.setTextureRect(sf::IntRect(rectX*value,0 , rectX, rectY ));
    }
}

void Entity::rotate(float angle)
{
    sprite.rotate(angle);
}

sf::Sprite *Entity::getSpriteReference()
{
    return &sprite;
}


int Entity::getSpeed() const
{
    return speed;
}

void Entity::setSpeed(int value)
{
    speed = value;
}

void Entity::setPosition(sf::Vector2f postion)
{
    sprite.setPosition(postion);
}

sf::Vector2f Entity::getPosition()
{
    return sprite.getPosition();
}

sf::Vector2f Entity::getCenterPosition()
{
    sf::Vector2f position = sprite.getPosition();
    position.x+=(texture.getSize().x/texturesAmount/2);
    position.y+=(texture.getSize().y/texturesAmount/2);
    return position;

}

void Entity::setScale(float scale)
{
    sprite.setScale(scale, scale);
}






