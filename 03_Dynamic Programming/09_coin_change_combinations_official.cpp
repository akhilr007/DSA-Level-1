// coin change combinations
/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of combinations of the n coins using which the 
     amount "amt" can be paid.

Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be 
                  used for many installments in payment of "amt"
Note2 -> You are required to find the count of combinations and not permutations i.e.
                  2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same 
                  combination. You should treat them as 1 and not 3.

Input Format
A number n
n1
n2
.. n number of elements
A number amt

Output Format
A number representing the count of combinations of coins which can be used to pay the amount "amt"

Constraints
1 <= n <= 30
0 <= n1, n2, .. n elements <= 20
0 <= amt <= 50

Sample Input
4
2
3
5
6
7

Sample Output
2
*/

#include <bits/stdc++.h>
using namespace std;

// recursion
int ccc(int coins[], int amt, int n){

	// base case -> if my amt gets equal to zero it means we have found our combination
	if(n == 0 || amt == 0){

		if(amt == 0){
			return 1;
		}
		else{
			return 0;
		}
	}

	// every coin has two options if its smaller or equal to amt i.e,
	// to get add in coins combination or do not get added
	if(coins[n-1] <= amt){
		return ccc(coins, amt-coins[n-1], n) + ccc(coins, amt, n-1);
	}
	else{
		return ccc(coins, amt, n-1);
	}
}

int ccc_mem(int coins[], int amt, int n, vector<int> &dp){

	if(n == 0 || amt == 0){

		if(amt == 0){
			return 1;
		}
		else{
			return 0;
		}
	}

	if(dp[amt] != -1){
		return dp[amt];
	}

	if(coins[n-1] <= amt){
		// two options either we select the coins or not
		// if we select we can repeat it afterwards but if we not we discard that coin
		dp[amt] = ccc_mem(coins, amt-coins[n-1], n, dp) + ccc_mem(coins, amt, n-1);
		return dp[amt];
	}
	else{
		dp[amt] = ccc_mem(coins, amt, n-1);
		return dp[amt];
	}
}

int ccc_tab(int coins[], int amt, int n){

	int dp[n+1][amt+1];

	// dp[i][j] -> no of combinations i coins can pay j amt

	for(int j=0; j<amt+1; j++){
		dp[0][j] = 0;
	}

	for(int i=0; i<n+1; i++){
		dp[i][0] = 1;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<= amt; j++){
			if(coins[i-1] <= j){
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][amt];
}

int main(){

	int n;
	cin >> n;

	int coins[n];
	for(int i=0; i<n; i++){
		cin >> coins[i];
	}

	int amt;
	cin >> amt;

	// recursion
	cout << ccc(coins, amt, n);

	// memoisation
	vector<int> dp(amt+1, -1);
	cout << ccc_mem(coins, amt, n, dp);

	// tabulation
	cout << ccc_tab(coins, amt, n);

	return 0;
}