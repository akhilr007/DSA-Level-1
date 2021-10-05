// friend pairing

/*
1. You are given a number n, representing the number of friends.
2. Each friend can stay single or pair up with any of it's friends.
3. You are required to print the number of ways in which these friends can stay single or pair up.
E.g.
1 person can stay single or pair up in 1 way.
2 people can stay singles or pair up in 2 ways. 12 => 1-2, 12.
3 people (123) can stay singles or pair up in 4 ways. 123 => 1-2-3, 12-3, 13-2, 23-1.

Input Format
A number n

Output Format
A number representing the number of ways in which n friends can stay single or pair up.

Constraints
0 <= n <= 20

Sample Input
4

Sample Output
10

*/

#include <bits/stdc++.h>
using namespace std;

int friendPairing(int n){

	// base case
	// if there are only two person or a single person there can be only n ways
	if(n == 2 || n == 1){
		return n;
	}

	if(n <= 0){
		return 0;
	}

	// to go to a party , a person can go single or with pair

	int single = friendPairing(n-1);
	// but to go with pair he can pair with n-1 friends
	int pair =  (n-1) * friendPairing(n-2);

	return single + pair;
}

// memoisation call
int friendPairing_mem(int n, vector<int> &dp){

	if(n == 2 || n == 1){
		return n;
	}

	if(n <= 0){
		return 0;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	int single = friendPairing_mem(n-1, dp);
	int pair = (n-1)*friendPairing_mem(n-2, dp);

	dp[n] = single + pair;
	return dp[n];
}

int friendPairing_tab(int n){

	vector<int> dp(n+1, 0);

	dp[1] = 1;
	dp[2] = 2;

	for(int i=3; i<=n; i++){

		dp[i] = dp[i-1] + (i-1)*dp[i-2];
	}

	return dp[n];
}

int main() {

	int n;
	cin >> n;

	// recursion
	cout << friendPairing(n);

	// memoisation
	vector<int> dp(n+1, -1);
	cout << friendPairing_mem(n, dp);

	// tabulation
	cout << friendPairing_tab(n);

	return 0;
}