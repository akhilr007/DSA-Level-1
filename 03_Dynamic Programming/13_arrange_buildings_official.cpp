// arrange buildings

/*
1. You are given a number n, which represents the length of a road. The road has n plots on it's each side.
2. The road is to be so planned that there should not be consecutive buildings on either side of the road.
3. You are required to find and print the number of ways in which the buildings can be built on both side of roads.

Input Format
A number n

Output Format
A number representing the number of ways in which the buildings can be built on both side of roads.

Constraints
0 < n <= 45

Sample Input
6

Sample Output
441

*/

#include <bits/stdc++.h>
using namespace std;

int arrangeBuilding(int n, char type){

	if(n == 1){
		return 1;
	}

	// if type is 'b' then we can only select 's' as if we also select 'b' then
	// we will end up with two consecutive buildings in a single plot
	int ans = 0;
	if(type == 'b'){
		ans = arrangeBuilding(n-1, 's');
	}
	else{
		ans = arrangeBuilding(n-1, 'b') + arrangeBuilding(n-1, 's');
	}

	return ans; // since we have to do similarly in another plot multiply it with itself
}

int arrangeBuilding_tab(int n){

	int ocb = 1; // old count building
	int ocs = 1; // old count space

	for(int i=2; i<=n; i++){

		int ncb = ocs;
		int ncs = ocb + ocs;

		ocb = ncb;
		ocs = ncs;
	}

	return ocb + ocs;
}

int main() {

	int n;
	cin >> n;

	// recursion
	// divide the question into two parts
	// 1. n plots that end with building that is 'b'
	// 2. n plots that end with spaces that is 's'
	int ans = arrangeBuilding(n, 'b') + arrangeBuilding(n, 's');
	cout << (long)ans*ans;

	// tabulation
	int ans = arrangeBuilding_tab(n);
	cout << (long) ans * ans;

	return 0;
}
