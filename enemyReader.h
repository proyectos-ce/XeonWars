//
// Created by jimena on 19/04/17.
//

#ifndef XEONWARS_ENEMYREADER_H
#define XEONWARS_ENEMYREADER_H


#include <fstream>
#include <iostream>
#include <vector>
#include "enemy.h"
#include "entity.h"
//#include "enemyParameters.h"

class EnemyParameters{
public:
    int getLevel() const;
    void setLevel(int value);

    std::string getType() const;
    void setType(const std::string &value);

    int getXPosition() const;
    void setXPosition(int value);

    int getYPosition() const;
    void setYPosition(int value);

    float getMovement() const;
    void setMovement(float value);

private:
    int level;
    std::string type;
    int xPosition;
    int yPosition;
    float movement;
};




class EnemyReader{

private:
    int currentLevel;
    int quantityOfEnemiesToRead;
    std::vector<EnemyParameters> readEnemyFile();
    Enemy *createEnemy(EnemyParameters enemyParameters);
    sf::Sprite *playerSprite;
    void reset();



public:
    EnemyReader();
    int getCurrentLevel();
    std::ifstream txtFile;
    void setCurrentLevel(int numLevel);
    std::string setDivider = "%";
    std::string enemyDivider = "\n";
    std::string parameterDivider = "/";
    std::vector<Enemy *> getNextEnemySet();
    //void getNextEnemySet();

    sf::Sprite *getPlayerSprite() const;
    void setPlayerSprite(sf::Sprite *value);
};


#endif //XEONWARS_ENEMYREADER_H
