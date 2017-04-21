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

void Game::updateAll(RenderWindow &window)
{
   background.update(window, time.asMilliseconds());
   background.render(window);

    for (int i = 0; i < enemyBulletList.size(); ++i) {
        enemyBulletList[i]->update(window, time.asMilliseconds());
        enemyBulletList[i]->render(window);
        if( enemyBulletList[i]->getPosition().y >= 3000 | enemyBulletList[i]->getPosition().x >= 2000 | enemyBulletList[i]->getPosition().x <= -500){
            delete enemyBulletList.operator[](i);
            enemyBulletList.erase(enemyBulletList.begin()+i);
            i--;
        }

    }

    for (int i = 0; i < enemyList.size(); ++i) {
        enemyList[i]->update(window, time.asMilliseconds());
        enemyList[i]->render(window);
        if( enemyList[i]->getPosition().y >= 3000 | enemyList[i]->getPosition().x >= 2000 | enemyList[i]->getPosition().x <= -500){
            delete enemyList.operator[](i);
            enemyList.erase(enemyList.begin()+i);
            i--;

        }
    }

    for (int i = 0; i < playerbulletList.size(); ++i) {
        playerbulletList[i]->update(window, time.asMilliseconds());
        playerbulletList[i]->render(window);
        if( playerbulletList[i]->getPosition().y <= 0 | playerbulletList[i]->getPosition().x >= 2000 | playerbulletList[i]->getPosition().x <= -500){
            delete playerbulletList.operator[](i);
            playerbulletList.erase(playerbulletList.begin()+i);
            i--;

        }
    }

    ownSpaceShip.update(window, time.asMilliseconds());
    ownSpaceShip.render(window);




}

void Game::eraseAll()
{
    for (int i = 0; i < enemyBulletList.size(); ++i) {
            delete enemyBulletList.operator[](i);
            //enemyBulletList.erase(enemyBulletList.begin()+i);
    }
    enemyBulletList.clear();

    for (int i = 0; i < enemyList.size(); ++i) {
            delete enemyList.operator[](i);
            //enemyList.erase(enemyList.begin()+i);

    }
    enemyList.clear();

    for (int i = 0; i < playerbulletList.size(); ++i) {
            delete playerbulletList.operator[](i);
            //playerbulletList.erase(playerbulletList.begin()+i);

    }
    playerbulletList.clear();
}



int Game::run(RenderWindow &window, Texture &tex) {

    Texture enemyShipTexture;
    ownSpaceShip.setbulletList(&playerbulletList);
    Motion *enemyShipMotion = MotionFactory::createLinearMotion(45);
    Cannon *enemyShipCannon = CannonFactory::createSimpleCannon();
    //enemyShipTexture.loadFromFile("Resources/MissileTower.png");
    enemyShipTexture.loadFromFile("Resources/Boss1.png");

    CollisionManager collisionManager;
    collisionManager.setEnemyList(&enemyList);
    collisionManager.setPlayerShip(&ownSpaceShip);
    collisionManager.setPlayerBulletList(&playerbulletList);
    collisionManager.setEnemyBulletList(&enemyBulletList);


    //enemyShipMotion = motionFactory.createSimpleMotion();


    Enemy *enemyShip2= new Enemy(enemyShipTexture, &enemyList, &enemyBulletList);
    enemyShipMotion = MotionFactory::createSimpleMotion();
    enemyShip2->setTexturesAmount(1);
    enemyShip2->setMotion(enemyShipMotion);
    enemyShip2->setSpeed(0);

    enemyShip2->setPosition(sf::Vector2f(500,0));
    enemyShip2->setTrigger(80);

    enemyShipCannon = CannonFactory::createFollowerCannon(enemyShip2->getSpriteReference(),ownSpaceShip.getSpriteReference());
    enemyShipCannon->setBulletDamage(3);
    enemyShipCannon->setBulletSpeed(3);
    enemyShipCannon->setBulletTextureFilename("Resources/FollowerBullet.png");
    enemyShip2->setCannon(enemyShipCannon);


    enemyShip2->setScale(0.3);





    enemyShipMotion = MotionFactory::createSimpleMotion();
    enemyShipCannon = CannonFactory::createSprayCannon(2,3);
    enemyShipCannon->setBulletDamage(30);
    enemyShipCannon->setBulletSpeed(3);
    enemyShipTexture.loadFromFile("Resources/MissileTower.png");
    Enemy *enemyShip;
    for (int i = 0; i < 3; ++i) {
        enemyShipMotion = MotionFactory::createSimpleMotion();
        enemyShipCannon = CannonFactory::createSimpleCannon();
        enemyShipCannon->setBulletDamage(10);
        enemyShipCannon->setBulletSpeed(5);

        enemyShip = new Enemy(enemyShipTexture, &enemyList, &enemyBulletList);
        enemyShip->setTexturesAmount(4);
        enemyShip->updateTexture(i%4);
        enemyShip->setMotion(enemyShipMotion);
        enemyShip->setSpeed(1);
        enemyShip->setPosition(sf::Vector2f(300*i,0));
        enemyShip->setTrigger(60);
        enemyShip->setCannon(enemyShipCannon);
        enemyShip->setScale(0.2);
    }




    backgroundMusic.openFromFile("Resources/music2.ogg");
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
                eraseAll();
                return(3);
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                sf::Image img = window.capture();
                tex.loadFromImage(img);
                eraseAll();
                return (3);


            }

            if (event.type == sf::Event::Resized) {
                window.setView(Utils::calcView(sf::Vector2u(event.size.width, event.size.height), Utils::designedsize));
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::X) {
                ownSpaceShip.usePowerUp();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Z) {
                if(shootClock.getElapsedTime().asMilliseconds()>150){

                ownSpaceShip.playerShoot();

                shootClock.restart().asMilliseconds();
                }
            }

        }

       time = clock.getElapsedTime();
//        ownSpaceShip.score.scoreRender(window);
//        ownSpaceShip.score.add_score(1);


        window.clear();





        updateAll(window);
        if(collisionManager.checkCollisions()){
            return 2;
        }


        clock.restart().asMilliseconds();

        score.BossTimeCheck();

        if(score.isBossTime()){
            if(score.getcreateBoss()){
                backgroundMusic.stop();
                bossMusic.openFromFile("Resources/BackgroundMusic.ogg");
                bossMusic.setLoop(true);
                bossMusic.play();

                cout << "viene el boss" << endl;
                Boss.BossInit(score.getLevel(),&enemyList,&enemyBulletList);
                score.createbossOff();
            }
            Boss.life_refresh();
            Boss.lifeRender(window);
            if(Boss.isdead()){
                score.add_score(1000);
                bossMusic.stop();
                backgroundMusic.play();
                score.BossTime=false;
                cout << "boss ha muerto"<<endl;
                score.nextlevelReached();
                cout << "ahora esta en el nivel: "<< score.getLevel()<< endl;
                cout << "proximo boss al score de: "<< score.nextBoss_score;
            }
        }

        score.scoreRender(window);
        if(scoreClock.getElapsedTime().asMilliseconds()>500) {
            score.add_score(1);
            scoreClock.restart().asMilliseconds();
        }

        if (score.checklifes %1000 >=1){
            score.checklifes =0;
            ownSpaceShip.addlife();
        }

        window.display();

    }
    eraseAll();
    return (-1);
}


