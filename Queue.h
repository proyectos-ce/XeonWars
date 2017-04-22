//
// Created by jimena on 3/25/17.
//

#ifndef XEONWARS_QUEUE_H
#define XEONWARS_QUEUE_H
#include <iostream>
#include "Node.h"
using namespace std;

template <class T> class Queue {



private:
    int lenght;
public:
    int getLenght() const;

private:
    Node<T> *head;

public:
    Queue<T>();
    T dequeue();
    void enqueue(T data);
    void dequeueAll();
    void printQueue();
    bool isEmpty();
    Node<T> *getHead() const;



};



#endif //XEONWARS_QUEUE_H
