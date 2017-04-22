//
// Created by joseph on 4/21/17.
//

#ifndef XEONWARS_OPTIONSSCREEN_H
#define XEONWARS_OPTIONSSCREEN_H


#include "Screen.h"

class OptionsScreen : public Screen {
public:
    OptionsScreen();
    int run(sf::RenderWindow &window, sf::Texture &pauseScreen, Options* gameOptions);
private:
    bool running = true;
    int menu = 0;

    sf::Font classicFont;
    sf::Text statsLabel;
    sf::Text statsStatus;
    sf::Text nameLabel;
    sf::Text nameStatus;
    sf::Text backLabel;

    sf::Text difficultyLabel;
    sf::Text easyLabel;
    sf::Text mediumLabel;
    sf::Text hardLabel;

    sf::Event event;
};


#endif //XEONWARS_OPTIONSSCREEN_H