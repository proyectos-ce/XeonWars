//
// Created by jimena on 3/24/17.
//
#include <iostream>
#include "MainSpaceShip.h"
#include "ScoreManager.h"

MainSpaceShip::MainSpaceShip() {
    lifes = 3;
    scoreForLifes = 0;
    globalScore = 0;


    TOwnSpaceShip.loadFromFile("Resources/FramesNave.png");
    TOwnSpaceShip.setSmooth(true);
    SOwnSpaceShip.setTexture(TOwnSpaceShip);
    SOwnSpaceShip.setTextureRect(IntRect(100, 0, 100, 80));
    //SOwnSpaceShip.setColor(sf::Color(0,250,100,255));
    //SOwnSpaceShip.setScale(sf::Vector2f(0.8,0.8));
    SOwnSpaceShip.setPosition(550,720);

    normalShootBuffer.loadFromFile("Resources/sfx_laser1.ogg");
    missileShootBuffer.loadFromFile("Resources/sfx_laser2.ogg");
    shieldOnSound.loadFromFile("Resources/sfx_shieldUp.ogg");
    shieldOffSound.loadFromFile("Resources/sfx_shieldDown.ogg");
    




    powerUp p1(missile);
    powerUp p2(shieldd);
    powerUp p3(laser);
    powerUp p4(missile);


    powerUpsQueue.enqueue(p1);
    powerUpsQueue.enqueue(p2);
    powerUpsQueue.enqueue(p3);
    powerUpsQueue.enqueue(p4);




    shipCannon = CannonFactory::createSprayCannon(3,1);

    shipCannon->setOwnerSprite(&SOwnSpaceShip);
    shipCannon->setBulletDamage(14);
    shipCannon->setBulletSpeed(3);
    shipCannon->setReverseDirection(1);
    shipCannon->setBulletTextureFilename("Resources/Bullets.png");

    missileCannon = CannonFactory::createSprayCannon(10,7);

    missileCannon->setOwnerSprite(&SOwnSpaceShip);
    missileCannon->setBulletDamage(30);
    missileCannon->setBulletSpeed(-6);

    missiles_On=false;
    laser_On= false;
    missileShootCounter=0;

}


std::vector<Bullet *> *MainSpaceShip::getbulletList() const
{
    return bulletList;
}

void MainSpaceShip::setbulletList(std::vector<Bullet *> *value)
{

    bulletList = value;
    shipCannon->setBulletList(bulletList);
    missileCannon->setBulletList(bulletList);
}
void MainSpaceShip::lifeManager(int damage){
    lifeLevel-=damage;
    if (lifeLevel<=0){
        lifes -=1;
        lifeLevel=100;
        if (lifes <= 0){
            gameOver();
        }
    }
}

