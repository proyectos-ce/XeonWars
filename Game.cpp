//
// Created by jimena on 3/25/17.
//
#include "Game.h"
Game::Game() {
    cout<<"Juego Creado"<<endl;
}
void Game::run(RenderWindow &window) {
    backgroundMusic.openFromFile("Resources/BackgroundMusic.ogg");
    backgroundMusic.setLoop(true);
    backgroundMusic.play();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
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
}


