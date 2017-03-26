//
// Created by jimena on 3/24/17.
//
#include <iostream>
#include "MainSpaceShip.h"

MainSpaceShip::MainSpaceShip() {
    TOwnSpaceShip.loadFromFile("Resources/FramesNave.png");
    SOwnSpaceShip.setTexture(TOwnSpaceShip);
    SOwnSpaceShip.setTextureRect(IntRect(100, 0, 100, 80));
    SOwnSpaceShip.setPosition(550,720);
}

void MainSpaceShip::update(RenderWindow &window, float time) {

    if(Keyboard::isKeyPressed(Keyboard::Left)){
        SOwnSpaceShip.move(-0.5*time, 0);
        SOwnSpaceShip.setTextureRect(IntRect(0,0,95,80));
    }
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        SOwnSpaceShip.move(0.5*time, 0);
        SOwnSpaceShip.setTextureRect(IntRect(200,0,95, 80));
    }
    if(Keyboard::isKeyPressed(Keyboard::Up)){
        SOwnSpaceShip.move(0, -0.5*time);
    }
    if(Keyboard::isKeyPressed(Keyboard::Down)){
        SOwnSpaceShip.move(0, 0.5*time);
    }
}

void MainSpaceShip::render(RenderWindow &window) {
    window.draw(SOwnSpaceShip);
}
