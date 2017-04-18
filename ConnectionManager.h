//
// Created by Ignacio Mora on 4/5/17.
//

#ifndef XEONWARS_CONNECTIONMANAGER_H
#define XEONWARS_CONNECTIONMANAGER_H

#include "MQTTClient.h"


class ConnectionManager {

public:
    ConnectionManager();
    void receiveMessage();

private:
    MQTTClient* gameClient;



};


#endif //XEONWARS_CONNECTIONMANAGER_H
