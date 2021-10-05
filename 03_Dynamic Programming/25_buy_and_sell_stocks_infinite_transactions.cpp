// buy and sell stocks - infinite transactions allowed
/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed infinite transactions.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy)

Input Format
A number n
.. n more elements

Output Format
A number representing the maximum profit you can make if you are allowed infinite transactions.

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

int stocks(int arr[], int n){

	int ovp = 0;

	for(int i=0,j=1; i<n-1, j<n; i++, j++){

		if(arr[i] < arr[j]){
			ovp += arr[j] - arr[i];
		}
	}

	return ovp;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << stocks(arr, n);
	return 0;
}