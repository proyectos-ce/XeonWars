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
    //MotionFactory motionFactory;

    std::vector<Enemy *> enemyList;
    std::vector<Bullet *> enemyBulletList;
    std::vector<Bullet *> playerbulletList;

    ownSpaceShip.setbulletList(&playerbulletList);

    Motion *enemyShipMotion = MotionFactory::createLinearMotion(45);
    Cannon *enemyShipCannon = CannonFactory::createSimpleCannon();
    enemyShipTexture.loadFromFile("Resources/MissileTower.png");
    //enemyShipTexture.loadFromFile("Resources/enemy2.png");

    CollisionManager collisionManager;
    collisionManager.setEnemyList(&enemyList);
    collisionManager.setPlayerShip(&ownSpaceShip);
    collisionManager.setPlayerBulletList(&playerbulletList);
    collisionManager.setEnemyBulletList(&enemyBulletList);


    //enemyShipMotion = motionFactory.createSimpleMotion();


    Enemy *enemyShip2= new Enemy(enemyShipTexture, &enemyList, &enemyBulletList);
    enemyShipMotion = MotionFactory::createSimpleMotion();
    //enemyShipMotion = MotionFactory::createFollowerMotion(enemyShip2->getSpriteReference(), ownSpaceShip.getSpriteReference());
    //enemyShipMotion->setReverseDirection(true);
    enemyShip2->setTexturesAmount(4);
    enemyShip2->setMotion(enemyShipMotion);
    enemyShip2->setSpeed(2);
    enemyShip2->setPosition(sf::Vector2f(100,0));
    enemyShip2->setTrigger(20);

    enemyShipCannon = CannonFactory::createFollowerCannon(enemyShip2->getSpriteReference(),ownSpaceShip.getSpriteReference());
    enemyShipCannon->setBulletDamage(30);
    enemyShipCannon->setBulletSpeed(2);
    enemyShip2->setCannon(enemyShipCannon);

    enemyShip2->setScale(0.5);




    enemyShipMotion = MotionFactory::createSimpleMotion();
    enemyShipCannon = CannonFactory::createSprayCannon(2,3);
    enemyShipCannon->setBulletDamage(30);
    enemyShipCannon->setBulletSpeed(3);
    enemyShipTexture.loadFromFile("Resources/MissileTower.png");
    Enemy *enemyShip;
    for (int i = 0; i < 5; ++i) {
        enemyShipMotion = MotionFactory::createSimpleMotion();
        enemyShipCannon = CannonFactory::createSimpleCannon();
        enemyShipCannon->setBulletDamage(30);
        enemyShipCannon->setBulletSpeed(5);

        enemyShip = new Enemy(enemyShipTexture, &enemyList, &enemyBulletList);
        enemyShip->setTexturesAmount(4);
        enemyShip->updateTexture(i%4);
        enemyShip->setMotion(enemyShipMotion);
        enemyShip->setSpeed(1);
        enemyShip->setPosition(sf::Vector2f(300*i,0));
        enemyShip->setTrigger(60);
        enemyShip->setCannon(enemyShipCannon);
        enemyShip->setScale(0.7);
    }




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



        for (int i = 0; i < enemyBulletList.size(); ++i) {
            enemyBulletList[i]->update(window, time.asMilliseconds());
            enemyBulletList[i]->render(window);
            if( enemyBulletList[i]->getPosition().y >= 3000 | enemyBulletList[i]->getPosition().x >= 2000 | enemyBulletList[i]->getPosition().x <= -500){
                delete enemyBulletList.operator[](i);
                enemyBulletList.erase(enemyBulletList.begin()+i);
                //delete toDelete;

            }
            //std::cout<<enemyList[i]->getType()<<std::endl;

        }

        for (int i = 0; i < enemyList.size(); ++i) {
            enemyList[i]->update(window, time.asMilliseconds());
            enemyList[i]->render(window);
            if( enemyList[i]->getPosition().y >= 3000 | enemyList[i]->getPosition().x >= 2000 | enemyList[i]->getPosition().x <= -500){
                delete enemyList.operator[](i);
                enemyList.erase(enemyList.begin()+i);

            }
            //std::cout<<enemyList[i]->getType()<<std::endl;

        }


        for (int i = 0; i < playerbulletList.size(); ++i) {
            playerbulletList[i]->update(window, time.asMilliseconds());
            playerbulletList[i]->render(window);
            if( (playerbulletList[i]->getPosition().y) <= -1000| playerbulletList[i]->getPosition().x >= 2000 | playerbulletList[i]->getPosition().x <= -500){
                delete playerbulletList.operator[](i);
                playerbulletList.erase(playerbulletList.begin()+i);
                //delete toDelete;
                //playerbulletList.clear();
            }
            //std::cout<<enemyList[i]->getType()<<std::endl;

        }
        ownSpaceShip.update(window, time.asMilliseconds());
        ownSpaceShip.render(window);

        collisionManager.checkCollisions();

        clock.restart().asMilliseconds();


        window.display();

    }

    return (-1);
}


