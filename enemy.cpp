#include "enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(sf::Texture *texture)
{
    setBulletList(NULL);
    setTexture(texture);
    updateTexture(0);


}

Enemy::Enemy(sf::Texture *texture, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *bulletList)
{
    setTexture(texture);
    setBulletList(bulletList);
    enemyList->push_back(this);
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



Enemy *createEnemy(int level, sf::Texture *texture, Motion *enemyMotion,std::vector<Enemy *> *enemyList, Cannon *enemyCannon, std::vector<Bullet *> *bulletList)
{
    Enemy *newEnemy = new Enemy(texture, enemyList, bulletList);
    newEnemy->updateTexture(level);
    newEnemy->setMotion(enemyMotion);
    newEnemy->setCannon(enemyCannon);
    newEnemy->setTexturesAmount(4);
    return newEnemy;

}
//Jets: alta movilidad, ataque bajo, resistencia baja

Enemy *createJet(int level, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *bulletList)
{
    level-=1;
    Motion *enemyMotion = MotionFactory::createSimpleMotion();
    Cannon *enemyCannon = CannonFactory::createSimpleCannon();
    enemyCannon->setBulletDamage(10*(level+1));
    enemyCannon->setBulletTexture(SpritesManager::getInstance()->getEnemyBulletTexture());

    enemyCannon->setBulletDamage(10*(level+1));
    enemyCannon->setBulletSpeed(4*(level+1));
    Enemy *newEnemy = createEnemy(level,  SpritesManager::getInstance()->getJetTexture(),  enemyMotion, enemyList,  enemyCannon, bulletList);
    newEnemy->updateTexture(level);
    newEnemy->setScale(0.1+(0.01*level));
    newEnemy->setSpeed(0.6*(level+1));
    newEnemy->setTrigger(20);
    newEnemy->setLife(1);
    //newEnemy->setLife(4*(level+1));
    return newEnemy;

}

//Bombarderos: movilidad media, ataque alto y resistencia media
Enemy *createBomber(int level, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *bulletList)
{
    level-=1;
    Motion *enemyMotion = MotionFactory::createSinMotion(150);
    Cannon *enemyCannon = CannonFactory::createSprayCannon(15,level+1);
    enemyCannon->setBulletDamage(10*(level+1));
    enemyCannon->setBulletTexture(SpritesManager::getInstance()->getEnemyBulletTexture());
    //enemyCannon->setBulletTextureFilename("Resources/Bomber.png");
    //enemyCannon->setBulletSpeed(4*(level+1));
    enemyCannon->setBulletSpeed(4);
    Enemy *newEnemy = createEnemy(level,  SpritesManager::getInstance()->getBomberTexture(),  enemyMotion, enemyList,  enemyCannon, bulletList);
    newEnemy->setTexturesAmount(4);
    newEnemy->updateTexture(level);
    newEnemy->setScale(0.1+(0.01*level));
    newEnemy->setSpeed(0.6*(level+1));
    newEnemy->setTrigger(20);
    newEnemy->setLife(1);
    //newEnemy->setLife(4*(level+1));
    return newEnemy;

}



//Torres: no se mueven, están fijas en posiciones aleatorias en la pantalla y siempre apuntan al avión del jugador. Su ataque es medio

Enemy *createTower(int level, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *bulletList)
{

}

//Torres de misiles: igual que las torres pero de ataque alto.
Enemy *createMissileTower(int level, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *bulletList)
{

}
//Jets Kamikaze: no disparan, se mueven rápido y buscan chocar el avión del jugador.

Enemy *createKamikazeJet(int level, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *bulletList)
{

}



}//endNameSpace
