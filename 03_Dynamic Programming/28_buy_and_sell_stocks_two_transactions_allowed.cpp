// buy and sell stocks - two transactions allowed
/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed two transactions at-most.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

Input Format
A number n
.. n more elements

Output Format
A number representing the maximum profit you can make if you are allowed a single transaction.

Constraints
0 <= n <= 20
0 <= n1, n2, .. <= 10

Sample Input
9
11
6
7
19
4
1
6
18
4

Sample Output
30
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n){

	// by iterating from the left, we will find the max profit till ith stock

	int minLeft = arr[0]; // first element from left will be our min while starting.
	int ovpLeft = 0; // overall profit from left

	int dpl[n] = {0}; // starting with all element to be zeros

	for(int i=1; i<n; i++){

		// update the min left element if it exists.
		if(arr[i] < minLeft){
			minLeft = arr[i];
		}

		// calculate the profit if u sell at ith day
		ovpLeft = arr[i] - minLeft;

		// dpl[i] -> max profit we can get before and including ith stoc, if it's sold
		if(ovpLeft > dpl[i-1]){
			dpl[i] = ovpLeft;
		}
		else{
			dpl[i] = dpl[i-1];
		}
	}

	// by iterating from the right , we will find the max profit till ith stock
	int maxRight = arr[n-1]; // last element from right will be our max while starting
	int ovpRight = 0;

	int dpr[n] = {0};

	for(int i=n-2; i>=0; i--){

		// update the max right element if it exists
		if(arr[i] > maxRight){
			maxRight = arr[i];
		}

		// overall profit we can get if we know the max right element and buy it at ith day and sell 
		// it  at max Rightth day
		int ovpRight = maxRight - arr[i];

		// dpr[i] -> max profit we can get after and including ith stock, if it's sold.
		if(ovpRight > dpr[i+1]){
			dpr[i] = ovpRight;
		}
		else{
			dpr[i] = dpr[i+1];
		}
	}

	// now add the two dp values to get the two transaction values
	int profit = 0;
	for(int i=0; i<n; i++){
		if(dpl[i] + dpr[i] > profit){
			profit = dpl[i] + dpr[i];
		}
	}

	return profit;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << maxProfit(arr, n);
	return 0;
}