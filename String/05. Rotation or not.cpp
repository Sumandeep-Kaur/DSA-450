/*
    Check whether str2 is a rotation of str1 or not. 
    Example:    Input: str1 = "abcd", str2 = "cdab"
                Output: 1

    Time Complexity: O(n1+n2) //Method 1 
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/* Create a temp string and store concatenation of str1 to str1 in temp (temp = str1 + str1)
If str2 is a substring of temp then str1 and str2 are rotations of each other. */
bool areRotations(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
    /*find() returns the index of the first occurrence of the substring in the string from given starting position*/
    /*It is a constant static member value with the highest possible value for an element of type size_t.
    It actually means until the end of the string.*/
}

/*Push strings str1 & str2 into a queue q1 & q2 resp.
Keep popping q2‘s and pushing it back into it till the number of such operations are less than the size of the string.
If q2 becomes equal to q1 at any point during these operations, it is possible. Else not.*/
bool areRotations(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    queue<char> q1;
    for (int i = 0; i < str1.size(); i++) 
        q1.push(str1[i]);
    
    queue<char> q2;
    for (int i = 0; i < str2.size(); i++) 
        q2.push(str2[i]);
    
    int k = str2.size();
    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << areRotations(str1, str2);
    return 0;
}
