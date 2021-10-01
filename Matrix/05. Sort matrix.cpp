/*
    Given an n X n matrix. Sort all elements of the matrix.
    Example:    Input: n = 4;   M = [[10,20,30,40],
                                    [15,25,35,45], 
                                    [27,29,37,48], 
                                    [32,33,39,50]]
                Output: [[10, 15, 20, 25],
                         [27, 29, 30, 32], 
                         [33, 35, 37, 39], 
                         [40, 45, 48, 50]]  

    Time Complexity: O(n*n*logn) 
    Space Complexity: O(n*n)
*/

#include<iostream>
using namespace std;

void sortMatrix(int matrix[n][n], int n)
{
    vector<int> v(n*n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            v.push_back(matrix[i][j]);
    }
    sort(v.begin(), v.end());
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            matrix[i][j] = v[k++];
    }
}

int main()
{
    int n;
    cin n;
    int matrix[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    sortMatrix(matrix, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << matrix[i][j];
    }
    return 0;
}