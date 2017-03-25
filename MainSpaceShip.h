//
// Created by jimena on 3/24/17.
//

#ifndef AIRWAR_MAINSPACESHIP_H
#define AIRWAR_MAINSPACESHIP_H

#include <SFML/Graphics.hpp>
using namespace sf;

class MainSpaceShip{
public:
    MainSpaceShip();
    void update(RenderWindow &window, float time);
    void render(RenderWindow &window);
    bool gameOver();


private:
    Sprite SOwnSpaceShip;
    Texture TOwnSpaceShip;
    int lifes;
    int globalScore;
    int scoreForLifes;

    const float speed = 3;
    const float maxSpeed = speed*8;
    sf::Vector2f velocity;

};

#endif //AIRWAR_MAINSPACESHIP_H