void MainSpaceShip::update(RenderWindow &window, float time) {

    checkShieldTimer();

    bool anyKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

    // Si no hay ninguna tecla presionada la velocidad se pone en 0 si es muy pequeña
    if (!anyKeyPressed) {
        if (std::fabs(velocity.y) <= speed/2)
            velocity.y = 0;

        if (std::fabs(velocity.x) <= speed/2)
            velocity.x = 0;
    }

    // Modifica el vector segun las teclas presionadas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        velocity.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        velocity.y += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity.x += speed;
   // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
     //   playerShoot();



    // Air friction
    if (velocity.y > 0)
        velocity.y -= speed/2;
    else if (velocity.y < 0)
        velocity.y += speed/2;

    if (velocity.x > 0) {
        SOwnSpaceShip.setTextureRect(IntRect(200, 0, 95, 80));
        velocity.x -= speed/2;
    } else if (velocity.x < 0) {
        SOwnSpaceShip.setTextureRect(IntRect(0, 0, 95, 80));
        velocity.x += speed/2;
    } else {
        SOwnSpaceShip.setTextureRect(IntRect(100, 0, 100, 80));
    }

    // Maximum speed

    if (std::fabs(velocity.x) > maxSpeed)
    {
        if (velocity.x > 0)
            velocity.x = maxSpeed;
        else
            velocity.x = -maxSpeed;
    }
    if (std::fabs(velocity.y) > maxSpeed)
    {
        if (velocity.y > 0)
            velocity.y = maxSpeed;
        else
            velocity.y = -maxSpeed;
    }

    
    // Limites de la pantalla

    if(SOwnSpaceShip.getPosition().x < 0) {
        velocity.x = 0;
        SOwnSpaceShip.setPosition(0, SOwnSpaceShip.getPosition().y);
    }

    if(SOwnSpaceShip.getPosition().y < 0) {
        velocity.y = 0;
        SOwnSpaceShip.setPosition(SOwnSpaceShip.getPosition().x, 0);
    }

    if (SOwnSpaceShip.getPosition().x > window.getSize().x - SOwnSpaceShip.getGlobalBounds().width) {
        velocity.x = 0;
        SOwnSpaceShip.setPosition(window.getSize().x - SOwnSpaceShip.getGlobalBounds().width,  SOwnSpaceShip.getPosition().y);
    }

    if (SOwnSpaceShip.getPosition().y > window.getSize().y - SOwnSpaceShip.getGlobalBounds().height) {
        velocity.y = 0;
        SOwnSpaceShip.setPosition(SOwnSpaceShip.getPosition().x, window.getSize().y - SOwnSpaceShip.getGlobalBounds().height);
    }

    SOwnSpaceShip.move(velocity * (time/30));


}

void MainSpaceShip::render(RenderWindow &window) {
    window.draw(SOwnSpaceShip);
}

void MainSpaceShip::usePowerUp() {
    if(!powerUpsQueue.isEmpty()) {
        int powerToUse = powerUpsQueue.dequeue().getType();
        if(powerToUse == 0){
            cout <<"Misiles"<<endl;
            missiles_On=true;
        }
        else if(powerToUse == 1){
            if(!shieldActivated) shield();
            cout <<"Escudo"<<endl;
        }
        else if(powerToUse == 2){
            cout <<"Laser"<<endl;
            laser_On;
        }
    }else{
        cout <<"No hay power ups"<<endl;
    }
}

void MainSpaceShip::shield() {
    if(shieldActivated == false){
        shieldActivated = true;
        shieldClock.restart();
        sound.setBuffer(shieldOnSound);
        cout<<"Escudo activado"<<endl;
    }else{
        shieldActivated =false;
        sound.setBuffer(shieldOffSound);
    }
    sound.play();
}

bool MainSpaceShip::gameOver() {
   cout << "aqui hay que programar que termine el juego" << endl;
}



void MainSpaceShip::playerShoot() {
    // CHEQUEAR SI LA NAVE TIENE ACTIVADO LOS MISILES _______________________________******
    if (missiles_On){
        if(missileShootCounter <5) {
            missileShootCounter++;
            missileCannon->shoot();
            sound.setBuffer(missileShootBuffer);
            cout << "disparo misil" << endl;
        }else{
            missiles_On= false;
            missileShootCounter=0;
            sound.setBuffer(normalShootBuffer);
            shipCannon->shoot();
        }
    } else if (laser_On){
        cout << "disparo laser" << endl;
    } else {

        shipCannon->shoot();
        sound.setBuffer(normalShootBuffer);
        //std::cout<< shipCannon->getBulletDamage()<<endl;
        cout << "disparo simple" << endl;
    }
    sound.play();
}
bool MainSpaceShip::attack(int damage)
{

}

int MainSpaceShip::getLifeLevel() const
{
    return lifeLevel;
}

void MainSpaceShip::setLifeLevel(int value)
{
    lifeLevel = value;
}

Sprite *MainSpaceShip::getSpriteReference()
{
    return &SOwnSpaceShip;
}


Sprite MainSpaceShip::getSprite() const
{
    return SOwnSpaceShip;
}

void MainSpaceShip::checkShieldTimer() {
    if(shieldClock.getElapsedTime().asMilliseconds()>10000 && shieldActivated==true) {
        shield();
    }
}


