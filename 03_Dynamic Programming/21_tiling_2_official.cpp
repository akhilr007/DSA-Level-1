// tiling 2
/*
1. You are given a number n and a number m separated by line-break representing the length and breadth of a m * n floor.
2. You've an infinite supply of m * 1 tiles.
3. You are required to calculate and print the number of ways floor can be tiled using tiles.

Input Format
A number n
A number m

Output Format
A number representing the number of ways in which the number of ways floor can be tiled using tiles.

Constraints
1 <= n <= 100
1 <= m <= 50

Sample Input
39
16

Sample Output
61
*/

#include <bits/stdc++.h>
using namespace std;

// recursion function
int tiling(int m, int n){

	// base case;
	if(n <= 0){
		return 0;
	}

	if(n < m){
		return 1;
	}

	else if( n== m){
		return 2;
	}

	int horizontal = tiling(m, n-m);
	int vertical = tiling(m, n-1);
	return horizontal + vertical;
}

// memoisation function
int tiling_mem(int m, int n, vector<int> &dp){

	if(n <= 0){
		return 0;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	if(n < m){
		// if n < m then
		// only 1 way that is place it vertically
		return 1;
	}

	else if(n == m){
		// if n equal m then we can start placing it in 2 ways 
		return 2;
	}

	int horizontal = tiling_mem(m, n-m, dp);
	int vertical = tiling_mem(m, n-1, dp);
	dp[n] = horizontal + vertical;

	return dp[n];
}

// tabulation function
int tiling_tab(int m, int n){

	vector<int> dp(n+1, 0);

	// dp[i] -> ways to tile m*i area

	// base cases
	for(int i=1; i<=n; i++){

		if(i < m){
			dp[i] = 1;
		}

		// if n becomes equal to m then we have 2 ways
		else if(i == m){
			dp[i] = 2;
		}

		else{
			dp[i] = dp[i-m] + dp[i-1];
		}
	}

	return dp[n];
}

int main() {

	int n, m;
	cin >> n >> m;

	// recursion
	cout << tiling(m, n);

	// memoization
	vector<int> dp(n+1, -1);
	cout << tiling_mem(m, n, dp);

	// tabulation
	cout << tiling_tab(m, n);

	return 0;
}