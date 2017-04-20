#include "enemyReader.h"

//
// Created by jimena on 19/04/17.
//

enemyReader::enemyReader(){
    currentLevel = 1;
    quantityOfEnemiesToRead = 0;
}

void enemyReader::readEnemyFile(){
    std::ifstream txtFile;
    txtFile.open("Resources/Enemies.txt");
    std::string enemyFile = "";

    while (getline(txtFile,enemyFile,'\n')){
        quantityOfEnemiesToRead+=1;

    }
    quantityOfEnemiesToRead--;
    txtFile.close();
    txtFile.open("Resources/Enemies.txt");

    //std::cout <<"enemies to read"<< quantityOfEnemiesToRead << std::endl;
       // Code that could throw an exception

    for(int k = 0; k<quantityOfEnemiesToRead; k++) {
        try {

        std::vector<std::string> enemyAttributes;
        std::cout<<"enemigo" <<k<<std::endl;
        for (int i = 0; i < 5; i++) {
            std::getline(txtFile, enemyFile, '/');
            //std::cout << enemyFile;
            enemyAttributes.push_back(enemyFile);
        }
        //std::cout << std::endl;
        enemyParameters newEnemy;
        newEnemy.setLevel(std::stoi(enemyAttributes[0]));
        newEnemy.setType(enemyAttributes[1]);
        newEnemy.setXPosition(std::stoi(enemyAttributes[2]));
        newEnemy.setYPosition(std::stoi(enemyAttributes[3]));
        newEnemy.setMovement(std::stof(enemyAttributes[4]));
        enemyParametersVector.push_back(newEnemy);
        }
        catch(std::invalid_argument&) {
            std::cout << "Error in line number:" << k << '\n';
            break;
            //throw;
        }
    }
    //for(int i = 0; i<quantityOfEnemiesToRead; i++){
    //    std::cout << enemyParametersVector[i].getLevel()<<std::endl;
    //}

};




int enemyReader::getCurrentLevel() {
    return currentLevel;
}

void enemyReader::setCurrentLevel(int numLevel) {
    currentLevel = numLevel;
}



int enemyParameters::getLevel() const
{
    return level;
}

void enemyParameters::setLevel(int value)
{
    if(value>4){
        value=4;
    }
    level = value;
}

std::string enemyParameters::getType() const
{
    return type;
}

void enemyParameters::setType(const std::string &value)
{
    type = value;
}

int enemyParameters::getXPosition() const
{
    return xPosition;
}

void enemyParameters::setXPosition(int value)
{
    xPosition = value;
}

int enemyParameters::getYPosition() const
{
    return yPosition;
}

void enemyParameters::setYPosition(int value)
{
    yPosition = value;
}

float enemyParameters::getMovement() const
{
    return movement;
}

void enemyParameters::setMovement(float value)
{
    movement = value;
}
