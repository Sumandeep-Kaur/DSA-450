/*
    Given an array arr[] denoting heights of n towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
    Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.
    Example:    Input: K = 2, N = 4, arr[] = {1, 5, 8, 10}
                Output: 5       // {3, 3, 6, 8} =(8-3)

    Time Complexity: O(nlogn)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int diff = arr[n - 1] - arr[0];
    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] < k)
            continue;
        int curMin = min(arr[0] + k, arr[i + 1] - k);      
        int curMax = max(arr[n - 1] - k, arr[i] + k);        
        diff = min(diff, curMax - curMin);
    }
    return dif;
}

int main()
{
    int n, k;
    cin >> k >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    cout << getMinDiff(arr, n, k) << "\n";
    return 0;
} 