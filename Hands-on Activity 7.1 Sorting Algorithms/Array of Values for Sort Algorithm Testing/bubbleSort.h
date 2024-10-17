#ifndef BUBBLESORT_H
#define BUBBLESORT_H

template <typename T>
void bubbleSort(T arr[], size_t arrSize){
    
    //Step 1: For i = 0 to N-1 repeat Step 2
    for(int i = 0; i < arrSize; i++){
        //Step 2: For J = i + 1 to N – I repeat
        for(int j = i+1; j < arrSize; j++){
            
            //Step 3: if A[J] > A[i]
            if(arr[j]>arr[i]){
                //Swap A[J] and A[i]
                std::swap(arr[j], arr[i]);
            }
            //[End of Inner for loop]
        }
        //[End if Outer for loop]
    }
    //Step 4: Exit
}

#endif