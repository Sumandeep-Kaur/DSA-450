/*
    To check whether a string is palindrome or not.
    Example:    Input: "abba"
                Output: 1

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string s)
{
    int start = 0, end = s.length()-1;
    while(start < end){
        if(s[start++] != s[end--])
            return 0;
        return 1;
    }
}

int main()
{
    string str;
    cin >> str;
    cout << isPalindrome(str);
    return 0;
}