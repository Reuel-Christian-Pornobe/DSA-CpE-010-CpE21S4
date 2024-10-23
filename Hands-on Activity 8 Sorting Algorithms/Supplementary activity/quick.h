#ifndef QUICK_H
#define QUICK_H
using namespace std;


template<typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


template<typename T>
void insertionSort(T arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Modified quickSort function to use Insertion Sort on left and right subarrays
template<typename T>
void quickSortWithInsertionSort(T arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);   

       
        insertionSort(arr, low, pi - 1);

        insertionSort(arr, pi + 1, high);
    }
}

#endif
