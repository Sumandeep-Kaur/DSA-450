/*
    Given an array of integers and key x where each element has a difference of at most k with its neighbor, find the index value of x in array. 
    If multiple-element exist, return the first occurrence of the key.
    Example:    Input: arr[] = {4, 5, 6, 7, 6},  k = 1,  x = 6
                Output: 2 

    Time Complexity: O(n) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Key idea: x must be at least ‘diff/k’ away, so instead of searching one by one, jump ‘diff/k’. 
int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n) {
        // If x is found at index i
        if (arr[i] == x)           
            return i;
 
        // Jump the difference between current array element and x divided by k(max is used for atleast one step jump)
        i = i + max(1, abs(arr[i]-x)/k);
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int x, k;
    cin >> x >> k;
    cout << search(arr, n, x, k) << "\n";
    return 0;
}
