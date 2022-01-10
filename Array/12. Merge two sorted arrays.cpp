/*
    Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. 
    Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
    Example:    Input: arr1[] = {1, 4, 7, 8, 10} & arr2[] = {2, 3, 9}
                Output: arr1[] = {1, 2, 3, 4, 7} & arr2[] = {8, 9, 10}

    Time Complexity: O(logn)  //Gap-Method
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

//Two Pointer Approach | TC: O(n*m)
/* loop arr1, compare it with first element of second array, if it is greater than arr2[0], then swap and sort the second array */
void merge(int arr1[], int arr2[], int n, int m)
{
    for (int i = 0; i < n; i++) {
        if (arr1[i] > arr2[0])
            swap(arr1[i], arr2[0]);

        // insertion sort is used here
        int first = arr2[0];
        for (int k = 1; k < m && arr2[k] < first; k++) {
            arr2[k - 1] = arr2[k];
        }
        arr2[k - 1] = first;
    }
}

//Gap Method Approach | TC: O(logn)
void merge(int ar1[], int ar2[], int n, int m)
{
    int gap = ceil((float)(n + m) / 2);
    while (gap > 0) {
        int i = 0;
        int j = gap;
        while (j < (n + m)) {
            if (j < n && ar1[i] > ar1[j])
                swap(ar1[i], ar1[j]);
            else if (j >= n && i < n && ar1[i] > ar2[j - n])
                swap(ar1[i], ar2[j - n]);
            else if (j >= n && i >= n && ar2[i - n] > ar2[j - n])
                swap(ar2[i - n], ar2[j - n]);
            j++;
            i++;
        }
        if (gap == 1)
            gap = 0;
        else
            gap = ceil((float)gap / 2);
    }
}

int main()
{
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    
    merge(arr1, arr2, 5, 3);
    cout << "After merge:" << endl;
    for (int i = 0; i < 5; i++)
        cout << arr1[i] << " ";
    cout << endl;
    for (int i = 0; i < 3; i++)
        cout << arr2[i] << " ";

    return 0;
}