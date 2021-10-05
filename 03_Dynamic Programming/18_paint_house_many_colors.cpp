// paint houses - many colours

/*1. You are given a number n and a number k separated by a space, representing the number of houses and number of colors.
2. In the next n rows, you are given k space separated numbers representing the cost of painting nth house with one of the k colors.
3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.

Input Format
A number n
n1-0th n1-1st n1-2nd .. n1-kth
n2-0th n2-1st n2-2nd .. n2-kth
.. n number of elements

Output Format
A number representing the minimum cost of painting all houses without painting any consecutive house with same color.

Constraints
1 <= n <= 1000
1 <= k <= 10
0 <= n1-0th, n1-1st, .. <= 1000

Sample Input
4 3
1 5 7
5 8 4
3 2 9
1 2 4

Sample Output
8
*/

#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> houses){

	int n = houses.size();
	int k = houses[0].size();

	vector<vector<int>> dp(n, vector<int> (k, 0));

	int omin = INT_MAX;
	int osmin = INT_MAX;

	for(int i=0; i<houses.size(); i++){

		int cmin = INT_MAX;
		int csmin = INT_MAX;

		for(int j=0; j<houses[0].size(); j++){

			// if it is a 0th house
			if(i==0){
				dp[i][j] = houses[i][j];
			}
			else{

				if(dp[i-1][j] != omin){
					dp[i][j] = houses[i][j] + omin;
				}
				else{
					dp[i][j] = houses[i][j] + osmin;
				}
			}


			// maintaing our current min and current secondary min
			if(dp[i][j] < cmin){
				csmin = cmin;
				cmin = dp[i][j];
			}
			else if(dp[i][j] < csmin){
				csmin = dp[i][j];
			}
		}

		// updating our oldmin and old secondary min
		omin = cmin;
		osmin = csmin;
	}

	return omin;
}

int main(){

	int n, k;
	cin >> n >> k; // n - houses, k - colours

	vector<vector<int>> houses(n, vector<int>(k, 0));
	for(int i=0; i<houses.size(); i++){
		for(int j=0; j<k; j++){
			cin >> houses[i][j];
		}
	}

	cout << minCost(houses);
	return 0;
}
