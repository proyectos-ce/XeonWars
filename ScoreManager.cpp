//
// Created by danielc on 06/04/17.
//


#include "ScoreManager.h"
#include <iostream>
using namespace std;

ScoreManager::ScoreManager(){
    GeneralScore = 0;
    BossTime = false;
    currentLevel = 1;
    if (!font.loadFromFile("Resources/menu/verdana.ttf"))
    {
        cout << "error with the font" << endl;
    }
    text.setPosition(20,10);
// select the font
    text.setFont(font);
// set the character size
    text.setCharacterSize(30); // in pixels, not points!
// set the color
    text.setColor(sf::Color::White);
// set the text style
    text.setStyle(sf::Text::Bold );
// inside the main loop, between window.clear() and window.display()
};
int ScoreManager::get_score() {
    return GeneralScore;
}
void ScoreManager::add_score(int score) {
    GeneralScore+=score;
}
bool ScoreManager::isBossTime(){
    bool result = false;
    if (BossTime) result = true;
    return result;
}
int ScoreManager::getLevel() {
    return currentLevel;
}
void ScoreManager::nextlevelReached() {
    currentLevel+=1;
}
void ScoreManager::scoreRender(sf::RenderWindow &window){
    text.setString("Score: "+GeneralScore);
    window.draw(text);
}