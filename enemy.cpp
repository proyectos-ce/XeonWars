#include "enemy.h"

Enemy::Enemy()
{
}



Enemy::Enemy(sf::Texture *texture)
{
    setTexture(texture);
    //setBulletList(bulletList);
    //enemyList->push_back(this);
}
Enemy::~Enemy()
{
    delete cannon;

}

std::vector<Bullet *> *Enemy::getBulletList() const
{
    return bulletList;
}

void Enemy::setBulletList(std::vector<Bullet *> *value)
{
    bulletList = value;
    if(cannon!=NULL){
    cannon->setBulletList(bulletList);
   }
}

bool Enemy::attack(int damage)
{

    bool result=false;
    if(damage==-1){
        kill();
        result=true;
    }
    else if(damage>0){
        life-=damage;
        if(life<=0){
            kill();
            result=true;
        }
    }
    return result;

}

void Enemy::update(sf::RenderWindow &window, float time)
{

    Entity::update(window, time);

    if(trigger!=0 && moves%trigger==0){
        shoot();
        //updateTexture(++currentTexture);

    }
    moves++;
}

int Enemy::getTrigger() const
{
    return trigger;
}

void Enemy::setTrigger(int value)
{
    trigger = value;
}

void Enemy::shoot()
{
    cannon->shoot();

}

int Enemy::getMoves() const
{
    return moves;
}

void Enemy::setMoves(int value)
{
    moves = value;
}

Cannon *Enemy::getCannon() const
{
    return cannon;
}

void Enemy::setCannon(Cannon *value)
{
    cannon = value;
    cannon->setOwnerSprite(&(this->sprite));
    cannon->setBulletList(bulletList);
}



int Enemy::getLife() const
{
    return life;
}

void Enemy::setLife(int value)
{
    life = value;
}

int Enemy::getEnemy_score() {
    return enemy_score;
}

void Enemy::setEnemy_score(int score) {
    enemy_score = score;
}





