//
// Created by danielc on 25/03/17.
//
#include <SFML/Audio.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include "BulletClass.h"
    Bullet::Bullet(sf::Vector2f size) {
           sf::Texture shoot;
           shoot.loadFromFile("Resources/laserGreen.png");
       // bullet.setSize(size);
        //bullet.setFillColor(sf::Color::Blue);
    }
    void Bullet::fire (int speed){
        bullet.move(0,-speed);
    }
//    int get_Right(){
//        return bullet.getPosition().x + bullet.getSize().x;
//    }
//    int get_Left(){
//        return bullet.getPosition().x;
//    }
//    int get_Top(){
//        return bullet.getPosition().y;
//    }
//    int get_Bottom(){
//        return bullet.getPosition().y + bullet.getSize().y;
//    }
    void Bullet::draw (sf::RenderWindow &window){
        window.draw(bullet);
    }
    void Bullet::setPos(sf::Vector2f newPos){
        bullet.setPosition(newPos);
    }
