// zero one knapsack
/*
1. You are given a number n, representing the count of items.
2. You are given n numbers, representing the values of n items.
3. You are given n numbers, representing the weights of n items.
3. You are given a number "cap", which is the capacity of a bag you've.
4. You are required to calculate and print the maximum value that can be created in the bag without 
     overflowing it's capacity.

Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item 
               again and again.
Input Format
A number n
v1 v2 .. n number of elements
w1 w2 .. n number of elements
A number cap

Output Format
A number representing the maximum value that can be created in the bag without overflowing it's capacity

Constraints
1 <= n <= 20
0 <= v1, v2, .. n elements <= 50
0 < w1, w2, .. n elements <= 10
0 < cap <= 10

Sample Input
5
15 14 10 45 30
2 5 1 3 4
7

Sample Output
75
*/

#include<bits/stdc++.h>
using namespace std;

int knapsack01(int wt[], int val[], int cap, int n){

	// base case -> if n is 0 that means if there are no items no max value can be achieved
	// if cap is 0 that means max value can be 0
	if(n == 0 || cap == 0){
		return 0;
	}

	if(wt[n-1] <= cap){

		return max(val[n-1] + knapsack01(wt, val, cap-wt[n-1], n-1), knapsack01(wt, val, cap, n-1));
	}
	else{
		return knapsack01(wt, val, cap, n-1);
	}

}

int knapsack01_mem(int wt[], int val[], int cap, int n, vector<vector<int>> &dp){

	if(n == 0 || cap == 0){
		return 0;
	}

	if(dp[n][cap] != -1){
		return dp[n][cap];
	}

	if(wt[n-1] <= cap){
		dp[n][cap] = max(val[n-1] + knapsack01_mem(wt, val, cap-wt[n-1], n-1, dp),
		 knapsack01_mem(wt, val, cap, n-1, dp));

		return dp[cap];
	}
	else{
		dp[n][cap] = knapsack01_mem(wt, val, cap, n, dp);
		return dp[n][cap];
	}
}

int knapsack01_tab(int wt[], int val[], int cap, int n){

	int dp[n+1][cap+1];

	// dp[i][j] -> it denotes max value of jth weight from 1 to ith

	for(int i=0; i<n+1; i++){
		dp[i][0] = 0;
	}

	for(int j=0; j<cap+1; j++){
		dp[0][j] = 0;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=cap; j++){

			if(wt[i-1] <= j){
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][cap];
}

int main(){

	int n;
	cin >> n;

	int val[n];
	for(int i=0; i<n; i++){
		cin >> val[i];
	}

	int wt[n];
	for(int i=0; i<n; i++){
		cin >> wt[i];
	}

	int cap;
	cin >> cap;

	// recursion
	cout << knapsack01(wt, val, cap, n);

	// memoisation
	vector<vector<int>> dp(n+1, vector<int> (amt+1, -1));
	cout << knapsack01(wt, val, cap, n-1, dp);

	// tabulation
	cout << knapsack01_tab(wt, val, cap, n);

	return 0;
}