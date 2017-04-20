//
// Created by jimena on 19/04/17.
//

#ifndef XEONWARS_ENEMYREADER_H
#define XEONWARS_ENEMYREADER_H


#include <fstream>
#include <iostream>
#include <vector>
//#include "enemyParameters.h"

class enemyParameters{
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

class enemyReader{
private:
    int currentLevel;
    int quantityOfEnemiesToRead;

public:
    enemyReader();
    int getCurrentLevel();
    std::vector<enemyParameters> enemyParametersVector;

    void setCurrentLevel(int numLevel);
    void readEnemyFile();

};


#endif //XEONWARS_ENEMYREADER_H
