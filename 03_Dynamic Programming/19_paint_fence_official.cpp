// paint fences

/*
1. You are given a number n and a number k in separate lines, representing the number of fences and number of colors.
2. You are required to calculate and print the number of ways in which the fences could be painted so that not more than two consecutive  fences have same colors.

Input Format
A number n
A number k

Output Format
A number representing the number of ways in which the fences could be painted so that not more than two fences have same colors.

Constraints
1 <= n <= 10
1 <= k <= 10

Sample Input
8
3

Sample Output
3672

*/

#include <bits/stdc++.h>
using namespace std;

int paintFences(int n , int k){

	if(n == 1){
		return k;
	}

	//no of ways to paint fence with same color is k ways
	int osc = k;
	// no of ways to paint fence with diff color is k and multiply with k-1 ways
	int odc = k * (k-1);

	for(int i=3; i<=n ; i++){

		int nsc = odc;
		int ndc = (osc + odc) * (k-1);

		osc = nsc;
		odc = ndc;
	}

	return osc + odc;
}

int main(){

	int n, k;
	cin >> n >> k;

	cout << paintFences(n, k);
	return 0;
}
