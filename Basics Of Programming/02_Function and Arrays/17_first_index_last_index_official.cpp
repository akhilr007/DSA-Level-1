// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.

// Asssumption - Array is sorted. Array may have duplicate values.

// Input Format
// A number n
// n1
// n2
// .. n number of elements
// A number d

// Output Format
// A number representing first index
// A number representing last index

// Constraints
// 1 <= n <= 1000
// 1 <= n1, n2, .. n elements <= 100
// 1 <= d <= 100

// Sample Input
// 15
// 1
// 5
// 10
// 15
// 22
// 33
// 33
// 33
// 33
// 33
// 40
// 42
// 55
// 66
// 77
// 33

// Sample Output
// 5
// 9

#include <iostream>
using namespace std;

int getFirstIndex(int arr[], int n, int x){

	int lo = 0;
	int hi = n-1;

	int firstIndex = -1;

	while(lo <= hi){

		int mid = lo + (hi - lo)/2;

		if(arr[mid] == x){
			firstIndex = mid;
			hi = mid - 1;
		}

		else if(arr[mid] > x){
			hi = mid -1;
		}
		else{
			lo = mid + 1;
		}
	}

	return firstIndex;
}

int getLastIndex(int arr[], int n, int x){

	int lo = 0;
	int hi = n-1;

	int lastIndex = -1;

	while(lo <= hi){

		int mid = lo + (hi-lo)/2;

		if(arr[mid] == x){
			lastIndex = mid;
			lo = mid + 1;
		}
		else if(arr[mid] > x){
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return lastIndex;
}

int main(){

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int x;
	cin >> x;

	int fi = getFirstIndex(arr, n, x);
	int li = getLastIndex(arr, n, x);

	cout << fi << endl;
	cout << li << endl;
	
	return 0;
}