//
// Created by jimena on 3/24/17.
//
#include <iostream>
#include "MainSpaceShip.h"

MainSpaceShip::MainSpaceShip() {
    TOwnSpaceShip.loadFromFile("Resources/FramesNave.png");
    TOwnSpaceShip.setSmooth(true);
    SOwnSpaceShip.setTexture(TOwnSpaceShip);
    SOwnSpaceShip.setTextureRect(IntRect(100, 0, 100, 80));
    SOwnSpaceShip.setPosition(550,720);
}


void MainSpaceShip::update(RenderWindow &window, float time) {
    if(Keyboard::isKeyPressed(Keyboard::Left)) {
        if(SOwnSpaceShip.getPosition().x >= 15) {
            SOwnSpaceShip.move(-1*time, 0);
            SOwnSpaceShip.setTextureRect(IntRect(0, 0, 95, 80));
        }
    }else{
        SOwnSpaceShip.setTextureRect(IntRect(100, 0, 100, 80));
    }
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        if(SOwnSpaceShip.getPosition().x <= 1085) {
            SOwnSpaceShip.move(1*time, 0);
            SOwnSpaceShip.setTextureRect(IntRect(200, 0, 95, 80));
        }
    }
    if(Keyboard::isKeyPressed(Keyboard::Up)){
        if(SOwnSpaceShip.getPosition().y >= 15) {
            SOwnSpaceShip.move(0, -1*time);
        }
    }
    if(Keyboard::isKeyPressed(Keyboard::Down)){
        if(SOwnSpaceShip.getPosition().y <= 705) {
            SOwnSpaceShip.move(0, 1*time);
        }
    }

}

void MainSpaceShip::render(RenderWindow &window) {
    window.draw(SOwnSpaceShip);
}