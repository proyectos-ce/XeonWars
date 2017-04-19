#include "enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(sf::Texture texture)
{
    setBulletList(NULL);
    setTexture(texture);
    updateTexture(0);


}

Enemy::Enemy(sf::Texture texture, std::vector<Enemy *> *enemyList, std::vector<Bullet *> *bulletList)
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



/*
Jets: alta movilidad, ataque bajo, resistencia baja
Bombarderos: movilidad media, ataque alto y resistencia media
Torres: no se mueven, están fijas en posiciones aleatorias en la pantalla y siempre apuntan al avión del jugador. Su ataque es medio
Torres de misiles: igual que las torres pero de ataque alto.
Jets Kamikaze: no disparan, se mueven rápido y buscan chocar el avión del jugador.
Definido por el estudiante
Definido por el estudiante

*/

namespace EnemyFactory {

Enemy *createEnemy(int level, sf::Texture texture, Motion *enemyMotion,std::vector<Enemy *> *enemyList, Cannon *enemyCannon, std::vector<Bullet *> *bulletList)
{
    //enemyCannon->setBulletDamage(10);
    //enemyCannon->setBulletSpeed(5);
    //texture.loadFromFile("Resources/MissileTower.png");
    Enemy *enemyShip;
    enemyShip = new Enemy(texture, enemyList, bulletList);
    enemyShip->setTexturesAmount(4);
    enemyShip->updateTexture(level);
    enemyShip->setMotion(enemyMotion);
    //enemyShip->setSpeed(minSpeed*level);
    //enemyShip->setTrigger(60);
    enemyShip->setCannon(enemyCannon);
    enemyShip->setScale(0.2+(0.05*level));
    return enemyShip;

}



Enemy *createBomber(int level)
{
    //create texture
    //create motion
    //motion things


}

Enemy *createTower(int level)
{

}

Enemy *createMissileTower(int level)
{

}

Enemy *createKamikazeJet(int level)
{

}

Enemy *createJet(int level, std::vector<Enemy *> *enemyList, Cannon *enemyCannon, std::vector<Bullet *> *bulletList)
{

}

}//endNameSpace
