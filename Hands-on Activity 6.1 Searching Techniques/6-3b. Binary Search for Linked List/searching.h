#ifndef SEARCHING_H // Include guard
#define SEARCHING_H

#include <iostream>
#include "nodes.h"

using namespace std;


Node<int> *middle(Node<int> *start, Node<int> *last) {
    if (start == NULL) {
        return NULL;
    }

    if (start == last)
        return start;

    Node<int> *slow = start;
    Node<int> *fast = start->next;

    while (fast != last) {
        fast = fast->next;
        slow = slow->next;
        if (fast != last) {
            fast = fast->next;
        }
    }

    return slow;
}

bool binarySearch(Node<int> *head, int value) {
    Node<int> *start = head;
    Node<int> *end = head;

    // Find the end of the list
    while (end->next != NULL) {
        end = end->next;
    }

    while (start != NULL && start != end) {
        // Find middle
        Node<int> *mid = middle(start, end);

        // If value is present at middle
        if (mid->data == value)
            return true;

        // If value is more than mid
        else if (mid->data < value) {
            start = mid->next;
        }

        // If the value is less than mid.
        else if (mid->data > value)
            end = mid;
    }

    // If the value is present at the start or end
    if (start != NULL && start->data == value)
        return true;

    // value not present
    return false;
}
#endif
