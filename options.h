//
// Created by joseph on 4/21/17.
//

#ifndef XEONWARS_OPTIONS_H
#define XEONWARS_OPTIONS_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>




class Options {
public:
    Options();

    std::string name;
    sf::Clock gameClock;

    bool showStats = false;

};


#endif //XEONWARS_OPTIONS_H
