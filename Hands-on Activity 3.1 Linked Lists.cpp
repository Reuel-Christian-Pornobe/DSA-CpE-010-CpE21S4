#include<iostream>
#include<utility>
using namespace std;

class Node
{
    public:
        char data;
        Node *next;
    
};

// Traversal Function
Node* ListTraversal(Node *n)
{
    while (n != NULL)
    {
        cout << n->data;
        n = n->next;
    }
    return n;
}

// Insertion at any point
Node* insertAnyPos(Node* head, int pos, char value)
{
    Node* insertNode = new Node;
    insertNode->data = value;
    
    Node* headPos = head;
    for(int i = 1; i < pos - 1 && headPos != nullptr; i++)
    {
        headPos = headPos->next;
    }
    
    if (headPos == nullptr)
    {
        cout << "Position is out of bounds. ";
        delete insertNode;
        
        return head;
        
    }
    
    insertNode->next = headPos->next;
    headPos->next = insertNode;
    return head;
}
    
//Insertion at the end   
Node* insertEnd(Node* head, char value)
{
    Node* insertNode = new Node;
    insertNode->data = value;
    
    if(head == nullptr)
    {
        return insertNode;
    }
    
    Node* last = head;
    
    while (last->next != nullptr) 
    {
        last = last->next;
    }
    last->next = insertNode;
    return head;
}
    
//Deletion at any point
Node* deletionAnyPoint(Node* head, int pos)
{
    Node* prev;
    Node* temp = head;

    
    // Search for given position
    for (int i = 1; i != pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If found, delete the node
    if (temp != NULL) {
        prev->next = temp->next;
        //free(temp);
    }
    // If given position is not present
    else {
        cout << "Data not present\n";
    }

    return head;
}


int main()
{
    // step 1
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;
    Node *last = NULL;
    
    // step 2
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;
    last = new Node;
    
    // step 3
    head->data = 'C';
    head->next = second;
    
    second->data = 'P';
    second->next = third;
    
    third->data = 'E';
    third->next = fourth;
    
    fourth->data = '1';
    fourth->next = fifth;
    
    fifth->data = '0';
    fifth->next = last;
    
    last->data = '1';
    last->next = nullptr;
    
    
    // TRAVERSAL
    ListTraversal(head);
    cout << "\n\n";
    
    
    // INSERTION at head
    char insertData;                       //initialization of input
    cout << "\nInsert a Character at the start: ";
    cin >> insertData;
    
    Node *nodeInsert = NULL;           // 1. Allocate memory for the new node
    nodeInsert = new Node; 
    
    nodeInsert->data = insertData;         // 2. Put our data into the new node
    nodeInsert->next = head;           // 3. Set Next of the new node to point to the previous Head
    
    ListTraversal(nodeInsert);         // 4. Reset Head to point to the new node
    
    
    // INSERTION at any point
    int pos;
    char insertData1;
    
    cout << "\n\nType the index on where to insert: ";
    cin>>pos;
    cout << "Insert a Character: ";
    cin>>insertData1;
    
    Node* insertAtAnyPoint = insertAnyPos(nodeInsert, pos, insertData1);
    ListTraversal(insertAtAnyPoint); 
    
    // INSERTION at end (Not used for Table 3.3)
    
    /*char insertData2;
    cout << "\n\nInsert a Character at the end: ";
    cin>>insertData2;
    
    Node* endInsert = insertEnd(nodeInsert, insertData2);
    ListTraversal(endInsert); */
   
    // Deletion of Node 1
    int pos1;
    cout << "\n\nType the index on where to delete: ";
    cin>>pos1;
    
    
    Node* del = deletionAnyPoint(nodeInsert, pos1);
    ListTraversal(del);
    
    // Deletion of Node 2
    int pos2;
    cout << "\n\nType the index on where to delete: ";
    cin>>pos2;
    
    
    Node* del2 = deletionAnyPoint(nodeInsert, pos2);
    ListTraversal(del2);
    
    
    
    return 0;
}