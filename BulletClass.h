//
// Created by danielc on 25/03/17.
//
#include <SFML/Graphics.hpp>
#ifndef XEONWARS_BULLETCLASS_H
#define XEONWARS_BULLETCLASS_H
#include <SFML/Audio.hpp>
#include <time.h>
#include <list>
#include <iostream>

class Bullet {

public:
    Bullet(sf::Vector2f size);
    void fire (int speed);
    void draw (sf::RenderWindow &window);
    void setPos(sf::Vector2f newPos);
private:
    sf::Sprite bullet;
    //sf::RectangleShape bullet;
};


#endif //XEONWARS_BULLETCLASS_H
