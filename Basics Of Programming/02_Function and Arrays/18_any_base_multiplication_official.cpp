// 1. You are given a base b.
// 2. You are given two numbers n1 and n2 of base b.
// 3. You are required to multiply n1 and n2 and print the value.

// Input Format
// A base b
// A number n1
// A number n2

// Output Format
// A number of base b equal in value to n2 * n1.

// Constraints
// 2 <= b <= 10
// 0 <= n1 <= 10000
// 0 <= n2 <= 10000

// Sample Input
// 5
// 1220
// 31

// Sample Output
// 43320

#include <iostream>
using namespace std;

// step 1 : get product with single digit 
int gpwsd(int b, int n1, int d2){

	int ans = 0;
	int carry = 0;
	int power = 1;

	while(n1 > 0 || carry > 0){

		int d1 = n1 % 10; // extract last digit
		n1 = n1 / 10;   // reduce n1 

		int val = d1 * d2 + carry; // multiply two digits and add carry if any

		int q = val / b;  // calculate quotient
		int r = val % b;  // calculate remainder

		carry = q;
		ans = ans + r * power;  // add to ans
		power = power * 10;
	}

	return ans;
}

int getSum(int b, int n1, int n2){

	int carry = 0;
	int ans = 0;
	int power = 1;

	while(n1 > 0 || n2 > 0 || carry > 0){

		int r1 = n1 % 10;
		int r2 = n2 % 10;

		int val = r1 + r2 + carry;

		int q = val / b;
		int r = val % b;

		carry = q;
		ans = ans + r * power;
		power = power * 10;

		n1 = n1/10;
		n2 = n2/10;
	}

	return ans;
}

int getProduct(int b, int n1, int n2){

	int ans = 0;
	int power = 1;

	while(n2 > 0){

		int ld = n2 % 10;
		n2 = n2/10;

		int pwsd = gpwsd(b, n1, ld); // calculate product with single digit
		pwsd = pwsd * power;         // for each digit, the product will be multiplied with 10^0, 10^1, 10^2..

		ans = getSum(b, ans, pwsd);

		power = power * 10;
	}

	return ans;
}

int main(){

	int b, n1, n2;
	cin >> b >> n1 >> n2;

	int res = getProduct(b, n1, n2);
	cout << res << endl;

	return 0;
}