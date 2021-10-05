// climb stairs official

// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. In one move, you are allowed to climb 1, 2 or 3 stairs.
// 4. You are required to print the number of different paths via which you can climb to the top.

// Input Format
// A number n

// Output Format
// A number representing the number of ways to climb the stairs from 0 to top.

// Constraints
// 0 <= n <= 20

// Sample Input
// 4

// Sample Output
// 7

#include <bits/stdc++.h>
using namespace std;

// using recursion
int climbStairs(int n){

	if(n == 0){
		return 1;
	}

	if(n < 0){
		return 0;
	}

	int totalWays = climbStairs(n-1) + climbStairs(n-2) + climbStairs(n-3);

	return totalWays;
}

// using memoisation
int climbStairs_mem(int n, int dp[]){

	if(n == 0){
		return 1;
	}

	if(n < 0){
		return 0;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	int totalWays = climbStairs_mem(n-1, dp) + climbStairs_mem(n-2, dp) + climbStairs_mem(n-3, dp);
	dp[n] = totalWays;

	return totalWays;
}

// tabulation
int climbStairs_tab(int n){

	int dp[n+1];
	// dp[i] -> no of ways to travel from i to 0
	dp[0] = 1; // no of ways to travel from 0 to 0 is 1

	for(int i=1; i<=n; i++){

		if(i == 1){
			dp[i] = dp[i-1];
		}

		else if(i == 2){
			dp[i] = dp[i-1] + dp[i-2];
		}

		else{
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		}
	}

	return dp[n];
}

int main(){

	int n;
	cin >> n;

	cout << climbStairs(n); // recursion

	// memoisation
	// int dp[n+1];
	// memset(dp, -1, sizeof(dp));
	// cout << climbStairs_mem(n, dp); 

	// tabulation
	cout << climbStairs_tab(n);

	return 0;
}