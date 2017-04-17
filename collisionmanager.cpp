#include "collisionmanager.h"

CollisionManager::CollisionManager()
{
    collisionSpaceEnemySoundBuffer.loadFromFile("Resources/explosion.ogg");
    collisionBulletEnemySoundBuffer.loadFromFile("Resources/collisionSpaceEnemy.ogg");
}

CollisionManager::CollisionManager(MainSpaceShip *playerShip, std::vector<Bullet *> *playerBulletList, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *enemyBulletList)
{
    setEnemyList(enemyList);
    setPlayerBulletList(playerBulletList);
    setPlayerShip(playerShip);

}

bool CollisionManager::checkCollisions()
{
    int i = 0, j=0;
    while(i<enemyList->size()){
        //player vs enemies
        if(Collision::PixelPerfectTest(playerShip->getSprite(), enemyList->operator[](i)->getSprite())){
            //kill player
            collisionSound.setBuffer(collisionSpaceEnemySoundBuffer);
            collisionSound.play();
            deleteEnemy(enemyList,i);
            i--;
            //return true;
        }

        else{
            //player bullets vs enemies
            j=0;
            while(j<playerBulletList->size()){
                if(Collision::PixelPerfectTest(playerBulletList->operator[](j)->getSprite(), enemyList->operator[](i)->getSprite())){
                    collisionSound.setBuffer(collisionBulletEnemySoundBuffer);
                    collisionSound.play();
                    //std::cout<<"bala vs enemigo\n";
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

            getPlayerShip()->doDamageAnimation();


            //attack player

            deleteBullet(enemyBulletList, i);
            //delete bullet
            playerShip->setLifeLevel(playerShip->getLifeLevel()-enemyBulletList->operator[](i)->getDamage());
            if(playerShip->getLifeLevel() <=0){
                if(playerShip->getLifes() <=0){
                    collisionSound.setBuffer(collisionSpaceEnemySoundBuffer);
                    collisionSound.play();
                    return true;
                }else{
                    playerShip->setLifes(playerShip->getLifes()-1);
                    playerShip->setLifeLevel(100);
                }
            }

            i--;
        }
        i++;
    }
    return false;
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
    delete (list->operator [](index));
    list->erase(list->begin()+index);
}

void CollisionManager::deleteBullet(std::vector<Bullet *> *list, int index)
{
    delete (list->operator [](index));
    list->erase(list->begin()+index);

}
