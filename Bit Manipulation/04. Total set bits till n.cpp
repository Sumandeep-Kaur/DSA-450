/*
    Given a number n, Find total number of set bits for all numbers from 1 to n(both inclusive)
    Example:    Input: 4
                Output: 5

    Time Complexity: O(logn) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int largestPowerOfTwo(int n)
{
    int x = 0;
    while((1 << x) <= n)
        x++;
    return x - 1;
}

// 1. Using loop till n and count set bits of all numbers  TC: O(n*logn)
// 2. TC: O(logn)
/* From 1 to lowest perfect power of two(a), set bits are x * 2^(x-1) and then from a to n count MSB of all by n - a + 1
and now the remaining no's will be like 0,1,2..(n-a). Recursively count for these no's by calling function for n - a */
int totalSetBits(int n)
{
    if (n <= 1)
        return n;
    int x = largestPowerOfTwo(n);
    return (x * pow(2, (x-1))) + (n - pow(2, x) + 1) + totalSetBits(n - pow(2, x));
}

int main()
{
    int n;
    cin >> n;
    cout << totalSetBits(n) << "\n";
    return 0;
}
