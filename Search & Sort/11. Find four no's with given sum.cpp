/*
    Given an array of integers and another number. Find all the UNIQUE quadruple from the given array that sums up to the given number.
    Example:    Input: arr[] = {10,2,3,4,5,7,8} &  sum = 23
                Output: [[2 3 8 10], [2 4 7 10], [3 5 7 8]] 

    Time Complexity: O(n^3) 
    Space Complexity: O(n*n)   //for answer
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Brute force: using four loops  TC: O(n^4)
// 2. Using Sort  TC: O(n^3)
vector<vector<int> > fourSum(vector<int> &arr, int sum) {
    sort(arr.begin(), arr.end());
    int low, high;
    vector<vector<int>> ans;
    int n = arr.size();
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            low = j + 1;
            high = n - 1;
            while (low < high) {
                if (arr[i] + arr[j] + arr[low] + arr[high] == sum) {
                    ans.push_back({arr[i], arr[j], arr[low], arr[high]});
                    while (low < high && arr[low] == arr[low + 1])      //For duplicates
                        low++;
                    while (low < high && arr[high] == arr[high - 1])    //For duplicates
                        high--;
                    low++;
                    high--;
                }
                else if (arr[i] + arr[j] + arr[low] + arr[high] < sum)
                    low++;
                else
                    high--;
            }
            while (j < n - 3 && arr[j] == arr[j + 1])    //For duplicates
                j++;
        }
        while (i < n - 4 && arr[i] == arr[i + 1])       //For duplicates
            i++;
    }
    return ans;
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> ans = fourSum(arr, sum);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < 4; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
