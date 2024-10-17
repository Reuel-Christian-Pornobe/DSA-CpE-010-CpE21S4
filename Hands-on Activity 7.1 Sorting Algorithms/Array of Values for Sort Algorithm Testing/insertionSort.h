#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

template <typename T>


void insertionSort(T arr[], const int N){
    int K = 0, J, temp;
    
    //Step 1: Repeat Steps 2 to 5 for K = 1 to N-1
    while(K < N){
        
        //Step 2: set temp = A[K]
        temp = arr[K];
        
        //Step 3: set J = K – 1
        J = K-1;
        
        //Step 4: Repeat while temp <=A[J]
        while(temp <= arr[J]){
            //set A[J + 1] = A[J]
            arr[J+1] = arr[J];
            //set J = J – 1
            J--;
            //[end of inner loop]
            }
            
        //Step 5: set A[J + 1] = temp
        arr[J+1] = temp;
        
        //[end of loop]
        K++;
        }
    //Step 6: exit
}

#endif