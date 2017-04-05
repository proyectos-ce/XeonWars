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
    backgroundMusic.openFromFile("Resources/BackgroundMusic.ogg");
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
    std::cout << running << std::endl;

    running = true;
    clock.restart().asMilliseconds();

    while (running) {
        cout << "RUN" << endl;
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
                return(0);

            if (event.type == sf::Event::Resized) {
                window.setView(Utils::calcView(sf::Vector2u(event.size.width, event.size.height), Utils::designedsize));
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                ownSpaceShip.usePowerUp();
            }

        }

        Time time = clock.getElapsedTime();

        window.clear();


        background.update(window, time.asMilliseconds());
        background.render(window);

        ownSpaceShip.update(window, time.asMilliseconds());
        ownSpaceShip.render(window);

        clock.restart().asMilliseconds();


        window.display();

    }

    return (-1);
}


