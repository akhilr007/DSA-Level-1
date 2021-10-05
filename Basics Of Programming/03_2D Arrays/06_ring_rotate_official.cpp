// You are given a n*m matrix where n are the number of rows and m are the number of columns. You are also given n*m numbers representing the elements of the matrix.
// You will be given a ring number 's' representing the ring of the matrix. For details, refer to image.

// shell-rotate

// You will be given a number 'r' representing number of rotations in an anti-clockwise manner of the specified ring.
// You are required to rotate the 's'th ring by 'r' rotations and display the rotated matrix.

// Input Format
// A number n
// A number m
// e11
// e12..
// e21
// e22..
// .. n * m number of elements of array a
// A number s
// A number r

// Output Format
// output is handled by display function

// Constraints
// 1 <= n <= 10^2
// 1 <= m <= 10^2
// -10^9 <= e11, e12, .. n * m elements <= 10^9
// 0 < s <= min(n, m) / 2
// -10^9 <= r <= 10^9

// Sample Input
// 5
// 7
// 11
// 12
// 13
// 14
// 15
// 16
// 17
// 21
// 22
// 23
// 24
// 25
// 26
// 27
// 31
// 32
// 33
// 34
// 35
// 36
// 37
// 41
// 42
// 43
// 44
// 45
// 46
// 47
// 51
// 52
// 53
// 54
// 55
// 56
// 57
// 2
// 3

// Sample Output
// 11 12 13 14 15 16 17
// 21 25 26 36 46 45 27
// 31 24 33 34 35 44 37
// 41 23 22 32 42 43 47
// 51 52 53 54 55 56 57

#include <iostream>
#include <vector>
using namespace std;

// fill 1d array
vector<int> fill1dArray(vector<vector<int>> &mat, int s){

	int n = mat.size();
	int m = mat[0].size();

	// rs = row start, cs = col start, re = row end, ce = col end
	int rs = s-1;
	int cs = s-1;
	int re = n-s;
	int ce = m-s;

	// tne = total no of elements
	int tne = 2*(re-rs+1)+2*(ce-cs+1)-4;

	vector<int> a(tne);
	int idx = 0;

	//left wall
	for(int r=rs; r<=re; r++){
		a[idx] = mat[r][cs];
		idx++;
	}
	cs++;

	//bottom wall
	for(int c=cs; c<=ce; c++){
		a[idx] = mat[re][c];
		idx++;
	}
	re--;

	//right wall
	for(int r=re; r>=rs; r--){
		a[idx] = mat[r][ce];
		idx++;
	}
	ce--;

	//top wall
	for(int c=ce; c>=cs; c--){
		a[idx] = mat[rs][c];
		idx++;
	}
	rs++;

	return a;

}

void reverse(vector<int> &arr, int lo, int hi){

	while(lo < hi){

		int temp = arr[lo];
		arr[lo] = arr[hi];
		arr[hi] = temp;

		lo++;
		hi--;
	}
}

// rotate 1d array
void rotate(vector<int> &arr, int r){

	r = r % arr.size();

	if(r<0){
		r = r + arr.size();
	}

	reverse(arr, 0, arr.size()-r-1); // reverse left part
	reverse(arr, arr.size()-r, arr.size()-1); // reverse right part
	reverse(arr, 0, arr.size()-1); //reverse whole arry;
}

void fill2dArray(vector<vector<int>> &mat, vector<int> &arr, int s){

	int n = mat.size();
	int m = mat[0].size();

	// rs = row start, cs = col start, re = row end, ce = col end
	int rs = s-1;
	int cs = s-1;
	int re = n-s;
	int ce = m-s;

	int idx = 0;

	//left wall
	for(int r=rs; r<=re; r++){
		mat[r][cs] = arr[idx];
		idx++;
	}
	cs++;

	//bottom wall
	for(int c=cs; c<=ce; c++){
		mat[re][c] = arr[idx];
		idx++;
	}
	re--;

	//right wall
	for(int r=re; r>=rs; r--){
		mat[r][ce] = arr[idx];
		idx++;
	}
	ce--;

	//top wall
	for(int c=ce; c>=cs; c--){
		mat[rs][c] = arr[idx];
		idx++;
	}
	rs++;
}

void display(vector<vector<int>> &mat) {

	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[0].size(); j++){
			cout << mat[i][j] <<" ";
		}
		cout << endl;
	}
}

void ringRotate(vector<vector<int>> &mat, int s, int r){

	// step 1 fill 1d array from 2d matrix for s shell
	vector<int> arr = fill1dArray(mat, s);

	// rotate 1d array
	rotate(arr, r);

	//fill 2d array from 1d matrix
	fill2dArray(mat, arr, s);

	display(mat);
}

int main(){

	int n, m;
	cin >> n >> m;

	vector<vector<int>> mat(n, vector<int> (m, 0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}

	int s, r;
	cin >> s >> r;

	ringRotate(mat, s, r);
	return 0;
}