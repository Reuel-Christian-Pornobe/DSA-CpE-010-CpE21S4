#include <iostream>

class Node
{
public:
	int value;
	Node* next;
};









int main()
{
	Node* head;
	Node* one = NULL;
	Node* two = NULL;
	Node* three = NULL;
	Node* four = NULL;
	Node* five = NULL;

	//allocate 3 nodes in the heap
	one = new Node();
	two = new Node();
	three = new Node();
	four = new Node();
    five = new Node();
    
    one ->next = two;
    two ->next = three;
    three ->next = four;
    four ->next = five;
    five ->next = NULL;
    
    one ->value=1;
    two ->value=2;
    three ->value=3;
    four ->value=4;
    five ->value=5;
    
    head = one;
    while (head != NULL)
    {
        std::cout << head ->value;
        head = head ->next;
    }

	return 0;
}