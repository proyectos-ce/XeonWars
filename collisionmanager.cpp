#include "collisionmanager.h"

CollisionManager::CollisionManager()
{

}

CollisionManager::CollisionManager(MainSpaceShip *playerShip, std::vector<Entity *> *playerBulletList, std::vector<Entity *> *enemyList)
{
    setEnemyList(enemyList);
    setPlayerBulletList(playerBulletList);
    setPlayerShip(playerShip);

}

void CollisionManager::checkCollisions()
{
    for(int i=0;i<enemyList->size();i++){

        if( enemyList->operator[](i)->getType()=='B'  &   Collision::PixelPerfectTest(playerShip->getSprite(), enemyList->operator[](i)->getSprite())){
            std::cout<<"choque bala"<<std::endl;
            Entity *toDelete = (enemyList->operator[](i));

            enemyList->erase(enemyList->begin()+i);
            //std::cout<<toDelete->getSpeed()<<std::endl;
            //delete toDelete;
        }
        else if( enemyList->operator[](i)->getType()=='E'  &   Collision::PixelPerfectTest(playerShip->getSprite(), enemyList->operator[](i)->getSprite())){
            std::cout<<"choque nave"<<std::endl;
            //Entity *toDelete = (enemyList->operator[](i));

            enemyList->erase(enemyList->begin()+i);
            //delete toDelete;
        }


    }
    //player bullets vs enemies

    for(int j=0;j<playerBulletList->size();j++){
        for(int i=0;i<enemyList->size();i++){
            if( enemyList->operator[](i)->getType()=='E'  &   Collision::PixelPerfectTest(playerBulletList->operator[](j)->getSprite(), enemyList->operator[](i)->getSprite())){
                if(enemyList->operator[](i)->attack(playerBulletList->operator[](j)->getDamage())){
                    enemyList->erase(enemyList->begin()+i);
                }
                std::cout<<"choque"<<std::endl;
                Entity *toDelete = (playerBulletList->operator[](j));
                delete toDelete;
                playerBulletList->erase(playerBulletList->begin()+j);
                std::cout<<"deleted endzzzz"<<std::endl;
                break;
            }
        }
    }
}

std::vector<Entity *> *CollisionManager::getEnemyList() const
{
    return enemyList;
}

void CollisionManager::setEnemyList(std::vector<Entity *> *value)
{
    enemyList = value;
}

std::vector<Entity *> *CollisionManager::getPlayerBulletList() const
{
    return playerBulletList;
}

void CollisionManager::setPlayerBulletList(std::vector<Entity *> *value)
{
    playerBulletList = value;
}

MainSpaceShip *CollisionManager::getPlayerShip() const
{
    return playerShip;
}

void CollisionManager::setPlayerShip(MainSpaceShip *value)
{
    playerShip = value;
}
