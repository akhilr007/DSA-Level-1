// tiling with 2*1 tiles
/*
1. You are given a number n representing the length of a floor space which is 2m wide. It's a 2 * n board.
2. You've an infinite supply of 2 * 1 tiles.
3. You are required to calculate and print the number of ways floor can be tiled using tiles.

Input Format
A number n

Output Format
A number representing the number of ways in which the number of ways floor can be tiled using tiles.

Constraints
1 <= n <= 100

Sample Input
8

Sample Output
34

*/

#include <bits/stdc++.h>
using namespace std;

int tiling(int n){

	if(n <= 0){
		return 0;
	}

	if(n == 1 || n == 2){
		return n;
	}

	// to tiling 2 * n area with 2 * 1 tile
	// we have two options 1. to place it horizontally and second to place it vertically

	int horizontal = tiling(n-2);
	int vertical = tiling(n-1);
	return horizontal + vertical;
}

int tiling_mem(int n, vector<int> &dp){

	if(n <= 0){
		return 0;
	}

	if(n == 1 || n == 2){
		return n;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	int horizontal = tiling_mem(n-2, dp);
	int vertical = tiling_mem(n-1, dp);
	dp[n] = horizontal + vertical;

	return dp[n];
}

int tiling_tab(int n){

	vector<int> dp(n+1, 0);

	//dp[i] -> ways to tile 2*i

	// base case
	// ways to tile 2*1
	dp[1] = 1;
	// ways to tile 2*2
	dp[2] = 2;

	for(int i=3; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int main(){
	
	int n;
	cin >> n;

	// recursion
	cout << tiling(n);

	// memoisation
	vector<int> dp(n+1, -1);
	cout << tiling_mem(n, dp);

	// tabulation
	cout << tiling_tab(n);
	return 0;
}