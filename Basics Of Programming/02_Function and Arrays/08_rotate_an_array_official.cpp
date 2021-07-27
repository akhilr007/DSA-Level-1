// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are given a number k.
// 4. Rotate the array a, k times to the right (for positive values of k), and to
// the left for negative values of k.

// Input Format
// Input is managed for you

// Output Format
// Output is managed for you

// Constraints
// 0 <= n < 10^4
// -10^9 <= a[i], k <= 10^9

// Sample Input
// 5
// 1
// 2
// 3
// 4
// 5
// 3

// Sample Output
// 3 4 5 1 2

#include <iostream>
using namespace std;

void reverse(int* arr, int lo, int hi){

	while(lo < hi){
		int temp = arr[lo];
		arr[lo] = arr[hi];
		arr[hi] = temp;

		lo++;
		hi--;
	}
}

void display(int* arr, int n){

	for(int i=0; i<n; i++){
		cout << arr[i] <<" ";
	}

	cout << endl;
}

void rotate(int* arr, int n, int k){

	k = k % n;

	if(k < 0){
		k = k + n;
	}

	reverse(arr, 0, n-k-1);
	reverse(arr, n-k, n-1);
	reverse(arr, 0, n-1);
}

int main(){
	int n;
	cin >> n;

	int* arr = new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int k;
	cin >> k;

	rotate(arr, n, k);
	display(arr, n);
	return 0;
}