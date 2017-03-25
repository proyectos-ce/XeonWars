#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>


class Bullet
{
public:
    Bullet();
    void update(sf::RenderWindow &window, float time);
    void render(sf::RenderWindow &window);
};

#endif // BULLET_H
