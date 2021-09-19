/*
    Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
    Example:    Input: 1, 2, 3, -2, 5
                Output: 9

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    int cursum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++) {
        cursum += arr[i];
        if (cursum < 0)
            cursum = 0;
        maxsum = max(maxsum, cursum);
    }
    return maxsum;
}

int main() 
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i]; 

    cout << maxSubarraySum(a, n) << endl;
    return 0;
}