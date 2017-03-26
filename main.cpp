#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include "Background.h"
#include "MainSpaceShip.h"
#include "enemy.h"
#include "motion.h"
#include "motiongenerator.h"
#define RES nullptr

using namespace sf;


int main(){
   RenderWindow window(VideoMode(1200, 800), "XeonWars");
    window.setFramerateLimit(30);
    Clock clock;

    MainSpaceShip ownSpaceShip;


    Texture enemyShipTexture;
    MotionGenerator motionGenerator;

    std::vector<Enemy *> enemyList;



    Motion *enemyShipMotion = motionGenerator.createLinearMotion(45);
    enemyShipTexture.loadFromFile("Resources/FramesNave.png");
    Enemy enemyShip1(enemyShipTexture, &enemyList);
    enemyShip1.setTexturesAmount(4);
    enemyShip1.setMotion(enemyShipMotion);
    enemyShip1.setSpeed(3);
    enemyShip1.setPosition(300,0);
    enemyShip1.setTrigger(30);

    enemyShipMotion = motionGenerator.createSimpleMotion();
    Enemy enemyShip2(enemyShipTexture, &enemyList);
    enemyShip2.setTexturesAmount(4);
    enemyShip2.setMotion(enemyShipMotion);
    enemyShip2.setSpeed(3);
    enemyShip2.setPosition(100,0);
    enemyShip2.setTrigger(20);


    enemyShipMotion = motionGenerator.createSinMotion(200);
    Enemy enemyShip3(enemyShipTexture, &enemyList);
    enemyShip3.setTexturesAmount(4);
    enemyShip3.setMotion(enemyShipMotion);
    enemyShip3.setSpeed(3);
    enemyShip3.setPosition(700,200);
    enemyShip3.setTrigger(10);



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
           /*
        enemyShip1.update(window, time.asMilliseconds());
        enemyShip1.render(window);

        enemyShip2.update(window, time.asMilliseconds());
        enemyShip2.render(window);

        enemyShip3.update(window, time.asMilliseconds());
        enemyShip3.render(window);
        */
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
