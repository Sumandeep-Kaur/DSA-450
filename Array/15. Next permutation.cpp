/*
    Implement next permutation i.e, lexicographically next greater permutation of numbers - do inplace and use only constant extra space.
    If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
    Example:    Input: [1,2,3]
                Output: [1,3,2]

    Time Complexity: O(nlogn)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/* Find first pair of two successive numbers from the right such that a[i] > a[i-1]. 
No rearrangements to the left of a[i-1] can create a larger permutation, thus rearrange no's to the right of a[i-1] including itself.
Replace a[i-1] with no. just larger than itself among the numbers lying to its right, say a[j].
Now, Reverse the numbers following a[i-1](right side make it in inc order) to get the next smallest lexicographic permutation.*/
void nextPermutation(int a[], int n)
{
    int i = n - 2;
    while (i >= 0 && a[i + 1] <= a[i])
        i--;
    if (i >= 0) {
        int j = n - 1;
        while (a[j] <= a[i])
            j--;
        swap(a[i], a[j]);
    }
    reverse(a, i+1, n-1);
}

void reverse(int a[], int start, int end)
{
    while (start < end) {
        swap(a[start], a[end]);
        start++;
        end--;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    nextPermutation(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}