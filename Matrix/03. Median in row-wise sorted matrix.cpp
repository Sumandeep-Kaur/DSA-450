/*
    Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.
    Example:    Input: R = 3, C = 3,  M = [[1, 3, 5], 
                                          [2, 6, 9], 
                                          [3, 6, 9]]
                Output: 5          

    Time Complexity: O(32*R*logC) 
    Space Complexity: O(1)
*/

/*Store all the elements of matrix in array of size r*c, sort the array and find the median(arr[(r*c)/2]) in O(r*clog(r*c))*/

#include <bits/stdc++.h>
using namespace std;

int median(vectorvector<int>>& matrix, int r, int c)
{
    int mn = INT_MAX, mx = INT_MIN;
    for(int i = 0; i < r; i++) {
        mn = min(mn, matrix[i][0]);
        mx = max(mx, matrix[i][c-1]);
    }
    int desired_count = (1+(r*c)/2));
    while(mn < mx) {
        int mid = mn + (mx - mn)/2;
        int count = 0;
        for(int i = 0; i < r; i++)
            count += upper_bound(matrix[i], matrix[i]+c, mid) - matrix[i];
        /*gives the iterator pointing to the first element strictly greater than its third parameter(mid here)*/
        if(count < desired_count)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mid;
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
    cout << median(matrix, r, c) << "\n";
    return 0;
}

/*The upper bound function will take log(c) time and is performed for each row. 
And since the numbers will be max of 32 bit, so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations. */