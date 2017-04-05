//
// Created by joseph on 3/25/17.
//

#ifndef XEONWARS_UTILS_H
#define XEONWARS_UTILS_H


#include <SFML/Graphics/View.hpp>

class Utils {
public:
    static sf::View calcView(const sf::Vector2u &windowsize, const sf::Vector2u &designedsize);
    static const sf::Vector2u designedsize;
};


#endif //XEONWARS_UTILS_H
