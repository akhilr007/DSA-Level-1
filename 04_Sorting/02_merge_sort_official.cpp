// merge sort
/*
1. You are given an array(arr) of integers.
2. You have to sort the given array in increasing order using the merge sort.

Input Format
An Integer n 
arr1
arr2..
n integers

Output Format
Check the sample output and question video.

Constraints
1 <= N <= 100000
-10^9 <= arr[i] <= 10^9

Sample Input
5
7 
-2 
4 
1 
3

Sample Output
-2
1
3
4
7
*/

#include <bits/stdc++.h>
using namespace std;

void mergeTwoSortedArrays(vector<int> &arr, int lo, int mid, int hi){

	int n1 = mid - lo + 1;
	int n2 = hi - mid;

	vector<int> a(n1);
	vector<int> b(n2);

	for(int i=0; i<n1; i++){
		a[i] = arr[lo+i];
	}

	for(int i=0; i<n2; i++){
		b[i] = arr[mid+1+i];
	}

	int i=0, j=0, k=lo;

	while(i < n1 && j < n2){

		if(a[i] <= b[j]){

			arr[k] = a[i];
			i++;
			k++;
		}
		else{
			arr[k] = b[j];
			j++;
			k++;
		}
	}

	// if any of our array has not been traversed fully
	while(i < n1){
		arr[k] = a[i];
		i++;
		k++;
	}

	while(j < n2){
		arr[k] = b[j];
		j++;
		k++;
	}

}

void mergeSort(vector<int> &a, int lo, int hi){

	if(lo < hi){

		int mid = lo + (hi - lo)/2;

		mergeSort(a, lo, mid);
		mergeSort(a, mid+1, hi);

		mergeTwoSortedArrays(a, lo, mid, hi);
	}
}

int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	mergeSort(a, 0, a.size()-1);

	for(auto x: a){
		cout << x << endl;
	}

	return 0;
}