//
// Created by jimena on 3/24/17.
//
#include "Background.h"



Background::Background()
{
    bgSpeed = 0.2;

    bg1Tex.loadFromFile("Resources/background.jpg");
    //bg1Tex.loadFromFile("Resources/purple.png");
    bg1Tex.setSmooth(false);
    bg1Tex.setRepeated(true);
    bg1Sprite.setTexture(bg1Tex);
    bg1Sprite.setPosition(0, 0);
    bg1Y = 0;
    bg1Sprite.setTextureRect(IntRect(0,bg1Y,1366,768));
}


void Background::update(RenderWindow &window, float elapsedTime)
{

    if (bg1Y < 800)
    {
        bg1Y -= bgSpeed*elapsedTime;
    }else
    {
        bg1Y = 0;
    }

    bg1Sprite.setTextureRect(IntRect(0, bg1Y, 1366,768));
}
void Background::render(RenderWindow &window)
{
    window.draw(bg1Sprite);
}
