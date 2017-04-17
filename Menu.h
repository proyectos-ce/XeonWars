//
// Created by joseph on 3/25/17.
//

#ifndef XEONWARS_MENU_H
#define XEONWARS_MENU_H


#include "Screen.h"

class Menu : public Screen {
private:
    int alpha_max;
    int alpha_div;
    bool playing;
public:
    Menu();
    int run(sf::RenderWindow &window, sf::Texture &pauseTexture);
};



#endif //XEONWARS_MENU_H
