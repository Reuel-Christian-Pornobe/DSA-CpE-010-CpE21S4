#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;                            
        }
    }
    return -1;
}



int main()
{
    int arr[] = {'R', 'o', 'm', 'a', 'n'};
    int size = sizeof(arr) / sizeof(arr[0]);
    char target;
    
    cout << "Enter a char to search: ";
    cin >> target;
    
    
    int result = linearSearch(arr, size, target);
    
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    
    else
    {
        cout << "Element not found." << endl;
    }

    return 0;
}

