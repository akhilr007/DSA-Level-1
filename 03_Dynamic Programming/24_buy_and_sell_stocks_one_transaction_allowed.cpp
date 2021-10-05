// buy and sell stocks - one transaction allowed

/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed a single transaction.

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
17
*/

#include <bits/stdc++.h>
using namespace std;

int stocks(int arr[], int n){

	// naive solution
	// use two loops and find the max between two elements

	// efficient solution -> maintain min of the array and find the overall profit

	int msf = INT_MAX; // minimum so far
	int ovp = 0; // overall profit

	for(int i=0; i<n; i++){

		if(arr[i] < msf){
			msf = arr[i];
		}

		ovp = max((arr[i] - msf), ovp);
	}

	return ovp;
}

int main(){

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << stocks(arr, n);
	return 0;
}