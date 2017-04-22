//
// Created by joseph on 4/17/17.
//

#ifndef XEONWARS_PAUSESCREEN_H
#define XEONWARS_PAUSESCREEN_H


#include "Screen.h"

class PauseScreen : public Screen {
public:
    PauseScreen();
    int run(sf::RenderWindow &window, sf::Texture &pauseScreen, Options* gameOptions);
private:
    bool running = true;
    int menu = 0;
    sf::Text continueLabel;
    sf::Text exitLabel;
    sf::Sprite background;
    sf::Font classicFont;

};


#endif //XEONWARS_PAUSESCREEN_H
