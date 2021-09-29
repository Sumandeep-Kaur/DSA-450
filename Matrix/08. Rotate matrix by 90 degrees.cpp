/*
    Rotate a matrix by 90 degree in clockwise direction without using any extra space.
    Example:    Input: R = 3, C = 3,  M = [[1, 2, 3], 
                                           [4, 5, 6], 
                                           [7, 8, 9]]
                Output: [[7, 4, 1], 
                         [8, 5, 6], 
                         [9, 6, 3]]   

    Time Complexity: O(n*n) 
    Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

// Cycle swapping method
void rotate(int a[n][n])
{
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = a[i][j];
            a[i][j] = a[n - 1 - j][i];
            a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
            a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
            a[j][n - 1 - i] = temp;
        }
    }
}

// Transpose method
void rotate(int arr[n][n])
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++)
            swap(arr[i][j], arr[j][i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++)
            swap(arr[i][j], arr[i][n - j - 1]);
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
    rotate(matrix);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << matrix[i][j];
    }
    return 0;
}