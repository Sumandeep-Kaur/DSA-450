/*
    Check if a string is a valid shuffle of two distinct strings. 
    Example:    Input: str1 = "XY", str2 = "12" res = "X1Y2"
                Output: 1

    Time Complexity: O(n)  n = res.length() 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool check(string s1, string s2, string res)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int l = res.length();
    if(l1 + l2 != l)
        return false;
    int i = 0, j = 0, k = 0;    //i->s1, j->s2, k->res
    while(k < l){
        if (i < l1 && s1[i] == res[k])
            i++;
        else if (j < s2 && s2[j] == res[k])
            j++;
        else
            return false;
        k++;
    }
    if(i < l1 || j < l2)
        return false;
    else
        return true;
}

int main()
{
    string s1, s2, res;
    cin >> s1 >> s2 >> res;
    cout << check(s1, s2, res) << "\n";
    return 0;
}