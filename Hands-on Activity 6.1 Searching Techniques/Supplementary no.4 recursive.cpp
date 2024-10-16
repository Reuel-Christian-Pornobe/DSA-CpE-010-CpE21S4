#include <iostream>
using namespace std;

int recursiveB(int arr[], int low, int high, int key, int &comparisons);


int main() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;
    int comparisons = 0;

    // Perform recursive binary search
    int result = recursiveB(arr, 0, size - 1, key, comparisons);

    // Output results
    if (result != -1) {
        cout << key << " is at index " << result <<  endl;
        cout << "comparisons: " << comparisons;
    } else {
        cout << key << " not found after " << comparisons << " comparisons." << endl;
    }

    return 0;
}

int recursiveB(int arr[], int low, int high, int key, int &comparisons) {
    if (low > high) {
        // Base case: key not found
        return -1;
    }

    // Increment comparison counter
    comparisons++;

    // Calculate mid index
    int mid = low + (high - low) / 2;

    // Check if the middle element is the key
    if (arr[mid] == key) {
        return mid;  // Key found, return index
    }

    // If key is smaller than mid, search the left half
    if (arr[mid] > key) {
        return recursiveB(arr, low, mid - 1, key, comparisons);
    }

    // If key is greater than mid, search the right half
    return recursiveB(arr, mid + 1, high, key, comparisons);
}