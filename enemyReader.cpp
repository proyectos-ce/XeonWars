#include "enemyReader.h"

//
// Created by jimena on 19/04/17.
//

enemyReader::enemyReader(){
    currentLevel = 1;
}

void readEnemyFile(){

    std::ifstream txtFile;
    txtFile.open("Resources/Enemies.txt");
    std::string tempString = "";
    while(getline(txtFile, tempString, '/')){
        std::cout << tempString << std::endl;
    }

};

int enemyReader::getCurrentLevel() {
    return currentLevel;
}

void enemyReader::setCurrentLevel(int numLevel) {
    currentLevel = numLevel;
}
