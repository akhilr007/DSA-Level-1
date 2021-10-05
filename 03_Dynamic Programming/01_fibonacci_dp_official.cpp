// fibonacci official dp

// 1. You are given a number n.
// 2. You are required to print the nth element of fibonnaci sequence.

// Note -> Notice precisely how we have defined the fibonnaci sequence
// 0th element -> 0
// 1st element -> 1
// 2nd element -> 1
// 3rd element -> 2
// 4th element -> 3
// 5th element -> 5
// 6th element -> 8

// Input Format
// A number n

// Output Format
// A number representing the nth element of fibonnaci sequence

// Constraints
// 0 <= n <= 45

// Sample Input
// 10

// Sample Output
// 55

#include <bits/stdc++.h>
using namespace std;

//using recursion
int fibonacci_rec(int n){

	// base case
	if(n == 1 || n == 0){
		return n;
	}

	int fib = fibonacci_rec(n-2, dp) + fibonacci_rec(n-1, dp);

	return fib;
}

// using memoisation
int fibonacci_mem(int n, int dp[]){

	if(n == 1 || n == 0){
		return n;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	int fib = fibonacci_mem(n-2) + fibonacci_mem(n-1);
	dp[n] = fib;

	return fib;
}

// using tabulation
int fibonacci_tab(int n){

	int dp[n+1];

	dp[0] = 0;
	dp[1] = 1;

	// dp[i] -> fibonacci till i that is dp[2] contains fibonacci till 2s

	for(int i=2; i<=n; i++){

		dp[i] = dp[i-2] + dp[i-1];
	}

	return dp[n];
}

int main(){

	int n;
	cin >> n;

	cout << fibonacci_rec(n); // recursion call

	int dp[n+1];
	memset(dp, -1, sizeof(dp));
	cout << fibonacci_mem(n, dp); // memoization

	cout << fibonacci_tab(n); // tabulation

	return 0;
}