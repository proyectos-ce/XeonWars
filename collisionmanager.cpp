#include "collisionmanager.h"

CollisionManager::CollisionManager()
{

}

CollisionManager::CollisionManager(MainSpaceShip *playerShip, std::vector<Bullet *> *playerBulletList, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *enemyBulletList)
{
    setEnemyList(enemyList);
    setPlayerBulletList(playerBulletList);
    setPlayerShip(playerShip);

}

void CollisionManager::checkCollisions()
{
    int i = 0, j=0;
    while(i<enemyList->size()){
        //player vs enemies
        if(Collision::PixelPerfectTest(playerShip->getSprite(), enemyList->operator[](i)->getSprite())){
            //kill player
            deleteEnemy(enemyList,i);
            i--;
        }

        else{
            //player bullets vs enemies
            j=0;
            while(j<playerBulletList->size()){
                if(Collision::PixelPerfectTest(playerBulletList->operator[](j)->getSprite(), enemyList->operator[](i)->getSprite())){
                    std::cout<<"bala vs enemigo\n";
                    if(enemyList->operator[](i)->attack(playerBulletList->operator[](j)->getDamage())){
                        deleteEnemy(enemyList,i);
                        deleteBullet(playerBulletList, j);
                        i--;
                        break;
                    }
                    //delete player bullet
                    deleteBullet(playerBulletList, j);
                    j--;
                }
                j++;
            }
        }
        i++;
    }
    //player vs enemy bullets
    i=0;
    while(i<enemyBulletList->size()){
        //player vs enemies
        if(Collision::PixelPerfectTest(playerShip->getSprite(), enemyBulletList->operator[](i)->getSprite())){
            //attack player
            deleteBullet(enemyBulletList, i);
            //delete bullet
            i--;
        }
        i++;
    }
}
MainSpaceShip *CollisionManager::getPlayerShip() const
{
    return playerShip;
}

void CollisionManager::setPlayerShip(MainSpaceShip *value)
{
    playerShip = value;
}

std::vector<Enemy *> *CollisionManager::getEnemyList() const
{
    return enemyList;
}

void CollisionManager::setEnemyList(std::vector<Enemy *> *value)
{
    enemyList = value;
}

std::vector<Bullet *> *CollisionManager::getPlayerBulletList() const
{
    return playerBulletList;
}

void CollisionManager::setPlayerBulletList(std::vector<Bullet *> *value)
{
    playerBulletList = value;
}

std::vector<Bullet *> *CollisionManager::getEnemyBulletList() const
{
    return enemyBulletList;
}

void CollisionManager::setEnemyBulletList(std::vector<Bullet *> *value)
{
    enemyBulletList = value;
}

void CollisionManager::deleteEnemy(std::vector<Enemy *> *list, int index)
{
    Enemy *enemyToDelete = (list->operator [](index));
    //delete (list->operator [](index));
    list->erase(list->begin()+index);
    std::cout<<"eliminado-- enemigo\n";
    //delete enemyToDelete;
    std::cout<<"eliminado enemigo\n";


}

void CollisionManager::deleteBullet(std::vector<Bullet *> *list, int index)
{
    Bullet *bulletToDelete = list->operator [](index);
    //delete (list->operator [](index));
    list->erase(list->begin()+index);
    delete bulletToDelete;

}
