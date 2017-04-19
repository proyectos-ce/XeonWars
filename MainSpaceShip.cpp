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

    TOwnSpaceShip.loadFromFile("Resources/PlayerShip.png");
    TOwnSpaceShip.setSmooth(true);
    SOwnSpaceShip.setTexture(TOwnSpaceShip);
    effectSprite.setTexture(TOwnSpaceShip);

    //SOwnSpaceShip.setTextureRect(IntRect(100, 0, 100, 80));
    //SOwnSpaceShip.setColor(sf::Color(0,250,100,255));
    //SOwnSpaceShip.setScale(sf::Vector2f(0.8,0.8));
    SOwnSpaceShip.setPosition(550,720);
    SOwnSpaceShip.setScale(0.4,0.4);
    effectSprite.setPosition(550,720);
    effectSprite.setScale(0.4,0.4);
    updateEffect(0);


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
    shipCannon->setBulletSpeed(8);
    shipCannon->setReverseDirection(1);
    shipCannon->setBulletTextureFilename("Resources/Bullets.png");

    missileCannon = CannonFactory::createSprayCannon(10,7);
    missileCannon->setOwnerSprite(&SOwnSpaceShip);
    missileCannon->setBulletDamage(30);
    missileCannon->setBulletSpeed(-6);

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

    frameCounter++;

    if (frameCounter == 4) {
        if (blinkAnimationCounter > 0) {
            if (isWhite) {
                SOwnSpaceShip.setColor(sf::Color(255,255,255,255));
                isWhite = false;
            } else {
                SOwnSpaceShip.setColor(sf::Color(200,50,0,255));
                isWhite = true;
            }
            blinkAnimationCounter--;
        }
        frameCounter = 0;

    }



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
        //SOwnSpaceShip.setTextureRect(IntRect(200, 0, 95, 80));
        updateTexture(2);

        velocity.x -= speed/2;
    } else if (velocity.x < 0) {
        //SOwnSpaceShip.setTextureRect(IntRect(0, 0, 95, 80));
        updateTexture(0);

        velocity.x += speed/2;
    } else {
        //SOwnSpaceShip.setTextureRect(IntRect(100, 0, 100, 80));
        updateTexture(defaultTexture);
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

    //update effect sprite
    effectSprite.setPosition(SOwnSpaceShip.getPosition());

}

void MainSpaceShip::render(RenderWindow &window) {
    window.draw(effectSprite);
    window.draw(SOwnSpaceShip);

}

void MainSpaceShip::usePowerUp() {
    updateEffect(0);
    if(!powerUpsQueue.isEmpty()) {
        int powerToUse = powerUpsQueue.dequeue().getType();
        if(powerToUse == 0){
            //cout <<"Misiles"<<endl;
            setMissiles_On(true);
        }
        else if(powerToUse == 1){
            if(!shieldActivated) {
                shield();
            }
            //cout <<"Escudo"<<endl;

        }
        else if(powerToUse == 2){
            //cout <<"Laser"<<endl;
            laser_On;            
        }
    }else{
        cout <<"No hay power ups"<<endl;
        updateEffect(0);

    }
}

void MainSpaceShip::shield() {
    if(shieldActivated == false){
        setShieldActivated(true);
        shieldClock.restart();
        sound.setBuffer(shieldOnSound);
        //cout<<"Escudo activado"<<endl;
    }
    else{
        setShieldActivated(false);
        sound.setBuffer(shieldOffSound);
        //cout<<"Escudo desactivado"<<endl;

    }
    sound.play();
}

bool MainSpaceShip::gameOver() {
   cout << "aqui hay que programar que termine el juego" << endl;
}

void MainSpaceShip::doDamageAnimation() {
    if (blinkAnimationCounter == 0)
        blinkAnimationCounter = 6;
}

int MainSpaceShip::getTexturesAmount() const
{
    return texturesAmount;
}

void MainSpaceShip::setTexturesAmount(int value)
{
    texturesAmount = value;
    updateTexture(0);

}

Sprite MainSpaceShip::getEffectSprite() const
{
    return effectSprite;
}

void MainSpaceShip::setEffectSprite(const Sprite &value)
{
    effectSprite = value;
}

bool MainSpaceShip::getMissiles_On() const
{
    return missiles_On;
}

void MainSpaceShip::setMissiles_On(bool value)
{
    missiles_On = value;
    if(missiles_On){
        updateEffect(2);

    }
    else{
        updateEffect(0);
    }
}

bool MainSpaceShip::getShieldActivated() const
{
    return shieldActivated;
}

void MainSpaceShip::setShieldActivated(bool value)
{
    shieldActivated = value;
    if(shieldActivated){
        updateEffect(1);
    }
    else{
        updateEffect(0);
    }
}

void MainSpaceShip::updateTexture(int value)
{
    
    
    int rectX = (TOwnSpaceShip.getSize().x/texturesAmount), rectY = TOwnSpaceShip.getSize().y;
    SOwnSpaceShip.setTextureRect(sf::IntRect(rectX*value,0 , rectX, rectY ));
}

void MainSpaceShip::updateEffect(int value)
{
    value += 4;
    int rectX = (TOwnSpaceShip.getSize().x/texturesAmount), rectY = TOwnSpaceShip.getSize().y;
    effectSprite.setTextureRect(sf::IntRect(rectX*value,0 , rectX, rectY ));
}


void MainSpaceShip::playerShoot() {
    // CHEQUEAR SI LA NAVE TIENE ACTIVADO LOS MISILES _______________________________******
    if (missiles_On){
        if(missileShootCounter <5) {
            missileShootCounter++;
            missileCannon->shoot();
            sound.setBuffer(missileShootBuffer);
            //cout << "disparo misil" << endl;
            //updateEffect(0);

        }else{
            missiles_On= false;
            missileShootCounter=0;
            sound.setBuffer(normalShootBuffer);
            shipCannon->shoot();
            updateEffect(0);
        }
    } else if (laser_On){
        cout << "disparo laser" << endl;
    } else {

        shipCannon->shoot();
        sound.setBuffer(normalShootBuffer);
        //std::cout<< shipCannon->getBulletDamage()<<endl;
        //cout << "disparo simple" << endl;
    }
    sound.play();
}
bool MainSpaceShip::attack(int damage)
{
    std::cout<<lifeLevel<<endl;
    bool result = false;
    if(shieldActivated){
        shieldActivated=false;
        updateEffect(0);
    }
    else{
        lifeLevel-=damage;
        if(lifeLevel<=0){
            lifes-=1;
            lifeLevel=100;
            if(lifes<=0){
            result = true;
            }
        }

    }
    return result;

}

int MainSpaceShip::getLifeLevel() const
{
    return lifeLevel;
}

void MainSpaceShip::setLifeLevel(int value)
{   if(value<50){
    defaultTexture=3;
    }
    else{
        defaultTexture=1;
    }
    std::cout<<lifeLevel<<std::endl;
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
    //else()
}

int MainSpaceShip::getLifes() const {
    return lifes;
}

void MainSpaceShip::setLifes(int numLifes){
    lifes =  numLifes;
}

