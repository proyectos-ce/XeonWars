#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include "Background.h"
#include "MainSpaceShip.h"
#include "List.h"

#define RES nullptr

using namespace sf;


int main(){
 /*  RenderWindow window(VideoMode(1200, 800), "XeonWars");
    window.setFramerateLimit(60);
    Clock clock;

    MainSpaceShip ownSpaceShip;
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

        Time time = clock.getElapsedTime();

        window.clear();


        background.update(window, time.asMilliseconds());
        background.render(window);

        ownSpaceShip.update(window, time.asMilliseconds());
        ownSpaceShip.render(window);

        clock.restart().asMilliseconds();



        window.display();

    }

*/








    return 0;
}