//
// Created by jimena on 19/04/17.
//

#ifndef XEONWARS_ENEMYREADER_H
#define XEONWARS_ENEMYREADER_H


#include <fstream>
#include <iostream>
#include <vector>
#include "enemyParameters.h"



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
