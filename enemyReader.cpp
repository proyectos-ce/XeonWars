#include "enemyReader.h"

//
// Created by jimena on 19/04/17.
//

EnemyReader::EnemyReader(){
    currentLevel = 1;
    quantityOfEnemiesToRead = 0;
    txtFile.open("Resources/Enemies.txt");
    std::string enemyFile = "";
    while (getline(txtFile,enemyFile,'\n')){
        quantityOfEnemiesToRead+=1;
    }
    quantityOfEnemiesToRead--;
    txtFile.close();
    txtFile.open("Resources/Enemies.txt");
}

std::vector<EnemyParameters> EnemyReader::readEnemyFile(){
    int k =0;
    std::string enemyLine="";
    std::vector<EnemyParameters>enemyParametersVector ;
    while( k<quantityOfEnemiesToRead) {
        try {

            std::getline(txtFile, enemyLine, '\n');
            if(enemyLine.find("#")!=std::string::npos){
                //std::cout<<"linea comentario"<<k<<std::endl;
                break;
            }
            else{
                std::vector<std::string> enemyAttributes;
                for (int i = 0; i < 5; i++) {
                    std::string parameter =enemyLine.substr(0,enemyLine.find_first_of(parameterDivider));
                    enemyLine.erase(0, parameter.size()+1);                            //std::cout << enemyFile;
                    enemyAttributes.push_back(parameter);
                }
                EnemyParameters newEnemy;
                newEnemy.setLevel(std::stoi(enemyAttributes[0]));
                newEnemy.setType(enemyAttributes[1]);
                newEnemy.setXPosition(std::stoi(enemyAttributes[2]));
                newEnemy.setYPosition(std::stoi(enemyAttributes[3]));
                newEnemy.setMovement(std::stof(enemyAttributes[4]));
                enemyParametersVector.push_back(newEnemy);
                //std::cout<<newEnemy.getType()<<"\n";

            }
            //enemyAttributes.push_back(enemyLine);

            //std::cout << std::endl;

        }
        catch(std::invalid_argument&) {
            std::cout << "Error in line number:" << k << '\n';
            reset();
            break;
            //throw;
        }
        k++;
    }
    return enemyParametersVector;
}

Enemy *EnemyReader::createEnemy(EnemyParameters enemyParameters)
{
    Enemy *enemy;
    //std::cout<<"___"<<enemyParameters.getType()<<"___"<<std::endl;
    if(enemyParameters.getType()=="jet"){
        //std::cout<<"jet"<<std::endl;
        enemy = EnemyFactory::createJet(enemyParameters.getLevel(),enemyParameters.getMovement());
    }
    else if(enemyParameters.getType()=="bomber"){
        //std::cout<<"bomber"<<std::endl;
        enemy = EnemyFactory::createBomber(enemyParameters.getLevel(),enemyParameters.getMovement());
    }
    else if(enemyParameters.getType()=="tower"){
        //std::cout<<"tower"<<std::endl;
        enemy = EnemyFactory::createTower(enemyParameters.getLevel());
    }
    else if(enemyParameters.getType()=="missileTower"){
        //std::cout<<"missileTower"<<std::endl;
         enemy = EnemyFactory::createMissileTower(enemyParameters.getLevel(), playerSprite);
    }
    else if(enemyParameters.getType()=="kamikaze"){
        //std::cout<<"kamikaze"<<std::endl;
        enemy = EnemyFactory::createKamikaze(enemyParameters.getLevel(), playerSprite);
    }
    else{
        enemy = EnemyFactory::createJet(enemyParameters.getLevel(),enemyParameters.getMovement());
    }
    enemy->setCenterPosition(sf::Vector2f(enemyParameters.getXPosition(),-enemyParameters.getYPosition()-200));
    return enemy;
}

void EnemyReader::reset()
{
    txtFile.close();
    txtFile.open("Resources/Enemies.txt");
}


std::vector<Enemy *> EnemyReader::getNextEnemySet()
{
    std::vector<Enemy *> enemySet;
    std::vector<EnemyParameters> enemyParametersVector = readEnemyFile();
    for (int i=0; i < enemyParametersVector.size(); ++i) {
      enemySet.push_back(createEnemy(enemyParametersVector[i]));
    }
    return enemySet;
}

sf::Sprite *EnemyReader::getPlayerSprite() const
{
    return playerSprite;
}

void EnemyReader::setPlayerSprite(sf::Sprite *value)
{
    playerSprite = value;
}




int EnemyReader::getCurrentLevel() {
    return currentLevel;
}

void EnemyReader::setCurrentLevel(int numLevel) {
    currentLevel = numLevel;
}



int EnemyParameters::getLevel() const
{
    return level;
}

void EnemyParameters::setLevel(int value)
{
    if(value>4){
        value=4;
    }
    level = value;
}


std::string EnemyParameters::getType() const
{
    return type;
}

void EnemyParameters::setType(const std::string &value)
{
    type = value;
}

int EnemyParameters::getXPosition() const
{
    return xPosition;
}

void EnemyParameters::setXPosition(int value)
{
    xPosition = value;
}

int EnemyParameters::getYPosition() const
{
    return yPosition;
}

void EnemyParameters::setYPosition(int value)
{
    yPosition = value;
}

float EnemyParameters::getMovement() const
{
    return movement;
}

void EnemyParameters::setMovement(float value)
{
    movement = value;
}
