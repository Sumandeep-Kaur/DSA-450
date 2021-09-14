/*
    Move all negative numbers to beginning and positive numbers to end with constant extra space.
    Example:    Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
                Output: -12, -13, -5, -7, -3, -6, 11, 6, 5

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

//The idea is to simply apply the partition process of quicksort. TC: O(n)
void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] < 0 && i != j){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// Two pointer approach.  TC: O(n)
void rearrange(int arr[], int n)
{
    int left = 0, right = n-1;
    while (left <= right){
        // if the left and the right elements are negative
        if (arr[left] < 0 && arr[right] < 0)
            left++;

        // if the left pointer element is positive and the right pointer element is negative
        else if (arr[left] > 0 && arr[right] < 0){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }

        // if both the elements are positive
        else if (arr[left] > 0 && arr[right] > 0)
            right--;

        // if the left pointer element is negative and the right pointer element is positive
        else{
            left++;
            right--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    rearrange(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}