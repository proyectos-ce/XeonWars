//
// Created by joseph on 3/25/17.
//

#ifndef XEONWARS_SCREEN_H
#define XEONWARS_SCREEN_H

#include <SFML/Graphics.hpp>
#include "options.h"

class Screen
{
public :
    virtual int run (sf::RenderWindow &App, sf::Texture &Texture, Options* gameOptions) = 0;
};
#endif //XEONWARS_SCREEN_H
