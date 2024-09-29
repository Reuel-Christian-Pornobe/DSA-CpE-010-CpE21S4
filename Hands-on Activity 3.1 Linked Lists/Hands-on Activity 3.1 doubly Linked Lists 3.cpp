#include<iostream>
#include<utility>
using namespace std;

class Node  
{
    public:
        char data;
        Node* next;
        Node* prev;
    
};

Node* traverseForward(Node* head);   // traversing forward, FUNCTION DECLARATION
Node* traverseBackward(Node* head);  // traversing backward, FUNCTION DECLARATION
Node* insertHead(Node* head, char value); //insert node at the head, FUNCTION DECLARATION
Node* insertAnyPos(Node* head, int pos, char value); //insert node at any position, FUNCTION DECLARATION
Node* insertEnd(Node* tail, char value); //insert node at the tail, FUNCTION DECLARATION
Node* deletionAnyPoint(Node* head, int pos); //delete node at any position, FUNCTION DECLARATION 

int main()                          
{
    
    Node* head;                 //initializing the head and tail node
    Node* tail;
    
    Node* node1 = new Node();   //node variables
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    Node* node5 = new Node();
    Node* node6 = new Node();
    
    
    node1 ->data = 'C';         //creating a node(head)
    node1 ->next = nullptr;
    node1 ->prev = nullptr;
    head = node1;
    tail = node1;
    
    node2 ->data = 'P';         //creating a node
    node2 ->next = nullptr;
    node2 ->prev = tail;
    tail ->next = node2;        //connecting the tail of node1 to node 2
    tail = node2;               //new tail is node2
    
    node3 ->data = 'E';          //continuing the process in node2
    node3 ->next = nullptr;
    node3 ->prev = tail;
    tail ->next = node3;
    tail = node3;
    
    node4 ->data = '1';         //continuing the process in node2
    node4 ->next = nullptr;
    node4 ->prev = tail;
    tail ->next = node4;
    tail = node4;
    
    node5 ->data = '0';         //continuing the process in node2
    node5 ->next = nullptr;
    node5 ->prev = tail;
    tail ->next = node5;
    tail = node5;
    
    node6 ->data = '1';          //continuing the process in node2
    node6 ->next = nullptr;
    node6 ->prev = tail;
    tail ->next = node6;
    tail = node6;
    
    
    //traversing
    traverseForward(head);
    cout<<"\n";
    traverseBackward(tail);
    cout<<"\n"<<"\n";
    
    //insertion at head
    head = insertHead(head, 'A');
    traverseForward(head);
    cout<<"\n";
    traverseBackward(tail);
    cout<<"\n"<<"\n";
    
    //insertion anypoint
    Node* insertAtAnyPoint = insertAnyPos(head, 3, 'E');
    cout<<"\n";
    traverseForward(head);
    cout<<"\n";
    traverseBackward(tail);
    cout<<"\n"<<"\n";
    
    //insertion at the tail
    tail = insertEnd(tail, 'H');
    cout<<"\n";
    traverseForward(head);
    cout<<"\n";
    traverseBackward(tail);
    cout<<"\n"<<"\n";
    
    head = deletionAnyPoint(head, 4);
    cout<<"\n";
    traverseForward(head);
    cout<<"\n";
    traverseBackward(tail);
    cout<<"\n"<<"\n";
    
    return 0;
}


//traversing in forward direction, FUNCTION
Node* traverseForward(Node* head)    
{
    Node* n = head;         //traversing node
    while (n != nullptr)
    {
        cout << n->data;
        n = n->next;
    }
    return n;
}

//traversing in backward direction, FUNCTION
Node* traverseBackward(Node* tail)  
{
    Node* n = tail;         //traversing node
    while (n != nullptr)
    {
        cout << n->data;
        n = n->prev;
    }
    return n;
}

//insert node at the head, FUNCTION
Node* insertHead(Node* head, char value)
{
    Node* insertNode = new Node;          
    insertNode->data = value;
    
    insertNode->next = head; //connecting the new head next pointer to the old head
    head->prev = insertNode; //connecting the old head prev pointer to the new head
    
    head = insertNode;      //declaration of new head
    insertNode->prev = nullptr; //new head prev = NULL
    
    return head;
}

//insert node at any position, FUNCTION
Node* insertAnyPos(Node* head, int pos, char value)  
{
    Node* insertNode = new Node;                     //creating a new inserting node                
    insertNode->data = value;
    
    Node* nF = head;                                 //traversing to the position (for the next pointer)
    for(int i = 1; i < pos - 1 && nF != nullptr; i++)   
    {
        nF = nF->next; 
    }
    Node* nR = head;                                 //traversing to the position (for the previous pointer)
    for(int i = 1; i < pos  && nF != nullptr; i++)   
    {
        nR = nR->next; 
    }
    
    if (nF == nullptr)                               //if position is null
    {
        cout << "Position is out of bounds. ";
        delete insertNode;
        
        return head;
        
    }
    
    insertNode->next = nF->next;  // linking the pointer of the new node to the next node
    nF->next = insertNode;
    insertNode->prev = nR->prev;  // linking the pointer of the new node to the next node
    nR->prev = insertNode;
    
    return head;
}

//insert node at the tail, FUNCTION
Node* insertEnd(Node* tail, char value)
{
    Node* insertNode = new Node; //New node
    insertNode->data = value;
    
    insertNode->prev = tail; //connecting the new tail prev pointer to the old tail
    tail->next = insertNode; //connecting the old tail next pointer to the new tail
    insertNode->next = nullptr; //new tail next = NULL
    
    tail = insertNode;      //declaration of new tail
    
    return tail;
}

//delete node at any position, FUNCTION
Node* deletionAnyPoint(Node* head, int pos)
{
    Node* temp1 = head;        //a temporary node for deletion
    Node* temp2 = NULL;        //another temporary node for deletion(always behind the temp1)
    
    if (pos == 1)              //if node to be deleted is the head  
    {
        head = head->next;
        free(temp1);
        temp1 = NULL;
        head->prev = NULL;
    }
    
    while(pos > 1)           //traversing/finding the node to be deleted
    {
        temp1 = temp1->next;
        pos--;
    }
    
    if (temp1->next == NULL)  //if node to be deleted is the tail  
    {
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->prev;
        temp2->next = NULL;
        free(temp1);
        temp1 = NULL;
    }
    
    else                      //if node to be deleted is at the middle
    {
        temp2 = temp1->prev;
        temp2->next=temp1->next;
        temp1->next->prev=temp2;
        free(temp1);
        temp1 = NULL;
    }
    
    return head;
}
