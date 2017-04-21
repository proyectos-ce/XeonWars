//
// Created by jimena on 3/25/17.
//
#include "Game.h"



#include "Utils.h"
#include "ConnectionManager.h"

Game::Game() {
    cout<<"Juego Creado"<<endl;
    ownSpaceShip.setbulletList(&playerbulletList);

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

    Game* caca = this;
    ConnectionManager* myConnectionManager = new ConnectionManager(caca);


    CollisionManager collisionManager;
    collisionManager.setEnemyList(&enemyList);
    collisionManager.setPlayerShip(&ownSpaceShip);
    collisionManager.setPlayerBulletList(&playerbulletList);
    collisionManager.setEnemyBulletList(&enemyBulletList);



    Enemy *newEnemy;
    newEnemy = EnemyFactory::createJet(2,&enemyList,&enemyBulletList);
    newEnemy->setCenterPosition(sf::Vector2f(100,-100));

    newEnemy = EnemyFactory::createBomber(2,&enemyList,&enemyBulletList);
    newEnemy->setCenterPosition(sf::Vector2f(200*2,-100));

    newEnemy = EnemyFactory::createTower(2,&enemyList,&enemyBulletList, 2);
    newEnemy->setCenterPosition(sf::Vector2f(200*3,-100));

    newEnemy = EnemyFactory::createMissileTower(2,&enemyList,&enemyBulletList, ownSpaceShip.getSpriteReference(),2);
    newEnemy->setCenterPosition(sf::Vector2f(200*4,-100));

    newEnemy = EnemyFactory::createKamikaze(2,&enemyList,&enemyBulletList, ownSpaceShip.getSpriteReference());
    newEnemy->setCenterPosition(sf::Vector2f(200*5,-100));





    backgroundMusic.openFromFile("Resources/music2.ogg");
    backgroundMusic.setLoop(true);
    //backgroundMusic.play();
    std::cout << running << std::endl;

    running = true;
    clock.restart().asMilliseconds();

    while (running) {

        // Modifica el vector segun las teclas presionadas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || phoneDirection==UP)
            ownSpaceShip.setDirectionUp();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || phoneDirection==DOWN)
            ownSpaceShip.setDirectionDown();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || phoneDirection==LEFT)
            ownSpaceShip.setDirectionLeft();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || phoneDirection==RIGHT)
            ownSpaceShip.setDirectionRight();

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

        ownSpaceShip.score.BossTimeCheck();

        if(ownSpaceShip.score.isBossTime()){
            if(ownSpaceShip.score.getcreateBoss()){
                cout << "viene el boss" << endl;
                ownSpaceShip.score.setBossOn();
                ownSpaceShip.score.createbossOff();
            }
            ownSpaceShip.score.Boss.lifeRender(window);
            if(ownSpaceShip.score.Boss.isdead()){
                ownSpaceShip.score.BossTime=false;
                ownSpaceShip.score.nextlevelReached();
            }
        }

        ownSpaceShip.score.scoreRender(window);
        if(scoreClock.getElapsedTime().asMilliseconds()>500) {
            ownSpaceShip.score.add_score(1);
            scoreClock.restart().asMilliseconds();
        }

        window.display();

    }
    eraseAll();
    return (-1);
}

void Game::setPhoneDirection(string direction) {
    if(direction.compare("L") == 0){
        phoneDirection = LEFT;
    }
    else if(direction.compare("R") ==0){
        phoneDirection = RIGHT;
    }
    else if(direction.compare("U") ==0){
        phoneDirection = UP;
    }
    else if(direction.compare("D") ==0){
        phoneDirection = DOWN;
    }
    else if(direction.compare("C") ==0){
        phoneDirection = CENTER;
    }
}


