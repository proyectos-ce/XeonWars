//
// Created by joseph on 4/21/17.
//

#ifndef XEONWARS_CREDITS_H
#define XEONWARS_CREDITS_H

#include "Screen.h"
#include <fstream>

class CreditsScreen : public Screen {
public:
    CreditsScreen();
    int run(sf::RenderWindow &window, sf::Texture &pauseScreen, Options* gameOptions);
private:
    bool running = true;
    int menu = 0;

    sf::View creditsView;
    sf::Font classicFont;
    sf::Text titleCredit;
    sf::Text creditText;
    sf::Text creditText2;

    std::string creditsStr;
    std::string line;
    std::ifstream creditsFile;

    sf::Event event;
};


#endif //XEONWARS_CREDITS_H
