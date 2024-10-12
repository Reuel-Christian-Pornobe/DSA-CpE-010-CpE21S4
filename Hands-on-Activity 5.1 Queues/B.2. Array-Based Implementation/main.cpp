#include <iostream>
using namespace std;

class Queue {
private:
    int* q_arr;  // Pointer to the dynamic array
    int q_capacity;  // Maximum capacity of the queue (renamed to q_capacity)
    int q_front;  // Index of the front element
    int q_back;  // Index of the last element
    int q_size;  // Current size of the queue

    // Helper function to copy elements from one queue to another
    void copyQueue(const Queue& other) {
        q_arr = new int[other.q_capacity];
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        // Copy elements from the other queue 
        for (int i = 0; i < q_capacity; i++) {
            q_arr[i] = other.q_arr[i];
        }
    }

public:
    // Constructor to initialize the queue with a specified capacity
    Queue(int cap = 10) : q_capacity(cap), q_size(0), q_front(0), q_back(-1) {
        q_arr = new int[q_capacity];
    }

    // Destructor to free the allocated memory
    ~Queue() {
        delete[] q_arr;
    }

    // Copy Constructor
    Queue(const Queue& other) {
        copyQueue(other);
    }

    // Copy Assignment Operator
    Queue& operator=(const Queue& other) {
        if (this != &other) {
            delete[] q_arr;  // Deallocate old memory
            copyQueue(other);
        }
        return *this;
    }

    // Function to check if the queue is empty
    bool empty() const {
        return q_size == 0;
    }

    // Function to return the current size of the queue
    int size() const {
        return q_size;
    }

    // Function to clear the queue (reset size and indices but not capacity)
    void clear() {
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    // Function to access the front element
    int front() const {
        if (empty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;  // Return some invalid value
        }
        return q_arr[q_front];
    }

    // Function to access the last (back) element
    int back() const {
        if (empty()) {
            cout << "Queue is empty. No back element." << endl;
            return -1;  // Return some invalid value
        }
        return q_arr[q_back];
    }

    // Function to insert an element into the queue (enqueue)
    void enqueue(int value) {
        if (q_size == q_capacity) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        q_back = (q_back + 1) % q_capacity;  // Circular array handling
        q_arr[q_back] = value;
        q_size++;
    }

    // Function to remove the front element from the queue (dequeue)
    int dequeue() {
        if (empty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;  // Return some invalid value
        }
        int value = q_arr[q_front];
        q_front = (q_front + 1) % q_capacity;  // Circular array handling
        q_size--;
        return value;
    }

    // Display the queue contents (for testing purposes)
    void display() const {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue contents: ";
        for (int i = 0; i < q_size; i++) {
            cout << q_arr[(q_front + i) % q_capacity] << " ";
        }
        cout << endl;
    }
};

// Test the queue
int main() {
    Queue q(5);  // Create a queue of capacity 5

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    q.display();
    
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.front() << endl;
    cout << "Back element after dequeue: " << q.back() << endl;

    q.display();

    Queue q2 = q;  // Testing copy constructor
    q2.display();

    Queue q3;
    q3 = q;  // Testing copy assignment operator
    q3.display();

    return 0;
}
