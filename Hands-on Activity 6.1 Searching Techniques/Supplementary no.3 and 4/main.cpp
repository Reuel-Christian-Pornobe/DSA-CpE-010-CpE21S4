#include <iostream>
using namespace std;


int search(int arr[], int size, int key);

int main() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int result = search(arr, size, key);
    
    if (result != -1) {
        cout << "The Number " << key << " is found at index " << result << endl;
    } else {
        cout << "Key " << key << " not found." << endl;
    }

    return 0;
}

int search(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;
    int comparisons = 0;  
    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;  

        if (arr[mid] == key) {
            cout << "Amount of comparisons: "<< comparisons << endl;
            return mid;  // Key found, return its index
        }
        if (arr[mid] < key) {
            low = mid + 1;  // Search the right part
        } else {
            high = mid - 1;  // Search the left part
        }
    }
    cout << "Key not found after " << comparisons;
    
    return -1;  // return error if not found
}
