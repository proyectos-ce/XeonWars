//
// Created by danielc on 15/04/17.
//

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BossManager.h"
using namespace std;
BossManager::BossManager(){
    if (!font.loadFromFile("Resources/menu/8bit.ttf"))
    {
        cout << "error with the font" << endl;
    }
    text.setPosition(1050,0);
    text.setFont(font);
    text.setCharacterSize(50); // in pixels, not points!
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold );
    text2.setPosition(1050,50);
    text2.setFont(font);
    text2.setCharacterSize(50); // in pixels, not points!
    text2.setColor(sf::Color::White);
    text2.setStyle(sf::Text::Bold );

    texture.loadFromFile("Resources/index.jpeg");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(0.125,0.125);
    sprite.setPosition(950,23);
};
void BossManager::BossInit(int level) {
    BossLevel=level;
    Bosslife=level*100;
    initialBosslife=Bosslife;

}
bool BossManager::isdead() {
    bool result = false;
    if (Bosslife <= 0){
        result = true;
    }
    return result;
}
void BossManager::lifeRender(sf::RenderWindow &window){
    text.setString("Boss Lvl. "+to_string(BossLevel));
    text2.setString("Life: "+to_string(Bosslife)+"/"+to_string(initialBosslife));
    window.draw(text);
    window.draw(text2);
    window.draw(sprite);
}