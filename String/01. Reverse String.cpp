/*
    To reverse a string inplace.
    Example:    Input: "hello"
                Output: "olleh"

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void reverse(string s)
{
    int start = 0, end = s.length() - 1;
    while(start < end){
        swap(s[start++], s[end--]);
    }
}

int main()
{
    string str;
    cin >> str;
    reverse(str);
    cout << str << "\n";
    return 0;
}