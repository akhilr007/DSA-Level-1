// insertion sort

/*
1. You are given an array(arr) of integers.
2. You have to sort the given array in increasing order using selection sort.

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

void insertionSort(vector<int> &arr, int n){


	for(int i=1; i<n; i++){

		for(int j=i; j>=1; j--){

			if(arr[j-1] > arr[j]){
				swap(arr[j-1], arr[j]);
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

	insertionSort(arr, n);
	for(auto x: arr){
		cout << x <<" ";
	}

	return 0;
}