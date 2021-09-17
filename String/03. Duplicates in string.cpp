/*
    To find duplicates in string.
    Example:    Input: "aeroplane"
                Output: a: count = 2 
                        e: count = 2

    Time Complexity: O(n)    ** Using hashing and unordered_map **
    Space Complexity: O(k) //k=no. of chars or size of map
*/

#include <bits/stdc++.h>
using namespace std;

void duplicates(string s)
{
    unordered_map<char, int> count;           //TC= O(n) n: traverse & O(1): insertion in map
    for(int i = 0; i < s.length(); i++){       //Using map TC = O(nlogn) as insertion will be O(logn)
        count[s[i]]++;
    }
    for(auto it:count){
        if(it.second > 1)
            cout << it.first << ": count = " << it.second << "\n";
    }
}

int main()
{
    string str;
    cin >> str;
    duplicates(str);
    return 0;
}