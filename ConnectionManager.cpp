//
// Created by Ignacio Mora on 4/5/17.
//

#include <cstdlib>
#include <iostream>
#include <zconf.h>
#include "ConnectionManager.h"


#include <mosquitto.h>


Game* ConnectionManager::mainGame;

void connect_callback(struct mosquitto *mosq, void *obj, int result)
{
    printf("connect callback, rc=%d\n", result);
}

void message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message)
{

    string dir ((char*)message->payload);
    ConnectionManager::setPhoneDirection(dir);
}


void ConnectionManager::setPhoneDirection(string direction){
    ConnectionManager::mainGame->setPhoneDirection(direction);
}




ConnectionManager::ConnectionManager(Game *gamecito) {
    ConnectionManager::mainGame = gamecito;

    struct mosquitto *mosq;

    mosquitto_lib_init();

    char clientid[9] = "XeonWars";

    memset(clientid, 0, 24);
    snprintf(clientid, 23, "mysql_log_%d", getpid());
    mosq = mosquitto_new(clientid, true, 0);

    if(mosq) {
        mosquitto_connect_callback_set(mosq, connect_callback);
        mosquitto_message_callback_set(mosq, message_callback);

        mosquitto_connect(mosq, mqtt_host, mqtt_port, 60);

        mosquitto_subscribe(mosq, NULL, "/XeonDataFrom/Phone", 0);

        mosquitto_loop_start(mosq);
    }
}
