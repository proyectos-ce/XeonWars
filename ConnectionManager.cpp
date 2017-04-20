//
// Created by Ignacio Mora on 4/5/17.
//

#include <cstdlib>
#include <iostream>
#include "ConnectionManager.h"
#define CLIENTID "XeonWars"
#define QOS 2

//ConnectionManager* ConnectionManager::getInstance() {
//    if (instance == NULL){
//        instance = new ConnectionManager;
//    }
//    return instance;

//}

void ConnectionManager::receiveMessage() {

}

volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt)
{
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    int i;
    char* payloadptr;

    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");

    payloadptr = (char*) message->payload;
    for(i=0; i<message->payloadlen; i++)
    {
        putchar(*payloadptr++);
    }
    putchar('\n');
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

ConnectionManager::ConnectionManager() {

    gameClient = new MQTTClient();
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;
    int ch;

    MQTTClient_create(gameClient, "tcp://iot.eclipse.org:1883", CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    MQTTClient_setCallbacks(gameClient, NULL, connlost, msgarrvd, delivered);

    if ((rc = MQTTClient_connect(gameClient, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }
    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n Press Q<Enter> to quit\n\n", "/XeonDataFrom/Phone", CLIENTID, QOS);
    MQTTClient_subscribe(gameClient, "/XeonDataFrom/Phone", QOS);

    do
    {
        ch = getchar();
    } while(ch!='Q' && ch != 'q');

    MQTTClient_disconnect(gameClient, 10000);
    MQTTClient_destroy(gameClient);
    std::cout << rc << std::endl;
}


