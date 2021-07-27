// 1. You are given a number n.
// 2. You are given a base b1. n is a number on base b.
// 3. You are given another base b2.
// 4. You are required to convert the number n of base b1 to a number in base b2.

// Input Format
// A number n
// A base b1
// A base b2

// Output Format
// A number of base b2 equal in value to n of base b1.

// Constraints
// 0 <= n <= 512
// 2 <= b1 <= 10
// 2 <= b2 <= 10
// Sample Input
// 111001
// 2
// 3
// Sample Output
// 2010

#include <iostream>
#include <math.h>
using namespace std;

int getDecimalValue(int n, int b){

	int decimal = 0;
	int power = 0;

	while(n > 0){

		int rem = n % 10;

		decimal += rem * pow(b, power);
		power++;

		n = n/10;
	}

	return decimal;
}

int getBaseValue(int decimal, int b){

	int baseValue = 0;
	int power = 0;

	while(n > 0){

		int rem = decimal % b;

		baseValue += rem * pow(10, power);
		power++;

		n = n/b;
	}

	return baseValue;
}

int main(){

	// n -> number with base b1, b2->number to converted to base b2
	int n, b1, b2;
	cin >> n >> b1 >> b2;

	// convert into decimal then convert decimal into another base;
	int decimal = getDecimalValue(n, b1);
	int ans = getBaseValue(decimal, b2);

	cout << ans << endl;

	return 0;
}