// coin change permutations

// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the number of permutations of the n coins using which the 
//      amount "amt" can be paid.

// Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be 
//                   used for many installments in payment of "amt"
// Note2 -> You are required to find the count of permutations and not combinations i.e.
//                   2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same 
//                   combination. You should treat them as 3 and not 1.
// Input Format
// A number n
// n1
// n2
// .. n number of elements
// A number amt

// Output Format
// A number representing the count of combinations of coins which can be used to pay the amount "amt"

// Constraints
// 1 <= n <= 20
// 0 <= n1, n2, .. n elements <= 20
// 0 <= amt <= 30

// Sample Input
// 4
// 2
// 3
// 5
// 6
// 7

// Sample Output
// 5

#include <bits/stdc++.h>
using namespace std;

// recursion
int ccp(vector<int> coins, int amt){

	// base case -> if the amt gets zero it means we have got our target
	if(amt == 0){
		return 1;
	}

	// if amt gets less than 0 it means we do not have coins to get the reqd amount
	if(amt < 0){
		return 0;
	}
	// we can have all the options from denominations of coins
	// iterate through the coins and check by deducting from coins 
	// if the sum turns out to be zero we can add to the count and if its less than zero return 0

	int count = 0;
	for(int i=0; i<coins.size(); i++){

		count += ccp(coins, amt-coins[i]);
	}

	return count;
}

// memoisation
int ccp_mem(vector<int> coins, int amt, vector<int> dp){

	if(amt == 0){
		return 1;
	}

	if(amt < 0){
		return 0;
	}

	if(dp[amt] != -1){
		return dp[amt];
	}

	int count = 0;
	for(int i=0; i<coins.size(); i++){
		count += ccp_mem(coins, amt-coins[i], dp);
		dp[amt] = count;
	}

	return count;
}

int ccp_tab(vector<int> coins, int amt){

	vector<int> dp(amt+1, 0);

	// dp[i] -> ways to pay i amount
	dp[0] = 1;// smallest case no of ways to pay 0 is 0 

	for(int i=1; i<dp.size(); i++){

		for(int j=0; j<coins.size(); j++){

			// to pay 5 we can go to 2 3 5 7
			int remAmount = i - coins[j]; 

			if(remAmount >= 0){
				dp[i] += dp[remAmount];
			}
		}
	}

	return dp[amt];
}

int main(){
	
	int n;
	cin >> n;

	vector<int> coins(n);
	for(int i=0; i<n; i++){
		cin >> coins[i];
	}

	int amt;
	cin >> amt;

	// coin change permutations recursion
	cout << ccp(coins, amt);

	// memoisation
	vector<int> dp(amt+1 -1);
	cout << ccp_mem(coins, amt, dp);

	// tabulation
	cout << ccp_tab(coins, amt);

	return 0;
}