//
// Created by jimena on 3/25/17.
//

#ifndef XEONWARS_QUEUE_H
#define XEONWARS_QUEUE_H
#include <iostream>
#include "Node.h"
using namespace std;

template <class T> class Queue {
    Node<T> *head;
    int lenght;

public:
    Queue<T>();
    void dequeue();
    void enqueue(T data);
    void printQueue();

};



#endif //XEONWARS_QUEUE_H
