/*
    Consider space {1,4,9,16,...} Find the number of perfect squares less than N in the sample space S.
    Example:    Input: 9
                Output: 2

    Time Complexity: O(sqrt(n)) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int countSquares(int n)
{
    int count = 0;
    for (int i = 1; i * i < n; i++)
        count++;
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << countSquares(n) << "\n";
    return 0;
}