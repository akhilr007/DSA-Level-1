// min cost in maze traversal

// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
// 4. You are standing in top-left cell and are required to move to bottom-right cell.
// 5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
// 6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom- 
//      right cell).
// 7. You are required to traverse through the matrix and print the cost of path which is least costly.

// Input Format
// A number n
// A number m
// e11
// e12..
// e21
// e22..
// .. n * m number of elements

// Output Format
// The cost of least costly path.

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
// 23


#include <bits/stdc++.h>
using namespace std;

int minCost(int sr, int sc, vector<vector<int>> arr){

	if(sr >= arr.size() || sc >= arr[0].size()){
		return INT_MAX;
	}

	if(sr == arr.size()-1 && sc == arr[0].size()-1){
		return arr[sr][sc];
	}

	// we have two paths horizontal and vertical
	int hpath = minCost(sr, sc+1, arr);
	int vpath = minCost(sr+1, sc, arr);

	// min cost will be min b/w hpath and vpath and current cost to it
	int minCostRes = min(hpath, vpath) + arr[sr][sc];

	return minCostRes;
}

int minCost_mem(int sr, int sc, vector<vector<int>> arr, vector<vector<int>> dp){

	// base condition
	// if sr == dr and sc == dc
	if(sr == arr.size()-1 && sc == arr[0].size()-1){
		return arr[sr][sc];
	}

	// out of bounds 
	if(sr >= arr.size() || sc >= arr[0].size()){
		return INT_MAX;
	}

	// check if the problem has been solved earlier
	if(dp[sr][sc] != -1){
		return dp[sr][sc];
	}

	int hpath = minCost(sr, sc+1, arr, dp);
	int vpath = minCost(sr+1, sc, arr, dp);

	int minCostRes = min(hpath, vpath) + arr[sr][sc];
	dp[sr][sc] = minCostRes;

	return minCostRes;
}

int minCost_tab(vector<vector<int>> arr){

	int n = arr.size();
	int m = arr[0].size();

	int dp[n+1][m+1];

	for(int i=n-1; i>=0; i--){
		for(int j=m-1; j>=0; j--){

			// desination block
			if(i == n-1 && j == m-1){
				dp[i][j] = arr[i][j];
			}

			// last row
			else if(i == n-1){
				dp[i][j] = dp[i][j+1] + arr[i][j];
			}

			// last column
			else if(j == m-1){
				dp[i][j] = dp[i+1][j] + arr[i][j];
			}

			// rest of the matrix
			else{
				dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + arr[i][j];
			}
		}
	}

	return dp[0][0];
}

int main(){

	int n, m;
	cin >> n;
	cin >> m;

	vector<vector<int>> arr(n, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}

	// recursion
	cout << minCost(sr, sc, arr);

	// memoisation
	vector<vector<int>> dp(n, vector<int> (m, -1));
	cout << minCost_mem(0, 0, arr, dp);

	// tabulation
	cout << minCost_tab(arr)

	return 0;
}