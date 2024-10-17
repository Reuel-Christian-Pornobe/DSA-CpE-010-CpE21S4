#ifndef PRINT_H
#define PRINT_H


using namespace std;


// Function to print the array
template <typename T>
void printArray(T arr[], const int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

#endif