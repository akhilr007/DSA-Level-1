// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers (1's and 0's), representing elements of 2d array a.
// 4. Consider this array a maze and a player enters from top-left corner in east direction.
// 5. The player moves in the same direction as long as he meets '0'. On seeing a 1, he takes a 90 deg right turn.
// 6. You are required to print the indices in (row, col) format of the point from where you exit the matrix.

// Input Format
// A number n
// A number m
// e11
// e12..
// e21
// e22..
// .. n * m number of elements

// Output Format
// row
// col (of the point of exit)

// Constraints
// 1 <= n <= 10^2
// 1 <= m <= 10^2
// e1, e2, .. n * m elements belongs to the set (0, 1)

// Sample Input
// 4
// 4
// 0
// 0
// 1
// 0
// 1
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 1
// 0
// 1
// 0

// Sample Output
// 1
// 3

#include <iostream>
#include <vector>
using namespace std;

void exitPoint(vector<vector<int>> arr){

	int n = arr.size();
	int m = arr[0].size();

	//our starting point
	int i=0, j=0;
	int dir = 0;// currently going east

	// after encountering 1 it turns 90 degree
	// so east(0)-->south(1)-->west(2)-->north(3)-->east(4)

	while(true){

		dir = (dir + arr[i][j])%4;

		if(dir == 0){
			// going east,i.e, columns
			j++;
			if(j==m){
				j--;
				break;
			}

		}
		else if(dir == 1){
			//going south
			i++;
			if(i==n){
				i--;
				break;
			}
		}
		else if(dir == 2){
			//going west
			j--;
			if(j < 0){
				j++;
				break;
			}
		}
		else if(dir == 3){
			//going north
			i--;
			if(i <0){
				i++;
				break;
			}
		}
	}

	//exit point of matrix is
	cout << i << endl;
	cout << j << endl;
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

	exitPoint(arr);
	return 0;
}