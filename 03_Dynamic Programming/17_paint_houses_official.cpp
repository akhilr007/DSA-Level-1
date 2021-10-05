// paint house

// 1. You are given a number n, representing the number of houses.
// 2. In the next n rows, you are given 3 space separated numbers representing the cost of painting nth house with red or blue or green color.
// 3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.

// Input Format
// A number n
// n1red n1blue n1green
// n2red n2blue n2green
// .. n number of elements

// Output Format
// A number representing the minimum cost of painting all houses without painting any consecutive house with same color.

// Constraints
// 1 <= n <= 1000
// 0 <= n1red, n1blue, .. <= 1000

// Sample Input
// 4
// 1 5 7
// 5 8 4
// 3 2 9
// 1 2 4

// Sample Output
// 8

#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> houses){

	int oldRed = 0;
	int oldBlue = 0;
	int oldGreen = 0;

	//dp[i][j] -> min cost to paint houses from[0, i] such that i houses is to be painted with j colour

	for(int i=0; i<houses.size(); i++){

		// to paint red colour -> take min(blue, green) + add red colour cost to it so that adj
		// colours are painted 
		int newRed = min(oldBlue, oldGreen) + houses[i][0];
		int newBlue = min(oldRed, oldGreen) + houses[i][1];
		int newGreen = min(oldRed, oldBlue) + houses[i][2];

		oldRed = newRed;
		oldBlue = newBlue;
		oldGreen = newGreen;
	}

	// find the min in last row to get the result;
	return min(min(oldRed, oldBlue), oldGreen);
}

int main(){

	int n;
	cin >> n;

	vector<vector<int>> houses(n, vector<int>(3));
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin >> houses[i][j];
		}
	}


	// the basic idea is to recusively make 3 calls and check if the house is to be coloured by
	//  the red colour then find min of(blue and green) and add red cost to it.. subsequently follow 
	// these steps.. the time complexity will be 0(3^N).
	cout << minCost(houses);

	return 0;
}