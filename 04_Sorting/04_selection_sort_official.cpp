// selection sort
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

void selectionSort(vector<int> &arr, int n){

	for(int i=0; i<n-1; i++){
		int mini = i;
		for(int j=i+1; j<n; j++){

			if(arr[j] < arr[mini]){
				mini = j;
			}
		}

		swap(arr[i], arr[mini]);
	}
}

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	selectionSort(arr, n);
	for(auto x: arr){
		cout << arr[i] <<" ";
	}

	return 0;
}