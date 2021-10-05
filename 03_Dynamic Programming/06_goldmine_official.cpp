// goldmine

// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
// 4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from 
//      any row in the left wall.
// 5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).

// goldmine

// 6. Each cell has a value that is the amount of gold available in the cell.
// 7. You are required to identify the maximum amount of gold that can be dug out from the mine.

// Input Format
// A number n
// A number m
// e11
// e12..
// e21
// e22..
// .. n * m number of elements

// Output Format
// An integer representing Maximum gold available.

// Constraints
// 1 <= n <= 10^2
// 1 <= m <= 10^2
// 0 <= e1, e2, .. n * m elements <= 1000

// Sample Input
// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1

// Sample Output
// 33

#include <bits/stdc++.h>
using namespace std;

int goldmine(int r, int c, vector<vector<int>> &arr){

	// if the row and col is out of bound
	if(r < 0 || r >= arr.size() || c >= arr[0].size()){
		return INT_MIN;
	}

	// base condition -> when it reaches last column
	if(c == arr[0].size()-1){
		return arr[r][c];
	}

	// there will be 3 paths
	int f1 = goldmine(r-1, c+1, arr); // upward diagonal
	int f2 = goldmine(r, c+1, arr); // straigh
	int f3 = goldmine(r+1, c+1, arr);

	int maxCost = max(f1, max(f2, f3)) + arr[r][c];

	return maxCost;
}


int goldmine_mem(int r, int c, vector<vector<int>> &arr, vector<vector<int>> &dp){

	if(r < 0 || r >= arr.size() || c >= arr[0].size()){
		return INT_MIN;
	}

	if(c == arr[0].size()-1){
		return arr[r][c];
	}

	if(dp[r][c] != -1){
		return dp[r][c];
	}

	int f1 = goldmine_mem(r-1, c+1, arr, dp); // upward diagonal
	int f2 = goldmine_mem(r, c+1, arr, dp); // straigh path
	int f3 = goldmine_mem(r+1, c+1, arr, dp); // downward diagonal

	int maxCost = max(f1, max(f2, f3)) + arr[r][c];
	dp[r][c] = maxCost;

	return maxCost;
}

int goldmine_tab(vector<vector<int>> arr){

	int n = arr.size(), m = arr[0].size();

	int dp[n][m]; // max cost from i, j to n, m

	for(int j=m-1; j>=0; j--){

		for(int i=0; i<n; i++){

			// last col
			if(j == m-1){
				dp[i][j] = arr[i][j];
			}

			// first row
			else if(i == 0){
				dp[i][j] = max(dp[i][j+1], dp[i+1][j+1]) + arr[i][j];
			}

			// last row
			else if(i == n-1){
				dp[i][j] = max(dp[i][j+1], dp[i-1][j+1]) + arr[i][j];
			}

			// rest of the matrix
			else{
				dp[i][j] = max(dp[i-1][j+1], max(dp[i][j+1], dp[i+1][j+1])) + arr[i][j];
			}
		}
	}

	// we have max cost in the first col find out the max cost by traversing the first col
	int maxi = 0;
	for(int i = 0; i < n; i++){

		if(dp[i][0] > maxi){
			maxi = dp[i][0];
		}
	}

	return maxi;
}

int main(){

	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}

	int omax = INT_MIN;
	// we can start from any rows so we can use loop for row selection
	for(int i=0; i<n; i++){

		// recursion
		int ans = goldmine(i, 0, arr);

		// memoisation
		vector<vector<int>> dp(n, vector<int>(m, -1));
		int ans = goldmine_mem(i, 0, arr, dp);

		// tabulation
		int ans = goldmine_tab(arr);

		if(ans > omax){
			omax = ans;
		}
	}

	cout << ans;

	return 0;
}