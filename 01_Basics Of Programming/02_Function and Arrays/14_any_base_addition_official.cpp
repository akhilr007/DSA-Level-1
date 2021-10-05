//  You are given a base b.
// 2. You are given two numbers n1 and n2 of base b.
// 3. You are required to add the two numbes and print their value in base b.

// Input Format
// A base b
// A number n1
// A number n2

// Output Format
// A number representing the sum of n1 and n2 in base b.

// Constraints
// 2 <= b <= 10
// 0 <= n1 <= 256
// 0 <= n2 <= 256

// Sample Input
// 8
// 777
// 1

// Sample Output
// 1000

#include <iostream>
#include <math.h>
using namespace std;

int getSum(int b, int n1, int n2){

	int res = 0;
	int power = 0;
	int carry = 0;

	while(n1>0 || n2>0 || carry>0){

		int r1 = n1 % 10;
		int r2 = n2 % 10;

		int val = r1 + r2 + carry;

		int rem = val % b;
		int quo = val / b;

		carry = quo;
		res += rem * pow(10, power);
		power++;

		n1 = n1/10;
		n2 = n2/10;
	}
	return res;
}

int main(){

	int b, n1, n2;
	cin >> b >> n1 >> n2;

	int ans = getSum(b, n1, n2);
	cout << ans << endl;

	return 0;
}