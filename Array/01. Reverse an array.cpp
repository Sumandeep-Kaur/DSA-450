/*  C++ program to reverse an array.   
    Example:    Input: 3, 5, 1, 9, 6, 4
                Output: 4, 6, 9, 1, 5, 3
    Time complexity: O(n)  
    Space Complexity: O(1) 
*/

#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

//function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

//driver function
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    //print original array
    cout << "Input array is: " << endl;
    printArray(arr, n);
    //function calling
    reverseArray(arr, 0, n - 1);
    cout << "Reversed array is: " << endl;
    //print the reversed array
    printArray(arr, n);
    return 0;
}