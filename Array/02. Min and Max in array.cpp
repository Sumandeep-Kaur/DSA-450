/*  
    To find minimum and maximum element in an array using minimum number of comparisons.   
    Time Complexity: O(n)  
    Space Complexity: O(1) 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int mn = INT_MAX, mx = INT_MIN;
	for(int i = 0; i < n; i++){
		if(arr[i] < mn)
			mn = arr[i];
		if(arr[i] > mx)
			mx = arr[i];
	}
	cout << "Minimum element:" << mn << "\n";
	cout << "Maximum element:" << mx << "\n";
    return 0;
}