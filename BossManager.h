//
// Created by danielc on 15/04/17.
//

#ifndef XEONWARS_BOSSMANAGER_H
#define XEONWARS_BOSSMANAGER_H

#include "enemy.h"
#include <SFML/Graphics/Sprite.hpp>

class BossManager
{
public:
    BossManager();
    int Bosslife;
    void BossInit(int level);
    int BossLevel;
    bool isdead();
    int initialBosslife;
    void lifeRender(sf::RenderWindow &window);
    sf::Texture BossTexture;
private:
    sf::Text text;
    sf::Text text2;
    sf::Font font;
    sf::Texture texture;
    sf::Sprite sprite;


};


#endif //XEONWARS_BOSSMANAGER_H
