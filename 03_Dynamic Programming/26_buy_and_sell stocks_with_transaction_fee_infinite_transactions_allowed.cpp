// buy and transactions with transaction fee - infinite transactions allowed
/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are give a number fee, representing the transaction fee for every transaction.
4. You are required to print the maximum profit you can make if you are allowed infinite transactions, but has to pay "fee" for every closed transaction.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

Input Format
A number n
.. n more elements
A number fee

Output Format
A number representing the maximum profit you can make if you are allowed infinite transactions with transaction fee.

Constraints
0 <= n <= 20
0 <= n1, n2, .. <= 10
0 <= fee <= 5

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
3

Sample Output
13
*/

#include <bits/stdc++.h>
using namespace std;

int infiniteTransaction(int price[], int n, int fee){

	// two states are there 1> buying state which ends with b
	// 2> selling state which always ends with s.


	int obsp = -price[0]; // overall buying state profit
	int ossp = 0;         // overall selling state profit

	for(int i=1; i<n; i++){
		// new buying state profit and new selling state profit
		int nbsp = max(obsp, ossp - price[i]);
		int nssp = max(ossp, obsp + price[i] - fee);

		obsp = nbsp;
		ossp = nssp;
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

	int fee;
	cin >> fee;

	cout << infiniteTransaction(arr, n, fee);
	return 0;
}