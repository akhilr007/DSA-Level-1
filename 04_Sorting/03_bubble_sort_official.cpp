// bubble sort

/*
1. You are given an array(arr) of integers.
2. You have to sort the given array in increasing order using bubble sort.

Input Format
An Integer n 
arr1
arr2..
n integers

Output Format
Check the sample ouput and question video.

*/

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n){

	// loop structure -> first loop -> iterations second loop -> comparisons
	for(int i=1; i<n; i++){
		// first loop traverse n-1 times
		for(int j=0; j<n-i; j++){
			// second loop goes for about n-i times
			if(arr[j] > arr[j+1]){

				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	bubbleSort(arr, n);
	for(auto x: arr){
		cout << arr[i] <<" ";
	}

	return 0;
}