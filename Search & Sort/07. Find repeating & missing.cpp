/*
    Given an unsorted array arr of size n of positive integers. 
    One number 'a' from set {1, 2, …n} is missing and one number 'b' occurs twice in array. Find these two numbers.
    Example:    Input: {1, 3, 3}
                Output: 3 2

    Time Complexity: O(n) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Sort TC: O(n*logn) & SC: O(logn) 
// 2. Using Map TC: O(n) & SC: O(n) 
// 3. Use elements as Index and mark the visited places. TC: O(n) & SC: O(n)
void findTwoElements(int arr[], int n)
{
    cout << "Repeating element is ";
    for (int i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }

    cout << "Missing element is ";
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            cout << (i + 1) << "\n";
    }
}
/*  Swap numbers to their sorted positions. TC: O(n) & SC: O(n)
void findTwoElement(int *arr, int n)
{
    int i = 0;
    while (i < n) {
        if (arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i] - 1]);
        else
            i++;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << "Missing number = " << i+1 << "\n";
            cout << "Repeating number = " << arr[i] << "\n";
            break;
        }
    }
}
*/
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    findTwoElements(arr, n);
    return 0;
}
