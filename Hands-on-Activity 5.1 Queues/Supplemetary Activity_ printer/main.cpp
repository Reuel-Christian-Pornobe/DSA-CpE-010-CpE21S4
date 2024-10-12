#include <iostream>
#include <string>
using namespace std;

class Job {
public:
    int jobID;         // Unique job ID
    string userName;   // Name of the user submitting the job
    int numPages;      // Number of pages in the print job

    // Constructor to initialize a job
    Job(int id, string name, int pages) : jobID(id), userName(name), numPages(pages) {}
    
    // Display job details
    void display() {
        cout << "Job ID: " << jobID << ", User: " << userName << ", Pages: " << numPages << endl;
    }
};

class Node {
public:
    Job* job;      // Pointer to a Job object
    Node* next;    // Pointer to the next node in the list

    // Constructor to initialize a node
    Node(Job* j) : job(j), next(nullptr) {}
};

class Printer {
private:
    Node* front;  // Pointer to the front (oldest) job in the queue
    Node* rear;   // Pointer to the rear (newest) job in the queue
    int jobCounter;  // Keeps track of total jobs added

public:
    // Constructor to initialize an empty queue
    Printer() : front(nullptr), rear(nullptr), jobCounter(0) {}

    // Destructor to free memory
    ~Printer() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp->job;  // Delete the Job object
            delete temp;       // Delete the Node object
        }
    }

    // Function to add a new job (enqueue)
    void addJob(string userName, int numPages) {
        jobCounter++;
        Job* newJob = new Job(jobCounter, userName, numPages);
        Node* newNode = new Node(newJob);

        if (rear == nullptr) {  // If the queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Job added to queue: ";
        newJob->display();
    }

    // Function to process the next job (dequeue)
    void processJob() {
        if (front == nullptr) {  // If the queue is empty
            cout << "No jobs to process." << endl;
            return;
        }

        Node* temp = front;
        cout << "Processing job: ";
        temp->job->display();

        front = front->next;  // Move the front pointer to the next job

        if (front == nullptr) {  // If the queue becomes empty
            rear = nullptr;
        }

        delete temp->job;  // Free memory for the processed job
        delete temp;       // Free memory for the node
    }

    // Function to show all pending jobs
    void showQueue() const {
        if (front == nullptr) {
            cout << "No pending jobs in the printer queue." << endl;
            return;
        }

        Node* current = front;
        cout << "Pending jobs in the printer queue:" << endl;
        while (current != nullptr) {
            current->job->display();
            current = current->next;
        }
    }
};




int main() {
    Printer printer;  // Linked list-based printer

    // Multiple users submitting jobs
    printer.addJob("Yggdrasil", 10);
    printer.addJob("Olaf", 5);
    printer.addJob("Pilate", 20);

    // Display queue
    printer.showQueue();

    // Process one job
    printer.processJob();

    // Add more jobs
    printer.addJob("Teldrassil", 15);
    printer.addJob("Mirabella", 25);

    // Display queue
    printer.showQueue();

    // Process all jobs
    printer.processJob();
    printer.processJob();
    printer.processJob();

    // Display queue after processing
    printer.showQueue();

    return 0;
}



