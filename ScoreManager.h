//
// Created by danielc on 06/04/17.
//

#ifndef XEONWARS_SCOREMANAGER_H
#define XEONWARS_SCOREMANAGER_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BossManager.h"


class ScoreManager {
    public:
    ScoreManager();
    float get_score();
    void add_score(int);
    bool isBossTime();
    int getLevel();
    void nextlevelReached();
    void scoreRender(sf::RenderWindow &window);
    bool createBoss;
    bool getcreateBoss();
    void createbossOff();
    bool BossTime;
    int nextBoss_score;
    void BossTimeCheck();
    int checklifes;
    void show_levelup(sf::RenderWindow &window);

    void resetScore();

private:
    int GeneralScore;
    int currentLevel;
    sf::Text text;
    sf::Text showlevel;
    sf::Text levelup;
    sf::Font font;


};


#endif //XEONWARS_SCOREMANAGER_H
