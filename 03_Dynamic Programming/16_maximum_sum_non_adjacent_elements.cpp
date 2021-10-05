// maximum sum non adjacent elements

/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers, representing n elements.
3. You are required to find the maximum sum of a subsequence with no adjacent elements.

Input Format
A number n
n1
n2
.. n number of elements

Output Format
A number representing the maximum sum of a subsequence with no adjacent elements.

Constraints
1 <= n <= 1000
-1000 <= n1, n2, .. n elements <= 1000

Sample Input
6
5
10
10
100
5
6

Sample Output
116

*/

#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int idx, int n){
	// base case -> if n is greater than arr.length then return 0

	if(idx > n-1){
		return 0;
	}

	// we can include the number and exclude it
	int inc = arr[idx] + maxSum(arr, idx+2, n);
	int exc = maxSum(arr, idx+1, n);

	return max(inc, exc);
}

int maxSum_tab(int arr[], int n){

	int inc = 0;
	int exc = 0;

	for(int i=0; i<n; i++){

		int ninc = exc + arr[i];
		int nexc = max(inc, exc);

		inc = ninc;
		exc = nexc;
	}

	return max(inc, exc);
}

int main(){

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	// recursion
	cout << maxSum(arr, 0, n);

	// tabulation
	cout << maxSum_tab(arr, n);

	return 0;
}