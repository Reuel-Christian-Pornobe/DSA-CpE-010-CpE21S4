#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "nodes.h"
#include "searching.h"

const int max_size = 50;  // the capacity of data elements in our dataset


int main()
{
 
    //generate random values
    //int dataset[max_size];
    //srand(time(0));
    //for(int i = 0; i < max_size; i++){
    //    dataset[i] = rand();
    //}
    
    Node<char> *name1 = new_node('R');
    Node<char> *name2 = new_node('o');
    Node<char> *name3 = new_node('m');
    Node<char> *name4 = new_node('a');
    Node<char> *name5 = new_node('n');
    
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = NULL;
    
    
   int count, answer;
   char choice;
   
   cout << "Type a char to search: ";
   cin >> choice;
   count = countLinkedList(name1);
   
   answer = linearLS(name1, '5', choice);
   cout << "Index: " << answer;
    
    return 0;
}