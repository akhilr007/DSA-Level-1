// 1. You are given a square matrix of size 'n'. You are given n*n elements of the square matrix. 
// 2. You are required to find the saddle price of the given matrix and print the saddle price. 
// 3. The saddle price is defined as the least price in the row but the maximum price in the column of the matrix.

// Input Format
// A number n
// e11
// e12..
// e21
// e22..
// .. n * n number of elements of array a

// Output Format
// Saddle point of the matrix if available or "Invalid input" if no saddle point is there.

// Constraints
// 1 <= n <= 10^2
// -10^9 <= e11, e12, .. n * m elements <= 10^9

// Sample Input
// 4
// 11
// 12
// 13
// 14
// 21
// 22
// 23
// 24
// 31
// 32
// 33
// 34
// 41
// 42
// 43
// 44

// Sample Output
// 41

#include <iostream>
#include <vector>
using namespace std;

void saddlePrice(vector<vector<int>> arr){

	int n = arr.size();

	for(int i=0; i<n; i++){
		int svj=0;

		//find min in particular row
		for(int j=1; j<n; j++){
			if(arr[i][j] < arr[i][svj]){
				svj = j;
			}
		}

		//we got our column where price is low for that particular row 
		// now check if that price is max in particular column
		bool flag = true;
		for(int k=0; k<n; k++){
			if(arr[k][svj] > arr[i][svj]){
				flag = false;
				break;
			}
		}

		if(flag == true){
			cout << arr[i][svj];
			return;
		}
	}

	cout <<"Invalid input";
}

int main(){

	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}

	saddlePrice(arr);
	return 0;
}