/*  C++ program to reverse an array.   
    Example:    Input: 3, 5, 1, 9, 6, 4
                Output: 4, 6, 9, 1, 5, 3
    Time complexity: O(n)  
    Space Complexity: O(1) 
*/

#include <iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
    int start = 0, end = n-1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
    reverseArray(arr, n);
    cout << "Reversed array is: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}