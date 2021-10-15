/*
    Given a string containing the characters '(', ')', '{', '}', '[' and ']', determine if the input string is balanced. 
    Example:    Input: "[()]{}{[()()]()}""
                Output: 1

    Time Complexity: O(n)   n = str.length()
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            st.push(str[i]);

        if (st.empty())
            return 0;

        int x;
        switch (str[i]) {
        case ')':
            x = st.top();
            st.pop();
            if (x == '{' || x == '[')
                return 0;
            break;
        case '}':
            x = st.top();
            st.pop();
            if (x == '(' || x == '[')
                return 0;
            break;
        case ']':
            x = st.top();
            st.pop();
            if (x == '{' || x == '(')
                return 0;
            break;
        }
    }
    return (st.empty());
}

int main()
{
    string str;
    cin >> str;
    cout << isValid(str) << "\n";
    return 0;
}