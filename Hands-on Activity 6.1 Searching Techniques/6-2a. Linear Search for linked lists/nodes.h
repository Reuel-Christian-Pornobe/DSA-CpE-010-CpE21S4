#ifndef NODES_H // Include guard
#define NODES_H

#include <iostream>

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
};


template <typename T>

Node<T> *new_node(T newData){
    
    Node<T> *newNode = new Node<T>; // creating a node
    newNode->data = newData;        // inserting the data
    newNode->next = nullptr;           // creating a pointer tha points to nothing
    return newNode;
}

#endif