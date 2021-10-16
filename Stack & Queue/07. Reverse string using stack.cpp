/*
    Reverse string str using stack.
    Example:    Input: "hello"
                Output: "olleh"

    Time Complexity: O(n)   n = str.length()
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    stack<char> st;
    for(int i = 0; i < s.length(); i++)
        st.push(s[i]);

    int i = 0;
    while(!st.empty()){
        s[i++] = st.top();
        st.pop();
    }
    return s;
}

int main()
{
    string str;
    cin >> str;
    cout << reverse(str) << "\n";
    return 0;
}