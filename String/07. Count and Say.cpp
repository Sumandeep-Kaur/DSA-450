/*
    The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
    countAndSay(1) = "1"
    countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
    Ex: For "3322251" next term will be "23321511" i.e, Two 3s, Three 2's, One 5's, One 1's 
    For given n return the nth term of the count-and-say sequence.
    Example:    Input: 4
                Output: 1211

    Time Complexity: O(m*n)    
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string str = "1";
    for (int i = 2; i <= n; i++) {
        string temp = "";
        str += '/';
        int count = 1;
        for (int j = 1; j < str.length(); j++) {
            if (str[j] != str[j - 1]) {
                temp += to_string(count);
                temp += str[j - 1];
                count = 1;
            }
            else
                count++;
        }
        str = temp;
    }
    return str;
}

int main()
{
    int n;
    cin >> n;
    cout << countAndSay(n) << "\n";
    return 0;
}