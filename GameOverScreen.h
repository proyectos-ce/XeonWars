//
// Created by joseph on 4/17/17.
//

#ifndef XEONWARS_GAMEOVERSCREEN_H
#define XEONWARS_GAMEOVERSCREEN_H


#include "Screen.h"

class GameOverScreen : public Screen {
private:
    sf::Font classicFont;
    sf::Text testText;
    sf::Text continueLabel;
    bool running = true;
    sf::Event event;

    bool isWhite = false;
    int frameCounter = 0;

    sf::Color bg = sf::Color(102,0,0);
public:
    GameOverScreen();

    int run(sf::RenderWindow &window, sf::Texture &Texture);

    bool elapsedFrames(int frames);
};




#endif //XEONWARS_GAMEOVERSCREEN_H
