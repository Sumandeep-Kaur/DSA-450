/*
    Given an array arr[] of size n and a number k, find if there exists a pair of elements in the array whose difference is k.
    Example:    Input: arr[] = {5, 20, 3, 2, 5, 80} &  k = 78
                Output: 1 

    Time Complexity: O(n*logn) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Using two loops  TC: O(n*n)
// 2. Sort and Binary Search  TC: O(n*logn)
bool findPair(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int i = 0, j = 1;
 
    while (i < n && j < n) {
        if (i != j && (arr[j] - arr[i] == k || arr[i] - arr[j] == k) ) 
            return true;
        else if (arr[j] - arr[i] < k)
            j++;
        else
            i++;
    }
    return false;
}
 

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findPair(arr, n, k) << "\n";
    return 0;
}
