// partition into subsets

/*
1. You are given a number n, representing the number of elements.
2. You are given a number k, representing the number of subsets.
3. You are required to print the number of ways in which these elements can be partitioned in k non-empty subsets.
E.g.
For n = 4 and k = 3 total ways is 6
12-3-4
1-23-4
13-2-4
14-2-3
1-24-3
1-2-34

Input Format
A number n
A number k

Output Format
A number representing the number of ways in which these elements can be partitioned in k non-empty subsets.

Constraints
0 <= n <= 20
0 <= k <= n

Sample Input
4
3

Sample Output
6
*/

#include <bits/stdc++.h>
using namespace std;

long partitionKSubset(int n, int k){

	// base case;
	if(k > n){
		return 0;
	}

	// if k == 1 there is only one way that is all elements are together

	// if n is equals to k, so we cannot make any set empty so there is only option that is
	// to put every element at every set
	if(k == 1 || n == k){
		return 1;
	}
	// we have two ways from which we can divide the subset

	// first step -> an element doesn't include any element with itself
	long single = partitionKSubset(n-1, k-1);

	// second step -> an element include other elements with itself
	// why are we multiplying k?
	// every element other than suppose a from abcd that is bcd divides itself into k sets
	// then a can attach itself to any one of the sets that is it gets 3 ways so multiply with k
	long pair = k * partitionKSubset(n-1, k);

	long ans = single + pair;
}

long partitionKSubset_tab(int n, int k){

	vector<vector<long>> dp(n+1, vector<long>(k+1, 0));

	for(int i=0; i<dp.size(); i++){ // i->n

		for(int j=0; j<dp[0].size(); j++){ // j -> k

			if(i == 0 || j == 0 || j > i){
				dp[i][j] = 0;
			}

			else if(i == j){
				dp[i][j] = 1;
			}

			else{

				dp[i][j] = dp[i-1][j-1] + j * dp[i-1][j];
			}
		}
	}

	return dp[n][k];
}

int main() {

	int n, k;
	cin >> n >> k;

	// recursion
	long ans = partitionKSubset(n, k);
	cout << ans;

	// tabulation
	long ans = partitionKSubset_tab(n, k);
	cout << ans;

	return 0;
}