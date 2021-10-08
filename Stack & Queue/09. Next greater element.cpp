/*
    Find next greater element for each element of the array in order of their appearance in the array.
    Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
    Example:    Input: {6, 8, 0, 1, 3}
                Output: {8, -1, 1, 3, -1}

    Time Complexity: O(n)   
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr, int n)
{
    vector<int> v;
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        if (s.size() == 0)
            v.push_back(-1);
        else if (s.size() > 0 && s.top() > arr[i])
            v.push_back(s.top());
        else if (s.size() > 0 && s.top() <= arr[i]) {
            while (s.size() > 0 && s.top() <= arr[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> res = nextGreaterElement(arr, n);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
