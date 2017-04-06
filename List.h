//
// Created by jimena on 3/25/17.
//

#ifndef XEONWARS_LIST_H
#define XEONWARS_LIST_H
#include <iostream>
#include "Node.h"
using namespace std;

template <class T> class List{
    Node<T> *head;
public:
    List<T>();
    ~List<T>();

    int lenght;
    void add(T data);
    void printList();
    void deleteData(T data);


};


#endif //XEONWARS_LIST_H
