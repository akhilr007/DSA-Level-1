// sort 012 
/*
1. You are given an array(arr) containing only 0's, 1's, and 2's.
2. You have to sort the given array in increasing order and in linear time.

Input Format
An Integer N 
arr1
arr2..
n integers

Output Format
Check the sample output and question video.

Constraints
1 <= N <= 10000
arr[i] = 0,1,2

Sample Input
10
1
0
2
2
1
0
2
1
0
2

Sample Output
0 0 0 1 1 1 2 2 2 2
*/

#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n){

	// 0 lies b/w 0 to j-1
	// 1 lies b/w j to i-1
	// 2 lies b/w k+1 to n-1
	// unknown lies b/w 0 to n-1

	int i=0, j=0, k=n-1;

	while(i <= k) {

		if(arr[i] == 1){
			i++;
		}
		else if(arr[i] == 0){
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
		else{
			swap(arr[k], arr[i]);
			k--;
		}
	}
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	sort012(arr, n);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

	return 0;
}