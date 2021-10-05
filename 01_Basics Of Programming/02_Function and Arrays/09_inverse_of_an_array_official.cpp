// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to calculate the inverse of array a.

// For definition and constraints check this link
// https://www.pepcoding.com/resources/online-java-foundation/getting-started/inverse-of-a-number/ojquestion
// The only difference is the range of values is from 0 to n - 1, instead of 1 to n.

// Input Format
// Input is managed for you

// Output Format
// Output is managed for you

// Constraints
// 0 <= n < 10^7
// For more constraints check this
// https://www.pepcoding.com/resources/online-java-foundation/getting-started/inverse-of-a-number/ojquestion
// The only difference is the range of values is from 0 to n - 1, instead
// of 1 to n

// Sample Input
// 5
// 4
// 0
// 2
// 3
// 1

// Sample Output
// 1
// 4
// 2
// 3
// 0

#include <iostream>
using namespace std;

void inverse(int arr[], int n){

	int a[n];

	for(int i=0; i<n; i++){
		int val = arr[i];
		a[val] = i;
	}

	for(int i=0; i<n; i++){
		cout << a[i] <<endl;
	}

}

int main(){
	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	inverse(arr, n);

	return 0;
}