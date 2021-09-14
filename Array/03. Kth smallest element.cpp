/*
    To find the Kth smallest element in the given array. It is given that all array elements are distinct.
    Example:    Input: nums = [3,2,1,5,6,4] & k = 2
                Output: 2
    Time Complexity: O(nlogk)
    Space Complexity: O(k)
*/

#include<bits/stdc++.h>
using namespace std;

/*  
// Method 1: Using Sorting   **TC: O(nlogn)**
int kthSmallest(int arr[], int n, int k)
{
    // Sort given array and return k'th element in the sorted array.
    sort(arr, arr + n);
    return arr[k - 1];
}
*/

// Method 2: Using Heap   **TC: O(nlogk)**
int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> max_heap;
    for(int i = 0; i < n; i++){
        max_heap.push(arr[i]);
        if(max_heap.size() > k)
            max_heap.pop();
    }
    return max_heap.top();
}

int main()
{
    int n, k;
    cin >> n, k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << kthSmallest(arr, n, k) << endl;
    return 0;
}


