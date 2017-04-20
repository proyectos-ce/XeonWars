#include "enemyReader.h"

//
// Created by jimena on 19/04/17.
//

enemyReader::enemyReader(){
    currentLevel = 1;
    quantityOfEnemiesToRead = 2;
}

void enemyReader::readEnemyFile(){
    std::ifstream txtFile;
    txtFile.open("Resources/Enemies.txt");
    std::string enemyFile = "";
    for(int k = 0; k<quantityOfEnemiesToRead; k++) {
        std::vector<std::string> enemyAttributes;
        std::cout<<"enemigo" <<k<<std::endl;
        for (int i = 0; i < 5; i++) {
            getline(txtFile, enemyFile, '/');
            std::cout << enemyFile << std::endl;
            enemyAttributes.push_back(enemyFile);
        }
        enemyParameters newEnemy;
        newEnemy.level = enemyAttributes[0];
        newEnemy.type = enemyAttributes[1];
        newEnemy.xPosition = enemyAttributes[2];
        newEnemy.yPosition = enemyAttributes[3];
        newEnemy.movement = enemyAttributes[4];

        enemyParametersVector.push_back(newEnemy);
    }



    for(int i = 0; i<2; i++){
        std::cout << enemyParametersVector[i].level<<std::endl;
    }
};




int enemyReader::getCurrentLevel() {
    return currentLevel;
}

void enemyReader::setCurrentLevel(int numLevel) {
    currentLevel = numLevel;
}


