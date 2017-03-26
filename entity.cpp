#include "entity.h"
Entity::Entity()
{

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
    setLife(0);
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

int Entity::getLife() const
{
    return life;
}

void Entity::setLife(int value)
{
    life = value;
}

bool Entity::attack(int damage)
{
    bool result=false;
    if(damage>0){
        life-=damage;
        if(life<=0){
            kill();
            result=true;
        }
    }
    return result;
}

int Entity::getSpeed() const
{
    return speed;
}

void Entity::setSpeed(int value)
{
    speed = value;
}

void Entity::setPosition(int x, int y)
{
    sprite.setPosition(x,y);
}


