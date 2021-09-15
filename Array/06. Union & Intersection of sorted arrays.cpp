/*
    Move all negative numbers to beginning and positive numbers to end with constant extra space.
    Example:    Input:  arr1[] = {1, 3, 4, 5, 7} ,  arr2[] = {2, 3, 5, 6} 
                Output: Union = {1, 2, 3, 4, 5, 6, 7} , Intersection = {3, 5}

    Time Complexity: O(m+n)
    Space Complexity: Union => O(m+n), Intersection => O(min(m, n)) if answers to be stored in array
*/

#include <bits/stdc++.h>
using namespace std;

// Two-Pointer Approach 
vector<int> union(int a1[], int a2[])
{
    int n = sizeof(a1)/sizeof(a2[0]);
    int m = sizeof(a1)/sizeof(a2[0]);
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a1[i] < a2[j])
            ans.push_back(a1[i++]);
        else if (a1[i] > a2[j])
            ans.push_back(a2[j++]);
        else {
            ans.push_back(a2[j++]);
            i++;
        }
    }
    while (i < n)
        ans.push_back(a1[i++]);
    while (j < m)
        ans.push_back(a2[j++]);
    return ans;
}

// Two-Pointer Approach 
vector<int> intersection(int a1[], int a2[])
{
    int n = sizeof(a1)/sizeof(a2[0]);
    int m = sizeof(a1)/sizeof(a2[0]);
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m){
        if (a1[i] < a2[j])
            i++;
        else if (a1[i] > a2[j])
            j++;
        else{
            ans.push_back(a2[j++]);
            i++;
        }
    }
    return ans;
}

int main()
{
    int arr1[] = {1, 3, 4, 5, 7};
    int arr2[] = {2, 3, 5, 6};
    
    vector<int> uni = union(arr1, arr2);
    cout << "Union: ";
    for(int i = 0; i < uni.size(); i++)
        cout << uni[i] << " ";
    cout << "\n";

    vector<int> intersect = intersection(arr1, arr2);
    cout << "Intersection: ";
    for(int i = 0; i < intersect.size(); i++)
        cout << intersect[i] << " ";
    cout << "\n";

    return 0;
}

/*
// Using Map
void union(int a1[], int a2[])
{
    unordered_map<int, int> mp;
    vector<int> intersect;
    for(int i = 0; i < a1.size(); i++)
        mp[a1[i]]++;
    for(int i = 0; i < a2.size(); i++)
        mp[a2[i]]++;
    
    cout << "Union: ";
    for(auto it : mp) {
        cout << it.first << " ";
        if(it.second > 1)
            intersect.push_back(it.first);
    }
    cout << "\nIntersection: ";
    for(int i = 0; i < intersect.size(); i++)
        cout << intersect[i] << " ";
}
*/
