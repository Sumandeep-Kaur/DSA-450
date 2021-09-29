/*
    Given an array prices where prices[i] is the price of a given stock on the ith day.
    Return the maximum profit you can achieve buying stock on one day and selling someday in future. If you cannot achieve any profit, return 0.
    Example:    Input: 7,1,5,3,6,4
                Output: 5

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int prices[], int n)
{

    int buyPrice = INT_MAX, profit = 0;
    for (int i = 0; i < n; i++) {
        buyPrice = min(buyPrice, prices[i]);
        profit = max(profit, prices[i] - buyPrice);
    }
    return profit;
}

int main() 
{
    int n;
    cin >> n;
    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << maxProfit(prices, n) << endl;
    return 0;
}