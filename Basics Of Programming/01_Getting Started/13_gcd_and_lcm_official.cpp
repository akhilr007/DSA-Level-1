// 1. You are required to print the Greatest Common Divisor (GCD) of two numbers.
// 2. You are also required to print the Lowest Common Multiple (LCM) of the same numbers.
// 3. Take input "num1" and "num2" as the two numbers.
// 4. Print their GCD and LCM.

// Input Format
// num1
// num2
// .. the numbers whose GCD and LCM we have to find.

// Output Format
// a
// b
// .. where 'a' and 'b' are the GCD and LCM respectively.

// Constraints
// 2 <= n <= 10^9

// Sample Input
// 36
// 24

// Sample Output
// 12
// 72

#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(b > a){
		return gcd(b, a);
	}

	if(b == 0){
		return a;
	}

	return gcd(b, a%b);
}

int main(){
	
	int a;
	int b;

	cin >> a >> b;

	int gcd_ = gcd(a, b);
	// a * b = gcd * lcm

	int lcm = (a*b)/gcd_;
	cout << gcd_ <<endl;
	cout << lcm << endl;

	return 0;

}