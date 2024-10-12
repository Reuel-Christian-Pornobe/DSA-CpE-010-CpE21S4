#include <iostream>
#include <queue>
using namespace std;


class Node            
{
public:
    string data;
    Node *next;
    Node *prev;
};

Node* traverse(Node* tail);                    // function decalaration of displaying all nodes in the queue
Node* deletionAnyPoint(Node* head, int pos);   // function decalaration of deleting an item in the queue

int main()
{
    
    
    // Inserting an item into an empty queue
    Node* head;                 //initializing the head and tail node
    Node* tail;
    
    Node* node1 = new Node();   //node variables
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    Node* node5 = new Node();
    Node* node6 = new Node();
    
    // the node or item to be inserted to an empty queue
    node1 ->data = "Raguel Allobrogicus";         
    node1 ->next = nullptr;
    node1 ->prev = nullptr;
    head = node1;
    tail = node1;
    
    //Deleting an item from a queue with one item
    /*
    deletionAnyPoint(head, 1);
    traverse(tail);*/
    
    
    node2 ->data = "Egilhard Forneyg";        
    node2 ->next = nullptr;
    node2 ->prev = tail;
    tail ->next = node2;       
    tail = node2;               
    
    node3 ->data = "Olaf Hjalmar Ingolf";         
    node3 ->next = nullptr;
    node3 ->prev = tail;
    tail ->next = node3;
    tail = node3;
    
    node4 ->data =  "Lana Hightowere";         
    node4 ->next = nullptr;
    node4 ->prev = tail;
    tail ->next = node4;
    tail = node4;
    
    node5 ->data = "Earnan Ennisi";         
    node5 ->next = nullptr;
    node5 ->prev = tail;
    tail ->next = node5;
    tail = node5;
    
    // Inserting an item into a non-empty queue
    node6->data = "Kyle Roderiguez";     
    node6 ->next = nullptr;
    node6 ->prev = tail;
    tail ->next = node6;
    tail = node6;
    //display the items in the queue
    traverse(tail);
    
    cout << "\n\n" << "After deleting the 3rd person from the queue: ";
    
    // deleting node 3 from the queue
    deletionAnyPoint(head, 3);
    traverse(tail);
    
    
    return 0;
}



//function to display all items in the linked lists
Node* traverse(Node* tail)  
{
    Node* n = tail;         //traversing node
    while (n != nullptr)
    {
        cout << n->data << ", ";
        n = n->prev;
    }
    return n;
}

//function to delete a node or an item from a queue
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


