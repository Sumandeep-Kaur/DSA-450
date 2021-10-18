/*
    Write a program to reverse a stack using recursion. You are not allowed to use loops and you can only use the following ADT functions on Stack S: 
    isEmpty(S), push(S), pop(S)
    Example:    Input: {1, 2, 3, 4}
                Output: {4, 3, 2, 1}

    Time Complexity: O(n)   
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

stack<int> st;

void pushAtBottom(int t)
{
    if (st.size() == 0) {
        st.push(t);
        return;
    }
    else {
        int val = st.top();
        st.pop();
        pushAtBottom(t);
        st.push(val);
        return;
    }
}

void reverse()
{
    if (st.size() == 1)
        return;
    int temp = st.top();
    st.pop();
    reverse();
    pushAtBottom(temp);
    return;
}

int main()
{
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse();
    cout << "\nReversed Stack" << endl;

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}