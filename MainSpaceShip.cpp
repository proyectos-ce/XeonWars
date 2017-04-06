//
// Created by jimena on 3/24/17.
//
#include <iostream>
#include "MainSpaceShip.h"

MainSpaceShip::MainSpaceShip() {
    lifes = 3;
    scoreForLifes = 0;
    globalScore = 0;

    TOwnSpaceShip.loadFromFile("Resources/FramesNave.png");
    TOwnSpaceShip.setSmooth(true);
    SOwnSpaceShip.setTexture(TOwnSpaceShip);
    SOwnSpaceShip.setTextureRect(IntRect(100, 0, 100, 80));
    SOwnSpaceShip.setPosition(550,720);

    powerUp p1(missile);
    powerUp p2(shieldd);
    powerUp p3(laser);

    powerUpsQueue.enqueue(p1);
    powerUpsQueue.enqueue(p2);
    powerUpsQueue.enqueue(p3);


    shipCannon = cannonFactory.createSimpleCannon();

    shipCannon->setOwnerSprite(&SOwnSpaceShip);
    shipCannon->setBulletDamage(30);
    shipCannon->setBulletSpeed(-6);

}


std::vector<Entity *> *MainSpaceShip::getplayerbulletList() const
{
    return playerbulletList;
}

void MainSpaceShip::setplayerbulletList(std::vector<Entity *> *value)
{
    playerbulletList = value;
    shipCannon->setEnemyList(playerbulletList);

}
void MainSpaceShip::lifeManager(int daño){
    lifeLevel-=daño;
    if (lifeLevel<=0){
        lifes -=1;
        lifeLevel=100;
        if (lifes <= 0){
            gameOver();
        }
    }
}

void MainSpaceShip::update(RenderWindow &window, float time) {

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
        }
        else if(powerToUse == 1){
            shield();
            cout <<"Escudo"<<endl;
        }
        else if(powerToUse == 2){
            cout <<"Laser"<<endl;
        }
    }else{
        cout <<"No hay power ups"<<endl;
    }
}

void MainSpaceShip::shield() {
    if(shieldActivated == false){
        shieldActivated = true;
        cout<<"Escudo activado"<<endl;
    }
}

bool MainSpaceShip::gameOver() {
   cout << "aqui hay que programar que termine el juego" << endl;
}

const Sprite &MainSpaceShip::getSprite() {
    return SOwnSpaceShip;
}

void MainSpaceShip::playerShoot() {
    // CHEQUEAR SI LA NAVE TIENE ACTIVADO LOS MISILES _______________________________******


    shipCannon->shoot();

    //std::cout<< shipCannon->getBulletDamage()<<endl;
    cout << "disparo" << endl;
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

