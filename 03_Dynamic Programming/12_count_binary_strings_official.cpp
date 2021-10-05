// count binary strings
/*
1. You are given a number n.
2. You are required to print the number of binary strings of length n with no consecutive 0's.

Input Format
A number n

Output Format
A number representing the number of binary strings of length n with no consecutive 0's.

Constraints
0 < n <= 45

Sample Input
6

Sample Output
21
*/

#include <bits/stdc++.h>
using namespace std;

int cbs(int n, char type){

	// base case -> if length of n = 1 then the max binary string it can return will be 1
	if(n == 1){
		return 1;
	}

	// then divide the problem in two parts
	// if type is 'a'
	int ans = 0;
	if(type == 'a'){

		// then to get n length binary substring without consecutive 0's we have
		// to select binary strings that previously ended with 1 as it violates the
		// condition of no consecutive 0's if we take string that end with 0

		// na -> n length binary substring that end with 0 without consecutive 0's
		ans = cbs(n-1, 'b');
	}
	else{

		// n length binary substrings that end with 1 without consecutive 0's
		// we can take both previously strings that ended with 0 and 1 a
		ans = cbs(n-1, 'a') + cbs(n-1, 'b');
	}

	return ans;
}

// tabulation
int cbs_tab(int n){

	int ocz = 1; // old count zero that is 1 length binary string ending with 0
	int oco = 1; // old count one that is 1 length binary string ending with 1

	for(int i=2; i<=n; i++){

		// for ncz, we exclude the string ending with 0 as it violates two consecutive zero condition
		int ncz = oco; // new count zero
		// for nco, we include both the string ending with 0 and 1.
		int nco = ocz + oco; // new count one

		// reinitialise the old values of zeros and ones
		ocz = ncz;
		oco = nco;
	}

	return ocz + oco; // add both the values and return
}

int main(){

	int n;
	cin >> n;

	// divide the problems into two parts
	// 1. count the binary strings that end with 0
	// 2. count the binary strings that end with 1

	// a -> it means binary strings that end with 0
	// b -> it means binary strings that end with 1

	// recursion
	int ans = cbs(n, 'a') + cbs(n, 'b');
	cout << ans ;

	// tabulation
	// inclusion exclusion type 
	cout << cbs_tab(n);

	return 0;
}