// 1. You are given a number n, representing the number of rows and number of columns.
// 2. You are given n*n numbers, representing elements of 2d array a.
// 3. You are required to rotate the matrix by 90 degree clockwise and then display the contents using display function.
// *Note - you are required to do it in-place i.e. no extra space should be used to achieve it .*

// Input Format
// A number n
// e11
// e12..
// e21
// e22..
// .. n * n number of elements

// Output Format
// output is taken care of by display function

// Constraints
// 1 <= n <= 10^2
// -10^9 <= e1, e2, .. n * n elements <= 10^9

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
// 41 31 21 11
// 42 32 22 12
// 43 33 23 13
// 44 34 24 14

#include <iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int>> &arr){

	for(int i=0; i<arr.size(); i++){
		for(int j=i+1; j<arr.size(); j++){
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
}

void reverse(vector<vector<int>> &arr){

	int l=0;
	int r = arr.size()-1;

	while(l < r){

		for(int i=0; i<arr.size(); i++){
			int temp = arr[i][l];
			arr[i][l] = arr[i][r];
			arr[i][r] = temp;
		}

		l++;
		r--;
	}
}

void display(vector<vector<int>> &arr){

	for(int i=0; i<arr.size(); i++){
		for(int j=0; j<arr.size(); j++){
			cout << arr[i][j] <<" ";
		}
		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int> (n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}

	// step 1 transpose the matrix
	transpose(arr);
	// step 2 reverse the columns
	reverse(arr);
	// step 3 display
	display(arr);
	return 0;
}