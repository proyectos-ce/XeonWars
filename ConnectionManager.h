//
// Created by Ignacio Mora on 4/5/17.
//

#ifndef XEONWARS_CONNECTIONMANAGER_H
#define XEONWARS_CONNECTIONMANAGER_H

#include <mosquitto.h>

#include <signal.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Game.h"


#define QOS 2
#define mqtt_host "localhost"
#define mqtt_port 1883


class ConnectionManager {

public:
    ConnectionManager(Game* gamecito);
    static Game* mainGame;
    static void setPhoneDirection(string);
private:


};


#endif //XEONWARS_CONNECTIONMANAGER_H
