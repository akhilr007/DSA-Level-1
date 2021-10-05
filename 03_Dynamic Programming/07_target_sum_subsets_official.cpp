// target sum subsets

// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number "tar".
// 4. You are required to calculate and print true or false, if there is a subset the elements of which add 
//      up to "tar" or not.

// Input Format
// A number n
// n1
// n2
// .. n number of elements
// A number tar

// Output Format
// true or false as required

// Constraints
// 1 <= n <= 30
// 0 <= n1, n2, .. n elements <= 20
// 0 <= tar <= 50

// Sample Input
// 5
// 4
// 2
// 7
// 1
// 3
// 10

// Sample Output
// true

#include <bits/stdc++.h>
using namespace std;

bool targetSum(int arr[], int sum, int n){

	// base case -> when my sum turns to be zero it means subset is found 
	if(sum == 0){
		return true;
	}

	// if my n turns to be zero it means we dont have required elements to make targetsum
	if(n == 0){
		return false;
	}

	// if my last element of arr is less than or equal to target sum
	// we have two options that is
	// either we select into our subset or do not select
	// but if we select we gonna subtract it from reqd sum
	if(arr[n-1] <= sum){

		return targetSum(arr, sum - arr[n-1] , n-1) || targetSum(arr, sum, n-1);
	}

	// if it is greater than target sum we will not select into our subset
	else{
		return targetSum(arr, sum, n-1);
	}
}

bool targetSum_mem(int arr[], int sum, int n, vector<vector<int>> dp) {

	if(sum == 0){
		return 1;
	}

	if(n <= 0){
		return 0;
	}

	if(dp[n][sum] != -1){
		return dp[n][sum];
	}

	if(arr[n-1] <= sum){

		return dp[n][sum] = targetSum_mem(arr, sum-arr[n-1], n-1, dp) || targetSum_mem(arr, sum, n-1, dp);
	}
	else{
		return dp[n][sum] = targetSum_mem(arr, sum, n-1, dp);
	}

	return dp[n][sum];
}

bool targetSum_tab(int arr[], int sum, int n){

	int dp[n+1][sum+1];

	// n = 0, sum = 0 -> true;
	// n > 1, sum = 0 -> it will also be true
	// n = 0, sum > 0 -> false

	// make the first row false
	for(int j = 0; j < sum+1; j++){
		dp[0][j] = false;
	}

	// make first col true
	for(int i=0; i < n+1; i++){
		dp[i][0] = true;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){

			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j]; 
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][sum];
}

int main(){

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int sum;
	cin >> sum;

	// recursion
	int ans = targetSum(arr, sum, n);

	// memoisation
	vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
	int ans = targetSum_mem(arr, sum, n, dp);

	// tabulation
	int ans = targetSum_tab(arr, sum, n);

	if(ans == 1){
		cout <<"true";
	} 
	else{
		cout <<"false";
	}

	return 0;

}