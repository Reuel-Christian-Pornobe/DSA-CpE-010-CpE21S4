#include <iostream>

class Node 
{
public:
    int data;
    Node *next;
    
};

Node *head = NULL, *tail = NULL;


void push(int newData);    // function declaration of pushing an item to the stack
int pop();                 // function declaration of removing the top of the stack
void Top();                // function declaration of showing the top of the stack
Node* showStack(Node* n);   // function declaration of showing all the items in the stack

int main ()
{
    push(1);
    std::cout << "After first PUSH top of stack is: ";
    Top();
    std::cout << "All the items in the stack: ";
    showStack(head);
    std::cout << std::endl;
    
    push(5);
    std::cout << "After second PUSH top of stack is: ";
    Top();
    std::cout << "All the items in the stack: ";
    showStack(head);
    std::cout << std::endl;
    
    pop();
    std::cout << "After the first POP operation, top of the stack is: ";
    Top();
    std::cout << "All the items in the stack: ";
    showStack(head);
    std::cout << std::endl;

    pop();
    std::cout << "After the first POP operation, top of the stack is: ";
    Top();
    std::cout << "All the items in the stack: ";
    showStack(head);
    std::cout << std::endl;
    pop();
    
    return 0;
}

// function of pushing an item to the stack
void push(int newData)
{
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next= head;
        head = newNode;
    }
}

// function of removing the top of the stack
int pop()
{
    int tempVal;
    Node *temp;
    
    if (head == NULL)
    {
        head = tail = NULL;
        std::cout << "Stack Overflow." << std::endl;
        return -1;
        
    }
    
    else 
    {
        temp = head;
        tempVal = temp->data;
        head = head->next;
        delete(temp);
        
        return tempVal;
    }
}

// function of showing the top of the stack
void Top()
{
    if(head == NULL)
    {
        std::cout << "Stack is Empty." << std::endl;
        return;
        
    }
    
    else
    {
        std::cout << "Top of stack: " << head->data << std::endl;
        
    }
}

// function of showing all the items in the stack
Node* showStack(Node* n)
{
    while(n != NULL)
    {
        std::cout << n->data << ", "; // print the value of the node
        n = n->next;          // go to the next node
    }
    return n;
}




































