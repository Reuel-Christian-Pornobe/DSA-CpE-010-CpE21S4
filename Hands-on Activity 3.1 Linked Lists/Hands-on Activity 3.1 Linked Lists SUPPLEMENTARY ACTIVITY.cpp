#include<iostream>
#include<utility>
using namespace std;

class Node  
{
    public:
        string data;
        Node* next;
        Node* prev;
};

// Function declarations
Node* insertEnd(Node* tail, string value);                         // Adding a song to the playlist
Node* traverseForward(Node* head);                                 // Printing the playlist
Node* removeSong(Node* head, string value);                        // Removing a song
void playSongsInLoop(Node* head);                                  // Playing songs in a loop

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    string value;
    int choice;
    
    do
    {
        cout << "\n--- Playlist Menu ---\n";
        cout << "1. Add a song to the playlist\n";
        cout << "2. Print the playlist\n";
        cout << "3. Remove a song from the playlist\n";
        cout << "4. Play songs in a loop (print all songs once)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                cout << "Enter the song to add: ";
                cin >> value;
                if (head == nullptr)
                {
                    // First song in the playlist
                    Node* node = new Node();
                    node->data = value;
                    node->next = nullptr;
                    node->prev = nullptr;
                    head = node;
                    tail = node;
                }
                else
                {
                    // Add song to the end of the playlist
                    tail = insertEnd(tail, value);
                }
                break;
                
            case 2:
                traverseForward(head);   // Print the playlist
                break;
                
            case 3:
                cout << "Enter the song to remove: ";
                cin >> value;
                head = removeSong(head, value);  // Remove song from the playlist
                break;
                
            case 4:
                playSongsInLoop(head);   // Play songs in a loop
                break;
                
            case 5:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add a song to the end of the playlist
Node* insertEnd(Node* tail, string value)
{
    Node* insertNode = new Node(); // New node
    insertNode->data = value;
    insertNode->prev = tail;     // Connect the new node's prev to the current tail
    tail->next = insertNode;     // Connect the current tail's next to the new node
    insertNode->next = nullptr;  // New tail's next is NULL
    tail = insertNode;           // Update the tail to point to the new node
    return tail;
}

// Function to print the playlist
Node* traverseForward(Node* head)    
{
    Node* n = head;  // Start from the head
    if (n == nullptr)
    {
        cout << "The playlist is empty!\n";
        return n;
    }
    
    while (n != nullptr)
    {
        cout << n->data << ", ";
        n = n->next;
    }
    cout << endl;
    return n;
}

// Function to remove a song from the playlist
Node* removeSong(Node* head, string value)
{
    Node* current = head;
    
    // Check if the list is empty
    if (current == nullptr)
    {
        cout << "Playlist is empty! Cannot remove any song.\n";
        return head;
    }
    
    // Traverse to find the node to delete
    while (current != nullptr && current->data != value)
    {
        current = current->next;
    }
    
    if (current == nullptr)
    {
        cout << "Song not found in the playlist.\n";
        return head;
    }

    // Song is found
    if (current == head)  // If it's the head node
    {
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
    }
    else if (current->next == nullptr)  // If it's the tail node
    {
        current->prev->next = nullptr;
    }
    else  // If it's a middle node
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    
    delete current;  // Free the memory
    cout << "Song removed from the playlist.\n";
    return head;
}

// Function to play songs in a loop (print all songs once)
void playSongsInLoop(Node* head)
{
    if (head == nullptr)
    {
        cout << "The playlist is empty!\n";
        return;
    }

    cout << "Playing songs in a loop:\n";
    traverseForward(head);  // For simplicity, we print the songs once
}
