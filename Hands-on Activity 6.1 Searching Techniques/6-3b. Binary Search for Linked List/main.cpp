#include <iostream>

#include "nodes.h"
#include "searching.h"

int main(){
    //create a linked list for binary search
    //make sure the values are ordered
    char choice = 'y'; 
    int count = 1; 
    int newData;
    Node<int> *temp, *head, *node;
    
    cout << "Add a linkedlist? (y for yes): ";
    cin >> choice;
    
    while(choice=='y'){
        std::cout << "Enter data: ";
        std::cin >> newData;
        
        if(count==1){
            head = new_node(newData);
            std::cout << "Successfully added " << head->data << " to the list.\n";
            count++;
        } 
        else if(count==2) {
            node = new_node(newData);
            head->next = node;
            node->next = NULL;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            
            count++;
        } 
        
        else {
            temp = head;
            while(true){
            if(temp->next == NULL) break;
            temp = temp->next;
            }
            node = new_node(newData);
            temp->next = node;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }
        
        //when to end
        std::cout << "Continue? (y/n)";
        std::cin >> choice;
        if(choice=='n') break;
    }
    
    Node<int> *currNode;        //display the linkedlist
    currNode = head; 
    while(currNode!=NULL){ 
        std::cout << currNode->data << " "; 
        currNode = currNode->next; 
    }
    
    
    int check;
    cout << "\nType an integer to search in linked list: ";
    cin >> check;
    cout << endl;
    
    if (binarySearch(head, check) == true){
        cout << "Present";
    }
        
    else{
        cout << "Value not present\n";
    }
        
    
    return 0;
}































