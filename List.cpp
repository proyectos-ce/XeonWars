//
// Created by jimena on 3/25/17.
//
#include "List.h"
template <typename T>
List<T>::List() {
    head = NULL;
    lenght = 0;
}
template <typename T>
List<T>::~List() {
}

template <typename T>
void List<T>::add(T data) {
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
void List<T>::deleteData(T data) {
    Node<T> *temp = head;
    bool deleted = false;
    if(temp==NULL){
        cout << "EmptyList"<<endl;
    }
    else if(temp->data == data){
        head = head->next;
        deleted = true;
    }
    else{
        while(temp->next !=NULL){
            if(temp->next->data == data){
                temp->next = temp->next->next;
                deleted = true;
            }else{
                temp=temp->next;
            }
        }
    }
        if(deleted) {
            lenght--;
        }
        cout << "La lista ahora tiene " << lenght<<endl;

}

template <typename T>
void List<T>::printList() {
    cout<<"[";
    if(head != NULL) {
        Node<T> *temp = head;
        while(temp != NULL){
            cout<<temp->data<<",";
            temp = temp->next;
        }
    }else{
        cout << "EmptyList"<<endl;
    }
    cout<<"]"<<endl;
}

template class List<int>;
template class List<char*>;