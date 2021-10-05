// buy and sell stocks - k transactions allowed

/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are given a number k, representing the number of transactions allowed.
3. You are required to print the maximum profit you can make if you are allowed k transactions at-most.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

Input Format
A number n
.. n more elements
A number k

Output Format
A number representing the maximum profit you can make if you are allowed a single transaction.

Constraints
0 <= n <= 20
0 <= n1, n2, .. <= 10
0 <= k <= n / 2

Sample Input
6
9
6
7
6
3
8
1

Sample Output
5
*/

#include <bits/stdc++.h>
using namespace std;

// 0(n^3) solution
int maxProfit(int arr[], int n, int k){

	vector<vector<int>> dp(k+1, vector<int>(n, 0));

	// k -> no of transactions made
	// n -> no of days

	// for n = 0 and k = 0 all rows and cols will be 0 

	for(int t=1; t<=k; t++){

		for(int d=1; d<n; d++){

			// contenders for dp[t][d] are dp[t][d-1] -> if my k transaction has already been made 
			// by d-1th day.
			int maxi = dp[t][d-1];

			for(int pd=0; pd<d; pd++){

				// calculate profit till t-1th transaction and calculate the profit the dth day
				int tm1 = dp[t-1][pd];
				int tth = arr[i] - arr[pd];

				if(tm1 + tth > maxi){

					maxi = tm1 + tth;
				}
			}

			dp[t][d] = maxi;
		}
	}

	return dp[k][n-1];
}

// 0(n^2) solution
int maxProfit2(int arr[], int n, int k){

	vector<vector<int>> dp(k+1, vector<int> (n, 0));

	for(int t=1; t<=k; t++){

		int maxi = INT_MIN;

		for(int d=1; d<n; d++){

			// for t-1th transaction till d-th day we calculate the max from d=0 to d-1th day
			// the eqn states dp[t-1][d-1] + (arr[i] - arr[d])
			// we could also write the above eqn as dp[t-1][d-1] - arr[d-1] which is our max and arr[i]
			// will be constant
			if(dp[t-1][d-1] - arr[d-1] > maxi){
				maxi = dp[t-1][d-1] - arr[d-1];
			}

			if(maxi + arr[d] > dp[t][d-1]){
				dp[t][d] = maxi + arr[d];
			}
			else{
				dp[t][d] = dp[t][d-1];
			}
		}
	}

	return dp[k][n-1];
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int k;
	cin >> k;

	// time complexity -> O(n^3)
	cout << maxProfit(arr, n, k);

	// time complexity -> O(n^2)
	cout << maxProfit2(arr, n, k);

	return 0;
}