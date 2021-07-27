// 1. You are given a base b.
// 2. You are given two numbers n1 and n2 of base b.
// 3. You are required to subtract n1 from n2 and print the value.

// Input Format
// A base b
// A number n1
// A number n2

// Output Format
// A number of base b equal in value to n2 - n1.

// Constraints
// 2 <= b <= 10
// 0 <= n1 <= 256
// n1 <= n2 <= 256

// Sample Input
// 8
// 1
// 100

// Sample Output
// 77

#include <iostream>
#include <math.h>
using namespace std;

int getDifference(int b, int n1, int n2){

	int res = 0;

	int carry = 0;
	int power = 0;

	while(n2 > 0){

		int r1 = n1 % 10;
		int r2 = n2 % 10;

		int diff = 0;
		r2 = r2 + carry;

		if(r2 >= r1){
			carry = 0;
			diff = r2 - r1;
		}
		else{
			carry = -1;
			diff = r2 + b - r1;
		}

		res += diff * pow(10, power);
		power++;

		n1 = n1/10;
		n2 = n2/10;
	}
	return res;
}

int main(){

	int b, n1, n2;
	cin >> b >> n1 >> n2;

	int ans = getDifference(b, n1, n2);
	cout << ans << endl;

	return 0;
}