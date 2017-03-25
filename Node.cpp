//
// Created by jimena on 3/25/17.
//
#include "Node.h"
template <typename T>
Node<T>::Node(){
    next = nullptr;
}

template class Node<int>;
template class Node<char*>;

