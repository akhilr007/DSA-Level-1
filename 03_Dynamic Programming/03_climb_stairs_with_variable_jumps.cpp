// Climb Stairs With Variable Jumps

// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you 
//      could jump to in a single move.  
//      You can of course jump fewer number of steps in the move.
// 4. You are required to print the number of different paths via which you can climb to the top.

// Input Format
// A number n
// .. n more elements

// Output Format
// A number representing the number of ways to climb the stairs from 0 to top.


// Constraints
// 0 <= n <= 20
// 0 <= n1, n2, .. <= 20

// Sample Input
// 10
// 3
// 3
// 0
// 2
// 1
// 2
// 4
// 2
// 0
// 0

// Sample Output
// 5

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int src, int arr[], int n){

	if(src == n){
		return 1;
	}

	int total = 0;
	for(int k = 1; k <= arr[src] && src + k <= n; k++){

		int ways = climbStairs(src+k, arr, n);
		total += ways;
	}

	return total;
}

int climbStairs_mem(int src, int arr[], int n, int dp[]){

	if(src == n){
		return 1;
	}

	if(dp[src] != -1){
		return dp[src];
	}

	int total = 0;
	for(int k=1 ; k <= arr[src] && src + k <= n; k++){

		int ways = climbStairs_mem(src+k, arr, n, dp);

		total += ways;
	}

	dp[src] = total;
	return total;
}

int climbStairs_tab(int arr[], int n){

	int dp[n+1] = {0};
	// dp[i] -> no of ways to travel from i to n
	dp[n] = 1; // smallest case

	for(int i=n-1; i>=0; i--){

		for(int j=1; j <= arr[i] && i + j <= n; i++){

			dp[i] = dp[i] + dp[i+j];
		}
	}

	return dp[0]; // no of ways to travel from 0 to n 
}

int main(){

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	//recursion
	cout << climbStairs(0, arr, n);

	// memoisation
	int dp[n+1];
	memset(dp, -1, sizeof(dp));
	cout << climbStairs_mem(0, arr, n, dp);

	// tabulation
	cout << climbStairs_tab(arr, n);

	return 0; 
}