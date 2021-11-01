/*
    Divide two integers without using multiplication, division and mod operator.
    Example:    Input: a = 10  b = 3
                Output: 3

    Time Complexity: O(a) 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/* Keep subtracting the dividend from the divisor until dividend becomes less than divisor. 
The dividend becomes the remainder, and the number of times subtraction is done becomes the quotient.*/
int divide(int dividend, int divisor) 
{
    int quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }

    return quotient;
}

int divide(int dividend, int divisor) 
{
    int quotient = 0, temp = 0;

    // test down from the highest bit and accumulate the tentative value for valid bit
    for (int i = 31; i >= 0; --i) {
        if (temp + (divisor << i) <= dividend) {
            temp += divisor << i;
            quotient |= 1LL << i;
        }
    }
    
    return quotient;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << divide(a, b) << "\n";
    return 0;
}