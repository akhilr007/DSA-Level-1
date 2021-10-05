// 1. You are given a number n1, representing the number of rows of 1st matrix.
// 2. You are given a number m1, representing the number of columns of 1st matrix.
// 3. You are given n1*m1 numbers, representing elements of 2d array a1.
// 4. You are given a number n2, representing the number of rows of 2nd matrix.
// 5. You are given a number m2, representing the number of columns of 2nd matrix.
// 6. You are given n2*m2 numbers, representing elements of 2d array a2.
// 7. If the two arrays representing two matrices of dimensions n1 * m1 and n2 * m2 can be multiplied, display the contents of prd array as specified in output Format.

// 8. If the two arrays can't be multiplied, print "Invalid input".
// Input Format
// A number n1
// A number m1
// e11
// e12..
// e21
// e22..
// .. n1 * m1 number of elements of array a1
// A number n2
// A number m2
// e11'
// e12'..
// e21'
// e22'..
// .. n2 * m2 number of elements of array a2

// Output Format
// e11' e12' e13' ..
// e21' e22' e23' ..
// .. elements of prd array

// Constraints
// 1 <= n1 <= 10^2
// 1 <= m1 <= 10^2
// -10^9 <= e11, e12, .. n1 * m1 elements <= 10^9
// 1 <= n2 <= 10^2
// 1 <= m2 <= 10^2
// -10^9 <= e11', e12', .. n2 * m2 elements <= 10^9

// Sample Input
// 2
// 3
// 10
// 0
// 0
// 0
// 20
// 0
// 3
// 4
// 1
// 0
// 1
// 0
// 0
// 1
// 1
// 2
// 1
// 1
// 0
// 0

// Sample Output
// 10 0 10 0
// 0 20 20 40

#include <iostream>
using namespace std;

void matrixMultiplication(int a[][1001], int n1, int m1, int b[][1001], int n2, int m2){

	// matrix multiplication is possible exists if m1 == n2
	// our resultant array size will be res[n1][m2]

	int res[1001][1001];

	for(int i=0; i<n1; i++){
		for(int j=0; j<m2; j++){
			for(int k=0; k<n2; k++){
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	// display our resultant array
	for(int i=0; i<n1; i++){
		for(int j=0; j<m2; j++){
			cout << res[i][j] <<" ";
		}
		cout << endl;
	}
}

int main(){

	int n1, m1;  // array 1 n1 - rows m1 - columns
	cin >> n1 >> m1;

	int a[1001][1001];
	for(int i=0; i<n1; i++){
		for(int j=0; j<m1; j++){
			cin >> a[i][j];
		}
	}

	int n2, m2;
	cin >> n2 >> m2;

	int b[1001][1001];
	for(int i=0; i<n2; i++){
		for(int j=0; j<m2; j++){
			cin >> b[i][j];
		}
	}

	if(m1 != n2){
		cout <<"Invalid input";
	}
	else{
		matrixMultiplication(a, n1, m1, b, n2, m2);
	}
	
	return 0;
}