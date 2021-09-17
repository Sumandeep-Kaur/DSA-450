/*
    Spiral traversal of matrix.
    Example:    Input: nums =   {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15,16}}
                Output: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10

    Time Complexity: O(row*col)
    Space Complexity: O(r*c) //for answer only
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralTraverse(int r, int c, int matrix[][c])
{
    int top = 0, left = 0, bottom = r - 1, right = c - 1, dir = 0;
    vector<int> v;
    while (top <= bottom && left <= right){
        if (dir == 0){
            for (int i = left; i <= right; i++)
                v.push_back(matrix[top][i]);
            top++;
        }
        else if (dir == 1){
            for (int i = top; i <= bottom; i++)
                v.push_back(matrix[i][right]);
            right--;
        }
        else if (dir == 2){
            for (int i = right; i >= left; i--)
                v.push_back(matrix[bottom][i]);
            bottom--;
        }
        else if (dir == 3){
            for (int i = bottom; i >= top; i--)
                v.push_back(matrix[i][left]);
            left++;
        }
        dir = (dir + 1) % 4;
    }
    return v;
}

int main()
{
    int r, c;
    cin >> r >> c;
    int matrix[r][c] = {0};

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];
    }
    vector<int> result = spiralTraverse(r, c, matrix);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << "\n";
    return 0;
}