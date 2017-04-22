//
// Created by jimena on 3/25/17.
//
#include "Game.h"



#include "Utils.h"
#include "ConnectionManager.h"
#include "memory.h"

Game::Game() {
    cout<<"Juego Creado"<<endl;
    ownSpaceShip.setbulletList(&playerbulletList);
    backgroundMusic.openFromFile("Resources/music2.ogg");
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(60);
    bossMusic.openFromFile("Resources/boss.ogg");
    bossMusic.setLoop(true);
    //backgroundMusic.play();
    collisionManager.setEnemyList(&enemyList);
    collisionManager.setPlayerShip(&ownSpaceShip);
    collisionManager.setPlayerBulletList(&playerbulletList);
    collisionManager.setEnemyBulletList(&enemyBulletList);
    enemyReader.setPlayerSprite(ownSpaceShip.getSpriteReference());
    levelflag=false;
    gameClock.restart().asSeconds();


}

void Game::pauseGame() {
    running = false;
    std::cout << running << std::endl;
}

void Game::restartGame() {
    eraseAll();
    gameClock.restart().asSeconds();
    backgroundMusic.stop();
    score.resetScore();

}

void Game::updateAll(RenderWindow &window, Options* gameOptions)
{

   background.update(window, time.asMilliseconds());
   background.render(window);
    backstars.update(window,time.asMilliseconds());
    backstars.render(window);
    backasteroids.update(window, time.asMilliseconds());
    backasteroids.render(window);


    for (int i = 0; i < enemyBulletList.size(); ++i) {
        enemyBulletList[i]->update(window, time.asMilliseconds());
        enemyBulletList[i]->render(window);
        if( enemyBulletList[i]->getPosition().y >= 900 | enemyBulletList[i]->getPosition().x >= 2000 | enemyBulletList[i]->getPosition().x <= -500){
            delete enemyBulletList.operator[](i);
            enemyBulletList.erase(enemyBulletList.begin()+i);
            i--;
        }

    }

    for (int i = 0; i < enemyList.size(); ++i) {
        enemyList[i]->update(window, time.asMilliseconds());
        enemyList[i]->render(window);
        if( enemyList[i]->getPosition().y >= 900 | enemyList[i]->getPosition().x >= 2000 | enemyList[i]->getPosition().x <= -500){
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



    stats.setString("Memoria: " + std::to_string(getCurrentRSS() / 1024 /1024) + "MB \nTiempo: " + std::to_string((int) floor(gameClock.getElapsedTime().asSeconds())) + " S");

    if (gameOptions->showStats) {
        window.draw(stats);
    }



}

void Game::loadEnemies()
{
    if(!score.BossTime && enemyList.size()<minEnemyQuantity){
    std::vector<Enemy *> newEnemySet = enemyReader.getNextEnemySet();
    for (int i = 0; i < newEnemySet.size(); ++i) {
        newEnemySet[i]->setBulletList(&enemyBulletList);
        enemyList.push_back(newEnemySet[i]);
    }
    }
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



int Game::run(RenderWindow &window, Texture &tex, Options* gameOptions) {

    if (score.isBossTime()) {
        bossMusic.play();
    } else {
        backgroundMusic.play();
    }

    sf::Font classicFont;

    if (!classicFont.loadFromFile("Resources/menu/8bit.ttf"))
    {
        std::cerr << "Error loading 8bit.ttf" << std::endl;
        return (-1);
    }

    stats.setFont(classicFont);
    stats.setCharacterSize(20);
    stats.setColor(sf::Color::White);
    stats.setPosition(25, 55 );


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
                backgroundMusic.stop();
                bossMusic.stop();
                return(3);
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                sf::Image img = window.capture();
                tex.loadFromImage(img);
                //eraseAll();
                backgroundMusic.pause();
                bossMusic.pause();
                return (3);

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





        updateAll(window, gameOptions);
        if(collisionManager.checkCollisions()){
            return 2;
        }
        //update score         collisionManager.getLastScore();
        score.add_score(collisionManager.getLastScore());
        loadEnemies();
        //score.add_score(100);







        clock.restart().asMilliseconds();

        score.BossTimeCheck();

        if(score.isBossTime()) {
            if (score.getcreateBoss()) {
                backgroundMusic.stop();
                bossMusic.play();

                cout << "viene el boss" << endl;
                Boss.BossInit(score.getLevel(), &enemyList, &enemyBulletList);
                score.createbossOff();
            }
            Boss.life_refresh();
            Boss.lifeRender(window);
            if (Boss.isdead()) {
                score.add_score(1000);
                bossMusic.stop();
                backgroundMusic.play();
                score.BossTime = false;
                cout << "boss ha muerto" << endl;
                score.nextlevelReached();
                cout << "ahora esta en el nivel: " << score.getLevel() << endl;
                cout << "proximo boss al score de: " << score.nextBoss_score;

                levelupClock.restart();
                if (!levelflag) levelflag = true;
            }
        }
        if (  levelupClock.getElapsedTime().asSeconds()<=2){
            if (levelflag and (int)levelupClock.getElapsedTime().asMilliseconds() % 2 ==0){
                score.show_levelup(window);
            }
        }

        score.scoreRender(window);
        if(scoreClock.getElapsedTime().asMilliseconds()>500) {
            score.add_score(1);
            scoreClock.restart().asMilliseconds();
        }

        if (score.checklifes >=5000){
            score.checklifes =0;
            ownSpaceShip.addlife();
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


