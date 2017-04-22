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

        if(playerShip->getBlinkAnimationCounter() == 0 && !enemyList->operator[](i)->isExploding() && Collision::PixelPerfectTest(playerShip->getSprite(), enemyList->operator[](i)->getSprite())) {
            //kill player
            collisionSound.setBuffer(collisionSpaceEnemySoundBuffer);
            collisionSound.play();

            if (!enemyList->operator[](i)->isBoss()) {
                //deleteEnemy(enemyList, i);
                enemyList->operator[](i)->explode();
            }

            playerShip->loseLife();
            i--;
            if(playerShip->attack(0)){
            return true;
            }
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
                        addLastScore(enemyList->operator[](i)->getEnemy_score());
                        powerUpList->push_back(PowerUpFactory::createLaserPU( enemyList->operator[](i)->getPosition() ));
                        explosionList->push_back(ExplosionFactory::createSimpleExplosion(enemyList->operator[](i)->getPosition()));
                        deleteEnemy(enemyList,i);
                        //enemyList->operator[](i)->explode();
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
        if(playerShip->getBlinkAnimationCounter() == 0 && Collision::PixelPerfectTest(playerShip->getSprite(), enemyBulletList->operator[](i)->getSprite())){

            collisionSound.setBuffer(collisionSpaceEnemySoundBuffer);
            collisionSound.play();

            //attack player

            deleteBullet(enemyBulletList, i);
            //delete bullet
            //playerShip->attack(enemyBulletList->operator[](i)->getDamage());
            //playerShip->setLifeLevel(playerShip->getLifeLevel()-enemyBulletList->operator[](i)->getDamage());
            if(playerShip->attack(enemyBulletList->operator[](i)->getDamage())){
            //if(playerShip->getLifeLevel() <=0){
                //if(playerShip->getLifes() <=0){
                    collisionSound.setBuffer(collisionSpaceEnemySoundBuffer);
                    collisionSound.play();
                    return true;
                //}
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

int CollisionManager::getLastScore()
{
    int newScore = lastScore;
    setLastScore(0);
    return newScore;
}

void CollisionManager::addLastScore(int score)
{
    lastScore+=score;
}

void CollisionManager::setLastScore(int value)
{
    lastScore = value;
}

std::vector<FlyingPowerUp *> *CollisionManager::getPowerUpList() const
{
    return powerUpList;
}

void CollisionManager::setPowerUpList(std::vector<FlyingPowerUp *> *value)
{
    powerUpList = value;
}

std::vector<Explosion *> *CollisionManager::getExplosionList() const
{
    return explosionList;
}

void CollisionManager::setExplosionList(std::vector<Explosion *> *value)
{
    explosionList = value;
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
