#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "bubbleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
using namespace std;

const int max_size = 100;  // the capacity of data elements in our dataset


int main()
{
 
    //generate random values
    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand()/70000;
    }
    cout << "Unsorted data: " << endl;
    
    for(int i = 0; i < max_size; i++){ //print dataset
        cout << dataset[i] << " ";
    }
    
    cout << "\n" << "\n" <<"\n";

    bubbleSort(dataset, max_size);     //bubblesort function
    cout << "Sorted data using Bubble Sort (Descending Order): " << endl;
    
    for(int i = 0; i < max_size; i++){ //print dataset
        cout << dataset[i] << " ";
    }
    
    cout << "\n" << "\n" <<"\n";
    
    selectionSort(dataset, max_size);     //Selection Sort function
    cout << "Sorted data using Selection Sort (Ascending Order): " << endl;
    
    for(int i = 0; i < max_size; i++){ //print dataset
        cout << dataset[i] << " ";
    }
    
    cout << "\n" << "\n" <<"\n";
    
    insertionSort(dataset, max_size);     //Insertion Sort function
    cout << "Sorted data using Selection Sort (Ascending Order): " << endl;
    
    for(int i = 0; i < max_size; i++){ //print dataset
        cout << dataset[i] << " ";
    }
    
    return 0;
}


