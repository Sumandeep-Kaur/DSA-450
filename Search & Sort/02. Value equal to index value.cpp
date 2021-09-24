/*
    Given an array Arr of N positive integers. Find all the elements whose value is equal to that of its index value ( Consider 1-based indexing ).
    Example:    Input: 15, 2, 45, 12, 7
                Output: 2 

    Time Complexity: O(n) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> valueEqualToIndex(int arr[], int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (arr[i] == i + 1)
            v.push_back(arr[i]);
    }
    return v;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = valueEqualToIndex(arr, n);
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}