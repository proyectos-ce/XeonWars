//
// Created by joseph on 4/22/17.
//

#ifndef XEONWARS_RANKINGSCREEN_H
#define XEONWARS_RANKINGSCREEN_H

#include "Screen.h"
#include <fstream>
#include <SFML/Audio.hpp>

class RankingScreen : public Screen {
public:
    RankingScreen();
    int run(sf::RenderWindow &window, sf::Texture &pauseScreen, Options* gameOptions);
private:
    bool running = true;
    int menu = 0;

    sf::View creditsView;
    sf::Font classicFont;
    sf::Text titleCredit;
    sf::Text creditText;
    sf::Text creditText2;
    sf::Clock clock;
    sf::Time time;

    sf::Music backgroundMusic;

    std::string creditsStr;
    std::string line;
    std::ifstream creditsFile;

    sf::Event event;
};


#endif //XEONWARS_RANKINGSCREEN_H
