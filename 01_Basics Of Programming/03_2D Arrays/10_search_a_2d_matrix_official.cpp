// 1. Write an efficient algorithm that searches for a value in a m x n matrix. This matrix has the following properties:
// a). Integers in each row are sorted from left to right.
// b). The first integer of each row is greater than the last integer of the previous row.

// Input Format
// Input is managed for you

// Output Format
// Output is managed for you

// Constraints
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -10^4 <= matrix[i][j], target <= 10^4

// Sample Input
// 5 4
// 1 3 5 7
// 10 11 16 20
// 23 30 34 60
// 62 63 65 68
// 71 72 74 80
// 65

// Sample Output
// true

#include <iostream>
#include <vector>
using namespace std;

bool searchInAMatrix(vector<vector<int>> arr, int x){

	int lo = 0;
	int hi = n*m-1;

	while(lo<hi){

		int mid = lo + (hi-lo)/2;

		if(arr[mid/m][mid%m] == x){
			return true;
		}
		else if(arr[mid/m][mid%m] > x){
			hi = mid - 1;
		}
		else{
			lo = mid+1;
		}
	}

	return false;
}

int main(){

	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}

	int x;
	cin >> x;

	if(searchInAMatrix(arr, x) == true){
		cout <<"true";
	}else{
		cout <<"false";
	}
	return 0;
}