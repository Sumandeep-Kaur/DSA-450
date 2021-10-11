/*
    Given a string S. Print all permutations of a given string.
    Example:    Input: "abc"
                Output: {"abc", "acb", "bac", "bca", "cab", "cba"}

    Time Complexity: O(n!*n)    
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

void permute(vector<string>& v, string s, int j)
{
    if(j == s.length())
        v.push_back(s);
    else{
        for(int i = j; i < s.length(); i++) {
            swap(s[i], s[j]);
            permute(v, s, j+1);
            swap(s[i], s[j]);
        }
    }
}

vector<string> permutations(string s)
{
    vector<string> v;
    permute(v, s, 0);
    return v;
}

int main()
{
    string str;
    cin >> str;
    vector<string> res = permutations(str);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}