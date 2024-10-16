#include <iostream>
using namespace std;


int sequentialSearchArray(int arr[], int size, int key);
int occurences(int arr[], int size, int key);    // Function declaration of the occurences function


int main() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;

    int occurrences = occurences(arr, size, key);
    cout << "Amount of occurences of " << key << " in array: " << occurrences << endl;

    return 0;
}


int occurences(int arr[], int size, int key) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            count++;  // Increment the count whenever the key is found
        }
    }
    return count; // Return the total count of occurrences
}

int sequentialSearchArray(int arr[], int size, int key) {
    
    int index = 0;                        //comparison index
    
    for (int i = 0; i < size; i++) {
        
        index++;
        
        if (arr[i] == key) {
            return index; // Return comparisons when key is found
            
        }
        
    }
    return index; // If key is not found, return total comparisons
    
}