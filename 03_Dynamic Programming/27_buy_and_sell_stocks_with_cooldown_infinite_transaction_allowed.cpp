//Buy And Sell Stocks With Cooldown - Infinite Transaction Allowed
/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed infinite transactions, but have to cooldown for 1 day after 1 transaction
i.e. you cannot buy on the next day after you sell, you have to cooldown for a day at-least before buying again.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

Input Format
A number n
.. n more elements

Output Format
A number representing the maximum profit you can make if you are allowed infinite transactions with cooldown of 1 day.

Constraints
0 <= n <= 20
0 <= n1, n2, .. <= 10

Sample Input
12
10
15
17
20
16
18
22
20
22
20
23
25

Sample Output
19

*/

#include <bits/stdc++.h>
using namespace std;

int infiniteTransaction(int price[], int n){

	int obsp = -price[0]; // old buying state profit
	int ossp = 0; // old selling state profit
	int ocsp = 0; // old cooldown state profit

	for(int i=1; i<n; i++){

		int nbsp = max(obsp, ocsp - price[i]);
		int nssp = max(ossp, obsp + price[i]);
		int ncsp = max(ocsp, ossp);

		obsp = nbsp;
		ossp = nssp;
		ocsp = ncsp;
	}

	return ossp;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << infiniteTransaction(arr, n);
	return 0;
}