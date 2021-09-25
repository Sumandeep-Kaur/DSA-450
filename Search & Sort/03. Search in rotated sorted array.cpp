/*
    Search a target element in sorted array with distinct values rotated at unknown pivot index k. Return -1 if not found.
    Example:    Input: nums = [4,5,6,7,0,1,2], target = 0
                Output: 4

    Time Complexity: O(logn) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int search(int nums[], int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (nums[mid] == target)
            return mid;
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, target;
    cin >> n >> target;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << search(arr, target) << "\n";
    return 0;
}