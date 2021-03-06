//
// Created by danielc on 06/04/17.
//


#include "ScoreManager.h"
#include "Game.h"
#include <iostream>
using namespace std;

ScoreManager::ScoreManager(){
    GeneralScore = 0;
    BossTime = false;
    createBoss = false;
    currentLevel = 1;
    nextBoss_score=1500;
    checklifes=0;
    if (!font.loadFromFile("Resources/menu/8bit.ttf"))
    {
        cout << "error with the font" << endl;
    }
    text.setPosition(20,0);
// select the font
    text.setFont(font);
// set the character size
    text.setCharacterSize(50); // in pixels, not points!
// set the color
    text.setColor(sf::Color::White);
// set the text style
    text.setStyle(sf::Text::Bold );
// inside the main loop, between window.clear() and window.display
    levelup.setPosition(480,-10);
// select the font
    levelup.setFont(font);
// set the character size
    levelup.setCharacterSize(65); // in pixels, not points!
// set the color
    levelup.setColor(sf::Color::Red);
// set the text style
    levelup.setStyle(sf::Text::Bold );
    showlevel.setPosition(20,45);
// select the font
    showlevel.setFont(font);
// set the character size
    showlevel.setCharacterSize(50); // in pixels, not points!
// set the color
    showlevel.setColor(sf::Color::White);
// set the text style
    showlevel.setStyle(sf::Text::Bold );
};

float ScoreManager::get_score() {
    return GeneralScore;
}
bool ScoreManager::getcreateBoss() {
  return createBoss;
};
void ScoreManager::createbossOff(){
    createBoss=false;
}

void ScoreManager::add_score(int score) {
    GeneralScore+=score;
    checklifes+= score;
}
void ScoreManager::resetScore() {
    GeneralScore = 0;
    BossTime = false;
    createBoss = false;
    currentLevel = 1;
    nextBoss_score=1500;
    checklifes=0;
}
bool ScoreManager::isBossTime(){
    bool result = false;
    if (BossTime) result = true;
    return result;
}
void ScoreManager::BossTimeCheck(){
    if (get_score()>=nextBoss_score) {
        BossTime = true;
        createBoss = true;
        nextBoss_score *= 2.5;
    }
}
int ScoreManager::getLevel() {
    return currentLevel;
}
void ScoreManager::nextlevelReached() {
    currentLevel+=1;
}
void ScoreManager::scoreRender(sf::RenderWindow &window){
    text.setString("Score: "+to_string(GeneralScore));
    window.draw(text);
    showlevel.setString("Lvl: "+to_string(currentLevel));
    window.draw(showlevel);
}
void ScoreManager::show_levelup(sf::RenderWindow &window){
    levelup.setString("LEVEL UP!!!");
    window.draw(levelup);
}