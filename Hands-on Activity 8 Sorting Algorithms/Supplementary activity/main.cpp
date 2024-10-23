#include <iostream>
#include "quick.h"

const int max_size = 100; 

void generateRandomValues(int arr[]);
void printData(int dataset[], const int size);


int main() {
    
    int dataset[max_size];
    
    cout << "Unsorted data: " << endl;
    generateRandomValues(dataset);
    printData(dataset, max_size);
    

    cout << "Sorted Data(Quick sort): " << endl;
    quickSortWithInsertionSort(dataset, 0, max_size - 1);
    printData(dataset, max_size);
    
    cout << endl;

    return 0;
}

void generateRandomValues(int arr[]){
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        arr[i] = rand()/10000000;
    }    
}   
void printData(int dataset[], const int size){
    for(int i = 0; i < size; i++){ //print dataset
        cout << dataset[i] << " ";
    }
    cout << endl << endl;
}