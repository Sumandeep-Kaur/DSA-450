/*
    Find first and last positions of an element in a sorted array. Return -1 if x is not found.
    Example:    Input: arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}    x = 5
                Output: First=2, Last=5 

    Time Complexity: O(logn) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int first(int a[], int n, int x)
{
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(a[mid] == x){
            first = mid;
            high = mid-1;
        }
        else if(a[mid] > x)
            high = mid-1;
        else
            low = mid + 1;
    }
    return first;
}
int last(int a[], int n, int x)
{
    int low = 0, high = n-1;
    int last = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(a[mid] == x){
            last = mid;
            low = mid+1;
        }
        else if(a[mid] > x)
            high = mid-1;
        else
            low = mid + 1;
    }
    return last;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "First= " << first(arr, n, x) << ", Last= " << last(arr, n , x) << "\n";
    return 0;
}
