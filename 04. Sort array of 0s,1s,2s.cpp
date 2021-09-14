/*
    Sort an array of size n containing only 0s, 1s, and 2s in ascending order without using any sorting algo.
    Example:    Input: 0, 2, 1, 2, 0
                Output: 0, 0, 1, 2, 2
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high){
        switch (arr[mid]){
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
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
    sort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}