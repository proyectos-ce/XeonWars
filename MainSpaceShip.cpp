//
// Created by jimena on 3/24/17.
//
#include <iostream>
#include "MainSpaceShip.h"

MainSpaceShip::MainSpaceShip() {
    lifes = 3;
    scoreForLifes = 0;
    globalScore = 0;

    TOwnSpaceShip.loadFromFile("Resources/FramesNave.png");
    TOwnSpaceShip.setSmooth(true);
    SOwnSpaceShip.setTexture(TOwnSpaceShip);
    SOwnSpaceShip.setTextureRect(IntRect(100, 0, 100, 80));
    SOwnSpaceShip.setPosition(550,720);
}


void MainSpaceShip::update(RenderWindow &window, float time) {

    bool anyKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

    // Si no hay ninguna tecla presionada la velocidad se pone en 0 si es muy pequeña
    if (!anyKeyPressed) {
        if (abs(velocity.y) <= speed/2)
            velocity.y = 0;

        if (abs(velocity.x) <= speed/2)
            velocity.x = 0;
    }

    // Modifica el vector segun las teclas presionadas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        velocity.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        velocity.y += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity.x += speed;


    // Air friction
    if (velocity.y > 0)
        velocity.y -= speed/2;
    else if (velocity.y < 0)
        velocity.y += speed/2;

    if (velocity.x > 0) {
        SOwnSpaceShip.setTextureRect(IntRect(200, 0, 95, 80));
        velocity.x -= speed/2;
    } else if (velocity.x < 0) {
        SOwnSpaceShip.setTextureRect(IntRect(0, 0, 95, 80));
        velocity.x += speed/2;
    } else {
        SOwnSpaceShip.setTextureRect(IntRect(100, 0, 100, 80));
    }

    // Maximum speed

    if (abs(velocity.x) > maxSpeed)
        if (velocity.x > 0)
            velocity.x = maxSpeed;
        else
            velocity.x = -maxSpeed;
    if (abs(velocity.y) > maxSpeed)
        if (velocity.y > 0)
            velocity.y = maxSpeed;
        else
            velocity.y = -maxSpeed;


    
    // Limites de la pantalla

    if(SOwnSpaceShip.getPosition().x < 0) {
        velocity.x = 0;
        SOwnSpaceShip.setPosition(0, SOwnSpaceShip.getPosition().y);
    }

    if(SOwnSpaceShip.getPosition().y < 0) {
        velocity.y = 0;
        SOwnSpaceShip.setPosition(SOwnSpaceShip.getPosition().x, 0);
    }

    if (SOwnSpaceShip.getPosition().x > window.getSize().x - SOwnSpaceShip.getGlobalBounds().width) {
        velocity.x = 0;
        SOwnSpaceShip.setPosition(window.getSize().x - SOwnSpaceShip.getGlobalBounds().width,  SOwnSpaceShip.getPosition().y);
    }

    if (SOwnSpaceShip.getPosition().y > window.getSize().y - SOwnSpaceShip.getGlobalBounds().height) {
        velocity.y = 0;
        SOwnSpaceShip.setPosition(SOwnSpaceShip.getPosition().x, window.getSize().y - SOwnSpaceShip.getGlobalBounds().height);
    }

    SOwnSpaceShip.move(velocity * (time/30));


}

void MainSpaceShip::render(RenderWindow &window) {
    window.draw(SOwnSpaceShip);
}

bool MainSpaceShip::gameOver() {
    bool result = false;
    if(lifes <=0){
        result = true;
    }
    return result;
}