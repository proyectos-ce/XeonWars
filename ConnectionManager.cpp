//
// Created by Ignacio Mora on 4/5/17.
//

#include <cstdlib>
#include <iostream>
#include <zconf.h>
#include "ConnectionManager.h"
#include <mosquitto.h>



void connect_callback(struct mosquitto *mosq, void *obj, int result)
{
    printf("connect callback, rc=%d\n", result);
}

void message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message)
{
    bool match = 0;
    printf("got message '%.*s' for topic '%s'\n", message->payloadlen, (char*) message->payload, message->topic);

    mosquitto_topic_matches_sub("/XeonDataFrom/Phone", message->topic, &match);
    if (match) {
        printf("got message for ADC topic\n");
    }

}

ConnectionManager::ConnectionManager() {
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

        mosquitto_loop_forever(mosq, -1, 1);
    }
}
