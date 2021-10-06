// sort 01
/*
1. You are given an array(arr) containing only 0's and 1's.
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
arr[i] = 0,1

Sample Input
5
0
1
0
1
0

Sample Output
0
0
0
1
1
*/

#include <bits/stdc++.h>
using namespace std;

void sort01(int *arr, int n){

	// consider a straight line 
	// 0 to j-1 -> all zeros are in between them
	// j to i-1 -> all ones are in between them
	// i to end -> unknown 

	// to move 1 to its original position expand j to i-1 so increment i++;
	// to move 0 to its original position swap arr[j] to arr[i] and expand j and i both

	int i=0, j=0;

	while(i < n){

		if(arr[i] == 1){
			i++;
		}

		else {
			swap(arr[i], arr[j]);
			i++;
			j++;
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

	sort01(arr, n);
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
