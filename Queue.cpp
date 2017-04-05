//
// Created by jimena on 3/25/17.
//
#include "Queue.h"
#include "powerUp.h"

template <typename T>
Queue<T>::Queue() {
    head=NULL;
    lenght=0;
}

template <typename T>
T Queue<T>::dequeue() {
    Node<T>* temp = new Node<T>;
    if(head==NULL){
        cout<<"Empty Queue"<<endl;
    }else{
        temp = head;
        head = head->next;
        lenght--;
        return temp->data;
    }
}
template <typename T>
void Queue<T>::enqueue(T data) {
    if(head == NULL){
        head = new Node<T>;
        head->data = data;
        head->next = NULL;
    }else{
        Node<T>* temp = head;
        Node<T>* newNode = new Node<T>;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->data = data;
    }
    lenght ++;
}

template <typename T>
void Queue<T>::printQueue() {
    cout<<"[";
    if(head != NULL) {
        Node<T> *temp = head;
        while(temp != NULL){
            cout<<temp->data.getType()<<",";
            temp = temp->next;
        }
    }else{
        cout << "EmptyQueue";
    }
    cout<<"]"<<endl;
}

template <typename T>
bool Queue<T>::isEmpty() {
    bool result = false;
    if(head ==NULL){
        result = true;
    }
    return result;
}


template class Queue<powerUp>;