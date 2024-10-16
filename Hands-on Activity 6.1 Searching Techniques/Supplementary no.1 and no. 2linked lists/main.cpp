#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
};

Node* createNode(int data);
int sequentialSearchLinkedList(Node* head, int key);

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {            // shortcut of creating a linked list
        Node* newNode = createNode(arr[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int key = 18;

    int comparisons = sequentialSearchLinkedList(head, key);
    cout << "Amount of occurences of " << key << " in linked list: " << comparisons << endl;

    return 0;
}

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int sequentialSearchLinkedList(Node* head, int key) {
    Node* current = head;
    int comparisons = 0;

    while (current != nullptr) {
        comparisons++;
        if (current->data == key) {
            return comparisons; // Return comparisons when key is found
        }
        current = current->next;
    }

    return comparisons; // If key is not found, return total comparisons
}

int occurences(Node* head, int key) {
    Node* curr = head;
    int count = 0;

    while (curr != nullptr) {
        if (curr->data == key) {
            count++;  // Increment the count whenever the key is found
        }
        curr = curr->next;
    }

    return count; // Return the total count of occurrences
}


