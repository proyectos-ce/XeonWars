//
// Created by jimena on 3/24/17.
//

#ifndef AIRWAR_BACKGROUND_H
#define AIRWAR_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Background
{
public:
    Background(int bg, float speed);
    void update(RenderWindow &window, float elapsedTime);
    void render(RenderWindow &window);

private:
    Texture bg1Tex;
    Sprite  bg1Sprite;

    float bgSpeed;
    float bg1Y;
};

#endif //AIRWAR_BACKGROUND_H
