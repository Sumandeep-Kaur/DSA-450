/*
    Search a value in an m x n matrix. This matrix has the following properties:
    Integers in each row are sorted from left to right and the first integer of each row is greater than the last integer of the previous row.
    Example:    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3 
                Output: true

    Time Complexity: O(logm + logn) = O(log(mn)) 
    Space Complexity: O(1) 
*/

/* We can treat whole matrix as just sorted array and apply simple one binary search, 
but can cause multiplication overflow of high(= m*n-1) and also it involves expensive operations(%, /) */

#include <iostream>
using namespace std;

// Binary search by row first, then binary search by column
bool searchMatrix(vector<vector<int>> &m, int target)
{
    if (!m.size() || !m[0].size())          // Edge-case
        return false;
    int row, low = 0, high = m.size() - 1, mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (m[mid].back() < target)
            low = mid + 1;
        else if (m[mid][0] > target)
            high = mid - 1;
        else {
            low = mid;
            break;
        }
    }

    row = low; // storing the value of the new found row
    low = 0;   // resetting low and high to run a binary search on the rows
    high = m[0].size() - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (m[row][mid] < target)
            low = mid + 1;
        else if (m[row][mid] > target)
            high = mid - 1;
        else
            return true;
    }
    return false;
}


int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int> matrix(r, vector<int> (c, 0));
    for (int i = 0; i < r; i++){
        vector<int> v;
        for (int j = 0; j < c; j++){
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        matrix.push_back(v);
    }
    int target;
    cin >> target;
    cout << searchMatrix(matrix, target) << "\n";
    return 0;
}