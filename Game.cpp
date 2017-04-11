//
// Created by jimena on 3/25/17.
//
#include "Game.h"



#include "Utils.h"

Game::Game() {
    cout<<"Juego Creado"<<endl;
}

void Game::pauseGame() {
    running = false;
    std::cout << running << std::endl;
}
int Game::run(RenderWindow &window, Texture &tex) {



    Texture enemyShipTexture;
    MotionFactory motionFactory;

    std::vector<Enemy *> enemyList;
    std::vector<Bullet *> enemyBulletList;
    std::vector<Bullet *> playerbulletList;

    ownSpaceShip.setbulletList(&playerbulletList);


    CannonFactory cannonFactory;

    Motion *enemyShipMotion = motionFactory.createLinearMotion(45);

    Cannon *enemyShipCannon = cannonFactory.createSimpleCannon();
    enemyShipTexture.loadFromFile("Resources/FramesNave.png");


    CollisionManager collisionManager;
   // collisionManager.setEnemyList(&enemyList);
    //collisionManager.setPlayerShip(&ownSpaceShip);
    //collisionManager.setPlayerBulletList(&playerbulletList);

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


    Enemy enemyShip2(enemyShipTexture, &enemyList, &enemyBulletList);
    enemyShip2.setTexturesAmount(4);
    enemyShip2.setMotion(enemyShipMotion);
    enemyShip2.setSpeed(3);
    enemyShip2.setPosition(sf::Vector2f(100,0));
    enemyShip2.setTrigger(20);
    enemyShip2.setCannon(enemyShipCannon);




    enemyShipMotion = motionFactory.createSimpleMotion();
    enemyShipCannon = cannonFactory.createSprayCannon(2,3);
    enemyShipCannon->setBulletDamage(30);
    enemyShipCannon->setBulletSpeed(3);

    Enemy enemyShip3(enemyShipTexture, &enemyList, &enemyBulletList);
    enemyShip3.setTexturesAmount(4);
    enemyShip3.setMotion(enemyShipMotion);
    enemyShip3.setSpeed(2);
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


    backgroundMusic.openFromFile("Resources/BackgroundMusic.ogg");
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
    std::cout << running << std::endl;

    running = true;
    clock.restart().asMilliseconds();

    while (running) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
            {
                sf::Image img = window.capture();
                tex.loadFromImage(img);
                return(0);
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                sf::Image img = window.capture();
                tex.loadFromImage(img);
                return (0);

            }

            if (event.type == sf::Event::Resized) {
                window.setView(Utils::calcView(sf::Vector2u(event.size.width, event.size.height), Utils::designedsize));
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::X) {
                ownSpaceShip.usePowerUp();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Z) {
                ownSpaceShip.playerShoot();
            }

        }

        Time time = clock.getElapsedTime();

        window.clear();


        background.update(window, time.asMilliseconds());
        background.render(window);

        ownSpaceShip.update(window, time.asMilliseconds());
        ownSpaceShip.render(window);

        for (int i = 0; i < enemyList.size(); ++i) {
            enemyList[i]->update(window, time.asMilliseconds());
            enemyList[i]->render(window);
            if( enemyList[i]->getPosition().y >= 3000 | enemyList[i]->getPosition().x >= 2000 | enemyList[i]->getPosition().x <= -500){
                Entity *toDelete = (enemyList.operator[](i));
                enemyList.erase(enemyList.begin()+i);
                delete toDelete;

            }
            //std::cout<<enemyList[i]->getType()<<std::endl;

        }
        for (int i = 0; i < enemyBulletList.size(); ++i) {
            enemyBulletList[i]->update(window, time.asMilliseconds());
            enemyBulletList[i]->render(window);
            if( enemyBulletList[i]->getPosition().y >= 3000 | enemyBulletList[i]->getPosition().x >= 2000 | enemyBulletList[i]->getPosition().x <= -500){
                Entity *toDelete = (enemyBulletList.operator[](i));
                enemyBulletList.erase(enemyBulletList.begin()+i);
                delete toDelete;

            }
            //std::cout<<enemyList[i]->getType()<<std::endl;

        }

        for (int i = 0; i < playerbulletList.size(); ++i) {
            playerbulletList[i]->update(window, time.asMilliseconds());
            playerbulletList[i]->render(window);
            if( (playerbulletList[i]->getPosition().y) <= -1000| playerbulletList[i]->getPosition().x >= 2000 | playerbulletList[i]->getPosition().x <= -500){
                Entity *toDelete = (playerbulletList.operator[](i));
                playerbulletList.erase(playerbulletList.begin()+i);
               delete toDelete;
                playerbulletList.clear();
            }
            //std::cout<<enemyList[i]->getType()<<std::endl;

        }
       // collisionManager.checkCollisions();

        clock.restart().asMilliseconds();


        window.display();

    }

    return (-1);
}


