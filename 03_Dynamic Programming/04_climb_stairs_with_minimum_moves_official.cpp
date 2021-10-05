// climb stairs with minimum moves

// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you 
//      could jump to in a single move.  You can of-course fewer number of steps in the move.
// 4. You are required to print the number of minimum moves in which you can reach the top of 
//      staircase.
// Note -> If there is no path through the staircase print null.

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
// 4

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int src, int arr[], int n){

	// base case min moves to travel from n to n is 0
	if(src == n){
		return 0;
	}

	int minTotalSteps = INT_MAX; // nin total steps from intermediate to destination

	for(int k=1; k <= arr[src] && src + k <= n; k++){

		int ways = climbStairs(src+k, arr, n);

		minTotalSteps = min(minTotalSteps, ways);
	}

	if(minTotalSteps == INT_MAX){
		return INT_MAX;
	}
	else{
		return minTotalSteps+1; // add 1 from source to get source to destionation
	}
}

int climbStairs_mem(int src, int arr[], int n, int dp[]){

	if(src == n){
		return 0;
	}

	if(dp[src] != -1){
		return dp[src];
	}

	int minTotalSteps = INT_MAX;
	for(int k=1; k <= arr[src] && src + k <= n; k++){

		int ways = climbStairs_mem(src+k, arr, n, dp);

		minTotalSteps = min(minTotalSteps, ways);
	}

	if(minTotalSteps == INT_MAX){
		dp[src] = INT_MAX;
		return dp[src];
	}
	else{
		dp[src] = minTotalSteps+1;
		return dp[src];
	}
}

int climbStairs_tab(int arr[], int n){

	int dp[n+1] = {0};

	// dp[i] -> it stores min moves from i to n
	dp[n] = 0;// min moves from n to n is 0 that is dont go anywhere

	for(int i = n-1; i>=0; i--){
		int minMoves = INT_MAX;
		for(int j = 1; j <= arr[i] && i + j <= n; j++){

			dp[i] = dp[i+j];

			if(dp[i] < minMoves){
				minMoves = dp[i];
			}
		}

		if(minMoves == INT_MAX){
			dp[i] = INT_MAX;
		}
		else{
			dp[i] = minMoves + 1;
		}
	}

	return dp[0];

}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	// recursion
	cout << climbStairs(0, arr, n);

	// memoisation
	int dp[n+1];
	memset(dp, -1, sizeof(dp));
	cout << climbStairs_mem(0, arr, n, dp);

	// tabulation
	cout << climbStairs_tab(arr, n);

	return 0;
}