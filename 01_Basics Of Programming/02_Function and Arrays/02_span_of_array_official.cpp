// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are required to find the span of input. Span is defined as difference of maximum value and minimum value.

// Input Format
// A number n
// n1
// n2
// .. n number of elements

// Output Format
// A number representing max - min

// Constraints
// 1 <= n <= 10^4
// 0 <= n1, n2
//  .. n elements <= 10 ^9

// Sample Input
// 6
// 15
// 30
// 40
// 4
// 11
// 9

// Sample Output
// 36

#include <bits/stdc++.h>
using namespace std;

void getSpan(int arr[], int n){
	
	int ma = INT_MIN;
	int mi = INT_MAX;

	for(int i = 0; i < n; i++){

		if(arr[i] > ma){
			ma = arr[i];
		}

		if(arr[i] < mi){
			mi = arr[i];
		}	
	}

	cout << ma - mi <<endl;
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	getSpan(arr, n);
	return 0;
}