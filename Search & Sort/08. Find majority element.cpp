/*
    Find the majority element in an array of size n. A majority element is an element that appears more than n/2 times in the array.
    Return -1 if there is no majority element.
    Example:    Input: {3,1,3,3,2} 
                Output: 3 

    Time Complexity: O(n) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Checking maximum count TC: O(n*n)  &  SC: O(1)
// 2. Sort TC: O(n*logn) & SC: O(1) 
// 3. Using Map TC: O(n) & SC: O(n) 
// 4. Boyer-Moore's Voting Algorithm TC: O(n) & SC: O(1)

int findCandidate(int a[], int n)
{
    int majIndex = 0, count = 1;
    for (int i = 1; i < n; i++) {
        if (a[majIndex] == a[i])
            count++;
        else
            count--;
        if (count == 0) {
            majIndex = i;
            count = 1;
        }
    }
    return a[majIndex];
    // returns majority element, otherwise, it will return candidate for majority element.
}

int printMajority(int a[], int n)
{
    // Find the candidate for Majority
    int cand = findCandidate(a, n);         

    // Check if our candidate is majority element or not
    int count = 0;
    for (int i = 0; i < n; i++){ 
        if (a[i] == cand)
            count++;
    }
    if (count > n / 2)
        return cand;
    else
        return -1;
}

/* If majority element always exists in the array.
int majorityElement(int nums[], int n)
{
    int count = 0;
    int candidate;

    for (int i = 0; i < n; i++) {
        if (count == 0)
            candidate = nums[i];
        if (nums[i] == candidate)
            count++;
        else
            count--;
    }
    return candidate;
}*/

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << printMajority(arr, n) << "\n";
    return 0;
}
