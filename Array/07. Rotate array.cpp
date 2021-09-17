/*
    Cyclically rotate array by d clockwise.
    Example:    Input: nums = [1,2,3,4,5,6] and d = 2;
                Output: [3,4,5,6,1,2]

    Time Complexity: O(n)
    Space Complexity: O(d)
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(int a[], int n, int d)
{
    int temp[d];
    for(int i = 0; i < d; i++)
        temp[i] = a[i];
    for(int i = 0; i < n-d; i++)
        a[i] = a[i+d];
    for(int i = d, j = 0; i < n, j < d; i++, j++)
        a[i] = temp[j];
}

int main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    rotate(arr, n, d);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
