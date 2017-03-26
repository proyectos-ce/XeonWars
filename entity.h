#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity();
    void update(sf::RenderWindow &window, float time);
    void render(sf::RenderWindow &window);
    void kill();
protected:
    int speed;
    sf::Sprite sprite;
    sf::Texture texture;

};

#endif // ENTITY_H
