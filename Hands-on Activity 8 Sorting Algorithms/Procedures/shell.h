#ifndef SHELL_H
#define SHELL_H

template <typename T>

int shellSort(T arr[], const int size){
    for(int i = size/2; i > 0; i /= 2){
        for(int j = i; j < size; j++){
            int temp = arr[j];
            int k;
            
            for (k = j; k >= i && arr[k - i] > temp; k -= i)
                arr[k] = arr[k - i];
                
            arr[k] = temp;
        }   
    }
    return 0;
}



#endif