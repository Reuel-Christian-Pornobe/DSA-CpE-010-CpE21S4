// Write a C++ program to reverse the order of the items in the array. Original array: numbers = [5,4,3,2,1]

#include<iostream>
using namespace std;


int main()
{
   int numbers[5] = {5,4,3,2,1};   //Normal array
   int rNumbers[5];               //array that will be reversed
   
   cout << "Normal Array: ";      
   for (int i = 0; i < 5; i++)      // printing the normal order of the array
   {
       cout << numbers[i] << ", ";
   }
   
   cout << endl;
   
   cout << "Reversed Array: ";
   for (int i = 4; i >= 0; i--)
   {
       int i2 = 0;                 //index for the reversed array
       int x = numbers[i];         // putting the value of numbers[] from index 4 to 0 to a variable x
       rNumbers[i2] = x;           // putting the value of x to rNumbers from index 0 to 4
       cout << rNumbers[i2] << ", "; //printing the reversed output
   }
   
   

    return 0;
}