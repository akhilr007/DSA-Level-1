// 1. You are given a number n.
// 2. You are given a base b. n is a number on base b.
// 3. You are required to convert the number n into its corresponding value in decimal number system.

// Input Format
// A number n
// A base b

// Output Format
// A decimal number representing corresponding value of n in base b.

// Constraints
// 0 <= d <= 1000000000
// 2 <= b <= 10
  
// Sample Input
// 111001
// 2

// Sample Output
// 57

#include <iostream>
#include <math.h>
using namespace std;

int getDecimalValue(int n, int b){

	int decimalValue = 0;
	int power = 0;

	while(n > 0){

		// step 1 : take rem -> n % 10
		int rem = n % 10;

		// step 2 : calculate value by multiplying rem with 2^0, 2^1, 2^2...2^n-1
		decimalValue += rem * pow(b, power);
		power++;

		// step 3 : reduce n by 10
		n = n /10;
	}


	return decimalValue;
}

int main(){

	int n, b;  // n --> number with base b
	cin >> n >> b;

	int ans = getDecimalValue(n, b);
	cout << ans << endl;

	return ans;
}