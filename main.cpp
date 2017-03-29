#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include "Background.h"
#include "MainSpaceShip.h"
#include "entity.h"
#include "enemy.h"
#include "motion.h"
#include "cannon.h"
#define RES nullptr

using namespace sf;


int main(){
   RenderWindow window(VideoMode(1200, 800), "XeonWars");
    window.setFramerateLimit(30);
    Clock clock;

    MainSpaceShip ownSpaceShip;


    Texture enemyShipTexture;
    MotionFactory motionFactory;

    std::vector<Entity *> enemyList;


    CannonFactory cannonFactory;

    Motion *enemyShipMotion = motionFactory.createLinearMotion(45);

    Cannon *enemyShipCannon = cannonFactory.createSimpleCannon();
    enemyShipTexture.loadFromFile("Resources/FramesNave.png");

    /*
    enemyShipCannon->setBulletDamage(30);
    enemyShipCannon->setBulletSpeed(6);
    enemyShipCannon->setEnemyList(&enemyList);

    Enemy enemyShip1(enemyShipTexture, &enemyList);
    enemyShip1.setTexturesAmount(4);
    enemyShip1.setMotion(enemyShipMotion);
    enemyShip1.setSpeed(3);
    enemyShip1.setPosition(sf::Vector2f(300,0));
    enemyShip1.setTrigger(30);
    enemyShip1.setCannon(enemyShipCannon);
*/




    enemyShipMotion = motionFactory.createSimpleMotion();

    enemyShipCannon = cannonFactory.createSprayCannon(5,4);
    enemyShipCannon->setBulletDamage(30);
    enemyShipCannon->setBulletSpeed(6);


    Enemy enemyShip2(enemyShipTexture, &enemyList);
    enemyShip2.setTexturesAmount(4);
    enemyShip2.setMotion(enemyShipMotion);
    enemyShip2.setSpeed(3);
    enemyShip2.setPosition(sf::Vector2f(100,0));
    enemyShip2.setTrigger(20);
    enemyShip2.setCannon(enemyShipCannon);




    enemyShipMotion = motionFactory.createSimpleMotion();
    enemyShipCannon = cannonFactory.createSprayCannon(2,3);
    enemyShipCannon->setBulletDamage(30);
    enemyShipCannon->setBulletSpeed(12);

    Enemy enemyShip3(enemyShipTexture, &enemyList);
    enemyShip3.setTexturesAmount(4);
    enemyShip3.setMotion(enemyShipMotion);
    enemyShip3.setSpeed(3);
    enemyShip3.setPosition(sf::Vector2f(300,0));
    enemyShip3.setTrigger(20);
    enemyShip3.setCannon(enemyShipCannon);



/*
    enemyShipMotion = motionFactory.createSimpleMotion();

    enemyShipCannon = cannonFactory.createSimpleCannon();
    enemyShipCannon->setBulletDamage(30);
    enemyShipCannon->setBulletSpeed(6);

    enemyShipMotion = motionFactory.createSinMotion(200);
    Enemy enemyShip4(enemyShipTexture, &enemyList);
    enemyShip4.setTexturesAmount(4);
    enemyShip4.setMotion(enemyShipMotion);
    enemyShip4.setSpeed(3);
    enemyShip4.setPosition(sf::Vector2f(700,200));
    enemyShip4.setTrigger(10);
    enemyShip4.setCannon(enemyShipCannon);

*/


    Background background;
    Music backgroundMusic;

    backgroundMusic.openFromFile("Resources/BackgroundMusic.ogg");
    backgroundMusic.setLoop(true);
    backgroundMusic.play();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape){
                window.close();
            }
        }


        window.clear();

        Time time = clock.getElapsedTime();
        background.update(window, time.asMilliseconds());
        background.render(window);
        ownSpaceShip.update(window, time.asMilliseconds());
        ownSpaceShip.render(window);

        for (int i = 0; i < enemyList.size(); ++i) {
            enemyList[i]->update(window, time.asMilliseconds());
            enemyList[i]->render(window);

        }
        //std::cout<<enemyList.size()<<std::endl;
        clock.restart().asMilliseconds();


        window.display();

    }




    return 0;
}
