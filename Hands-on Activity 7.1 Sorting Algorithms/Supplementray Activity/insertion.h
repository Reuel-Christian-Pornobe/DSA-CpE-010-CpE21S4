#ifndef INSERTION_H
#define INSERTION_H


// Function to perform Insertion Sort
template <typename T>
void insertionSort(T arr[], const int N) {
    for (int K = 1; K < N; K++) {
        T temp = arr[K];
        int J = K - 1;
        while (J >= 0 && arr[J] > temp) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
    }
}

#endif