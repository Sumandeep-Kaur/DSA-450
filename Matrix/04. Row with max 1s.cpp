/*
    Given a boolean n x m matrix where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.
    Example:    Input: R = 3, C = 4,  M = [[0, 1, 1, 1], 
                                          [0, 0, 1, 1], 
                                          [1, 1, 1, 1]]
                Output: 2          

    Time Complexity: O(n+m) 
    Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

int rowWithMax1s(bool arr[n][m])
{
    int j = m-1, maxRowIndex = 0;
    for (int i = 0; i < R; i++) {
        bool flag = false; //to check whether a row has more 1's than previous
        while (j >= 0 && arr[i][j] == 1) {
            j = j - 1;   // Update the index of leftmost 1 seen so far
            flag = true; //present row has more 1's than previous
        }
        if (flag)   // if the present row has more 1's than previous
            maxRowIndex = i; // Update max row index
    }
    if (maxRowIndex == 0 && arr[0][m - 1] == 0)
        return -1;
    return maxRowIndex;
}
/*
int rowWithMax1s(bool arr[n][m])
{
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr[i][j] == 1)
            return i;
        if (i == n - 1) {
            i = 0;
            j++;
        }
        else
            i++;
    }
    return -1;
}
*/

int main()
{
    int r, c;
    cin >> r >> c;
    bool matrix[r][c];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];
    }
    cout << rowWithMax1s(r, c, matrix) << "\n";
    return 0;
}


/*
// Binary Search Solution TC: O(m*logn)
int first(bool arr[], int low, int high)
{
    if(low <= high) {
        int mid = low + (high - low)/2;
     
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)     // Check if the element at middle index is first 1
            return mid;
        else if (arr[mid] == 0)                                 // If the element is 0, recur for right side
            return first(arr, (mid + 1), high);
        else                                                   // If element is not first 1, recur for left side
            return first(arr, low, (mid -1));                  
    }
    return -1;
}
int rowWithMax1s(bool mat[R][C])
{
    int maxRowIndex = 0, max = -1;
 
    // Traverse for each row and count number of 1s by finding the index of first 1
    int i, index;
    for (i = 0; i < R; i++) {
        index = first (mat[i], 0, C-1);
        if (index != -1 && C-index > max) {
            max = C - index;
            maxRowIndex = i;
        }
    }
 
    return maxRowIndex;
}
*/