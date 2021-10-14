/*
    Given an array of n integers, and an integer k, find the number of pairs of elements in the array whose sum is equal to k.
    Example:    Input: nums = {1, 5, 7, 1} and k = 6
                Output: 2

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Brute force TC: O(n^2)
// 2. Using sort TC: O(nlogn)
// 3. Using map  TC: O(n)
int pairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (mp.find(k - arr[i]) != mp.end()) {
            count += mp[k - arr[i]];
        }
        mp[arr[i]]++;
    }
    return count;

    /*
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    int twice_count = 0;
 
    // iterate through each element and increment the count (notice that every pair is counted twice)
    for (int i = 0; i < n; i++) {
        twice_count += mp[sum - arr[i]];
 
        // if (arr[i], arr[i]) pair satisfies the condition, then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i]) pair is not considered
        if (sum - arr[i] == arr[i])
            twice_count--;
    }
 
    // return the half of twice_count every pair has counted twice
    return twice_count / 2;
    */
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << pairsCount(arr, n, k) << "\n";
    return 0;
}
