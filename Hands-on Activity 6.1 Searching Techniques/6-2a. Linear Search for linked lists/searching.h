#ifndef SEARCHING_H // Include guard
#define SEARCHING_H

#include <iostream>
#include "nodes.h"

using namespace std;


int lineartLS(Node<char> *head);
int countLinkedList(Node<char> *head);


int countLinkedList(Node<char>  *head){
    
    int count;
    while (head != NULL){
        count += 1;
        head = head->next;
    }
    return count;
} 

int linearLS(Node<char>* head, int count, char choice) {
    for (int i = 0; i < count && head != nullptr; i++) { // Check if head is not null
        if (choice == head->data) {
            return i; // Return index if found
        } else {
            head = head->next; // Move to the next node correctly
        }
    }
    return -1; // Return -1 if not found
}

#endif
