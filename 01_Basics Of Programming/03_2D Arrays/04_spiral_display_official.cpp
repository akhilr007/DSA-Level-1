// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a.
// 4. You are required to traverse and print the contents of the 2d array in form of a spiral.
// Note - Please check the sample output for details.

// Input Format
// A number n
// A number m
// e11
// e12..
// e21
// e22..
// .. n * m number of elements

// Output Format
// e11
// e21
// ..
// en1
// en2
// en3
// ..
// enm
// e(n-1)m
// ..
// e1m
// e1(m-1)
// ..
// e12
// e22
// e32
// ..

// Constraints
// 1 <= n <= 10^2
// 1 <= m <= 10^2
// -10^9 <= e1, e2, .. n * m elements <= 10^9

// Sample Input
// 3
// 5
// 11
// 12
// 13
// 14
// 15
// 21
// 22
// 23
// 24
// 25
// 31
// 32
// 33
// 34
// 35

// Sample Output
// 11
// 21
// 31
// 32
// 33
// 34
// 35
// 25
// 15
// 14
// 13
// 12
// 22
// 23
// 24

#include <iostream>
#include <vector>
using namespace std;

void spiralDisplay(vector<vector<int>> arr){

	int n = arr.size();
	int m = arr[0].size();

	int rs = 0;
	int cs = 0;
	int re = n-1;
	int ce = m-1;

	int psf = 0; // printed so far
	int tne = n*m; // total no of elements in an array

	while(psf < tne){

		//left wall
		for(int r=rs; r<=re && psf<tne; r++){
			cout << arr[r][cs] <<endl;
			psf++;
		}
		cs++;

		//bottom wall
		for(int c=cs; c<=ce && psf<tne; c++){
			cout << arr[re][c] <<endl;
			psf++;
		}
		re--;

		//right wall
		for(int r=re; r>=rs && psf<tne; r--){
			cout << arr[r][ce] <<endl;
			psf++;
		}
		ce--;

		//top wall
		for(int c=ce; c>=cs && psf<tne; c--){
			cout << arr[rs][c] << endl;
			psf++;
		}
		rs++;
	}
}

int main(){

	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int> (m, 0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}

	spiralDisplay(arr);
	return 0;
}