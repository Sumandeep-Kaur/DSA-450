/*
    Find the middle of three numbers using minimum number of comparisons.
    Example:    Input: 978, 518, 300
                Output: 518 

    Time Complexity: O(1) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int middle(int A, int B, int C)
{
    if ((A > B && A < C) || (A > C && A < B))
        return A;
    else if ((B > A && B < C) || (B > C && B < A))
        return B;
    else
        return C;
}
/*
int middle(int A, int B, int C)
{
    int mx = max(A, max(B, C));
    int mn = min(A, min(B, C));
    return ((A + B + C) - (mx + mn));
}

int middle(int A, int B, int C)
{
    int x = A - B;
    int y = B - C;
    int z = C - A;
    if (x * y > 0)
        return B;
    else if (y * z > 0)
        return C;
    else
        return A;
}
*/
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << middle(a, b, c) << "\n";
    return 0;
}