namespace EnemyFactory {



Enemy *createEnemy(int level, sf::Texture *texture, Motion *enemyMotion, Cannon *enemyCannon)
{
    Enemy *newEnemy = new Enemy(texture);
    newEnemy->updateTexture(level);
    if(enemyCannon!=NULL){
    newEnemy->setCannon(enemyCannon);
    }
    if(enemyMotion!=NULL){
        newEnemy->setMotion(enemyMotion);
    }

    return newEnemy;

}
//Jets: alta movilidad, ataque bajo, resistencia baja

Enemy *createJet(int level, float angle)
{
    Motion *enemyMotion = MotionFactory::createLinearMotion(angle);
    Cannon *enemyCannon = CannonFactory::createSimpleCannon();
    enemyCannon->setBulletDamage(10*level);
    enemyCannon->setBulletTexture(SpritesManager::getInstance()->getEnemyBulletTexture());
    enemyCannon->setBulletDamage(10*level);
    enemyCannon->setBulletSpeed(4*level);
    Enemy *newEnemy = createEnemy(level-1,  SpritesManager::getInstance()->getJetTexture(),  enemyMotion,  enemyCannon);
    newEnemy->updateTexture(level);
    newEnemy->setScale(0.1+(0.01*level));
    newEnemy->setSpeed(level+1);
    newEnemy->setTrigger(20);
    newEnemy->setLife(1);
    newEnemy->setTexturesAmount(4);

    //newEnemy->setLife(4*(level+1));
    return newEnemy;

}

//Bombarderos: movilidad media, ataque alto y resistencia media
Enemy *createBomber(int level, float motionScale)
{
    Motion *enemyMotion = MotionFactory::createSinMotion(motionScale);
    Cannon *enemyCannon = CannonFactory::createSprayCannon(15,level);
    enemyCannon->setBulletDamage(10*level);
    enemyCannon->setBulletTexture(SpritesManager::getInstance()->getEnemyBulletTexture());
    //enemyCannon->setBulletTextureFilename("Resources/Bomber.png");
    //enemyCannon->setBulletSpeed(4*(level+1));
    enemyCannon->setBulletSpeed(4);
    Enemy *newEnemy = createEnemy(level-1,  SpritesManager::getInstance()->getBomberTexture(),  enemyMotion,  enemyCannon);
    newEnemy->setTexturesAmount(4);
    newEnemy->updateTexture(level);
    newEnemy->setScale(0.1+(0.01*level));
    newEnemy->setSpeed(0.6*level);
    newEnemy->setTrigger(20);
    newEnemy->setLife(1);
    return newEnemy;

}



//Torres: no se mueven, están fijas en posiciones aleatorias en la pantalla y siempre apuntan al avión del jugador. Su ataque es medio

Enemy *createTower(int level, int backgroundSpeed)
{
    Motion *enemyMotion = MotionFactory::createSimpleMotion();
    Cannon *enemyCannon = CannonFactory::createSprayCannon(360/(3+level) , 3+level);
    enemyCannon->setBulletDamage(10*level);
    enemyCannon->setBulletTexture(SpritesManager::getInstance()->getEnemyBulletTexture());
    //enemyCannon->setBulletTextureFilename("Resources/Bomber.png");
    //enemyCannon->setBulletSpeed(4*(level+1));
    enemyCannon->setBulletSpeed(backgroundSpeed+1+level/2);
    enemyCannon->setBulletDamage(3*level);
    Enemy *newEnemy = createEnemy(level,  SpritesManager::getInstance()->getTowerTexture(),  enemyMotion,  enemyCannon);
    newEnemy->setTexturesAmount(4);
    newEnemy->updateTexture(level-1);
    newEnemy->setScale(0.1+(0.01*level));
    newEnemy->setSpeed(backgroundSpeed);
    newEnemy->setTrigger(120/level);
    newEnemy->setLife(1);
    //newEnemy->setLife(4*(level+1));
    return newEnemy;

}

//Torres de misiles: igual que las torres pero de ataque alto.
Enemy *createMissileTower(int level, sf::Sprite *target, int backgroundSpeed)
{
    Motion *enemyMotion = MotionFactory::createSimpleMotion();
    Enemy *newEnemy = createEnemy(level,  SpritesManager::getInstance()->getMissileTowerTexture(),  enemyMotion,  NULL);
    Cannon *enemyCannon = CannonFactory::createFollowerCannon(newEnemy->getSpriteReference(), target);
    enemyCannon->setBulletDamage(10*level);
    enemyCannon->setBulletTexture(SpritesManager::getInstance()->getFollowerBulletTexture());
    enemyCannon->setBulletSpeed(backgroundSpeed+1+level/2);
    enemyCannon->setBulletDamage(3*level);
    newEnemy->setCannon(enemyCannon);
    newEnemy->setTexturesAmount(4);
    newEnemy->updateTexture(level-1);
    newEnemy->setScale(0.1+(0.01*level));
    newEnemy->setSpeed(backgroundSpeed);
    newEnemy->setTrigger(120/level);
    newEnemy->setLife(1);
    return newEnemy;
}
//Jets Kamikaze: no disparan, se mueven rápido y buscan chocar el avión del jugador.

Enemy *createKamikaze(int level, sf::Sprite *target)
{
    Cannon *enemyCannon = CannonFactory::createSimpleCannon();
    enemyCannon->setBulletDamage(10*level);
    enemyCannon->setBulletTexture(SpritesManager::getInstance()->getFollowerBulletTexture());
    enemyCannon->setBulletSpeed(20);
    enemyCannon->setBulletDamage(3*level);

    Enemy *newEnemy = createEnemy(level,  SpritesManager::getInstance()->getKamikazeTexture(),  NULL,  enemyCannon);
    Motion *enemyMotion = MotionFactory::createFollowerMotion(newEnemy->getSpriteReference(), target);
    newEnemy->setMotion(enemyMotion);
    newEnemy->setTexturesAmount(4);
    newEnemy->updateTexture(level-1);

    newEnemy->setScale(0.1+(0.01*level));
    newEnemy->setSpeed(2*level);
    newEnemy->setTrigger(0);
    newEnemy->setLife(1);

    return newEnemy;
}



}//endNameSpace
